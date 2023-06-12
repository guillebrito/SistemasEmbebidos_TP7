#include "unity.h"
#include "reloj.h"
#include "string.h"

#define TICS 10

static bool alarma_activa = false;

void ActivarAlarma(bool estado);

void ActivarAlarma(bool estado)
{
    alarma_activa = estado;

    return;
}

// Al inicializar el reloj está en 00:00 y con hora invalida.
void test_inicializa_con_hora_invalida(void)
{
    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6] = {0xFF};

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    TEST_ASSERT_FALSE(ClockGetTime(reloj, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Al ajustar la hora el reloj queda en hora y es válida.
void test_ajustar_hora_valida(void)
{
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    TEST_ASSERT_TRUE(ClockSetTime(reloj, ESPERADO, 4));
    TEST_ASSERT_TRUE(ClockGetTime(reloj, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 5 ciclos de reloj la hora avanza un segundo
void test_avance_seg_unidad(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 0, 1};
    uint8_t hora[6];
    int ciclos = TICS;
    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 50 ciclos de reloj la hora avanza diez segundos
void test_avance_seg_decenas(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 1, 0};
    uint8_t hora[6];
    int ciclos = TICS * 10;
    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de n ciclos de reloj la hora avanza un minuto
void test_avance_min_unidades(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 1, 0, 0};
    uint8_t hora[6];
    int ciclos = TICS * 60;
    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 3000 ciclos de reloj la hora avanza diez minutos
void test_avance_min_decenas(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 1, 0, 0, 0};
    uint8_t hora[6];
    int ciclos = TICS * 600;
    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 18000 ciclos de reloj la hora avanza una hora
void test_avance_horas_unidades(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 1, 0, 0, 0, 0};
    uint8_t hora[6];
    int ciclos = TICS * 3600;
    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 180000 ciclos de reloj la hora avanza diez horas
void test_avance_horas_decenas(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {1, 0, 0, 0, 0, 0};
    uint8_t hora[6];
    int ciclos = TICS * 36000;
    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de n ciclos de reloj la hora avanza un día completo.
void test_avance_24_horas(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6];
    int ciclos = TICS * 86400;
    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Fijar la hora de la alarma y consultarla.
void test_fijar_alarma(void)
{
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};
    uint8_t alarma[6];

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    TEST_ASSERT_TRUE(AlarmSetTime(reloj, ESPERADO, 6));
    TEST_ASSERT_TRUE(AlarmGetTime(reloj, alarma, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, alarma, 6);
}

// Fijar la alarma y avanzar el reloj para que suene.
void test_sonar_alarma(void)
{
    static const uint8_t INICIO[] = {1, 2, 3, 4, 0, 0};
    uint8_t alarma[] = {1, 2, 3, 5, 0, 0}, hora[6];
    int ciclos = TICS * 60;
    alarma_activa = false;

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);
    ClockSetTime(reloj, INICIO, 6);
    AlarmSetTime(reloj, alarma, 6);

    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }

    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma, hora, 6);
    TEST_ASSERT_TRUE(alarma_activa);
}

// Fijar la alarma, deshabilitarla y avanzar el reloj para no suene.
void test_deshabilitar_alarma(void)
{
    static const uint8_t INICIO[] = {1, 2, 3, 4, 0, 0};
    uint8_t alarma[] = {1, 2, 3, 5, 0, 0}, hora[6];
    int ciclos = TICS * 60;
    alarma_activa = false;

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);
    ClockSetTime(reloj, INICIO, 6);
    AlarmSetTime(reloj, alarma, 6);
    AlarmEnamble(reloj, false);

    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }

    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma, hora, 6);
    TEST_ASSERT_FALSE(AlarmGetState(reloj));
    TEST_ASSERT_FALSE(alarma_activa);
}

// Hacer sonar la alarma y posponerla.
void test_posponer_alarma(void)
{
    static const uint8_t INICIO[] = {1, 2, 3, 4, 0, 0};
    uint8_t alarma[] = {1, 2, 3, 5, 0, 0}, alarma_nueva[] = {1, 2, 3, 6, 0, 0}, hora[6];
    int ciclos = TICS * 60;
    alarma_activa = false;

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);
    ClockSetTime(reloj, INICIO, 6);
    AlarmSetTime(reloj, alarma, 6);

    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma, hora, 6);
    TEST_ASSERT_TRUE(alarma_activa);

    AlarmPostpone(reloj, 1);
    TEST_ASSERT_FALSE(alarma_activa); // pruebo que dejo de sonar la alarma

    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma_nueva, hora, 6);
    TEST_ASSERT_TRUE(alarma_activa);
}

// Hacer sonar la alarma y cancelarla hasta el otro dia..
void test_cancelar_alarma_24_hs(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0};
    uint8_t alarma[] = {0, 0, 0, 1, 0, 0}, hora[6];
    int ciclos_minuto = TICS * 60, ciclos_dia = TICS * 86400;
    alarma_activa = false;

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);
    ClockSetTime(reloj, INICIO, 6);
    AlarmSetTime(reloj, alarma, 6);

    for (int index = 0; index < ciclos_minuto; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma, hora, 6);
    TEST_ASSERT_TRUE(alarma_activa);

    AlarmCancel(reloj);

    TEST_ASSERT_FALSE(alarma_activa);

    for (int index = 0; index < ciclos_dia; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma, hora, 6);
    TEST_ASSERT_TRUE(alarma_activa);
}

// Probar horas invalidas y verificar que las rechaza
void test_probar_horas_invalidas(void)
{
    static const uint8_t ESPERADO[] = {2, 4, 0, 0, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);

    TEST_ASSERT_FALSE(ClockSetTime(reloj, ESPERADO, 6));
    TEST_ASSERT_FALSE(ClockGetTime(reloj, hora, 6));
    if (memcmp(ESPERADO, hora, sizeof(ESPERADO)) == 0)
        TEST_FAIL_MESSAGE("No rechaza hora invalida");
}

// Probar alarmas invalidas y verificar que las rechaza
void test_probar_alarmas_invalidas(void)
{
    static const uint8_t ESPERADO[] = {2, 4, 0, 0, 0, 0}, INICIO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);
    ClockSetTime(reloj, INICIO, 6);

    TEST_ASSERT_FALSE(AlarmSetTime(reloj, ESPERADO, 6));
    TEST_ASSERT_FALSE(AlarmGetTime(reloj, hora, 6));
    if (memcmp(ESPERADO, hora, sizeof(ESPERADO)) == 0)
        TEST_FAIL_MESSAGE("No rechaza hora invalida");
}

// Probar posponer mas de una vez
void test_posponer_alarma_dos_veces(void)
{
    static const uint8_t INICIO[] = {1, 2, 3, 4, 0, 0};
    uint8_t alarma[] = {1, 2, 3, 5, 0, 0}, alarma_nueva[] = {1, 2, 3, 7, 0, 0}, hora[6];
    int ciclos = TICS * 60;
    alarma_activa = false;

    clock_t reloj = ClockCreate(TICS, ActivarAlarma);
    ClockSetTime(reloj, INICIO, 6);
    AlarmSetTime(reloj, alarma, 6);

    for (int index = 0; index < ciclos; index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma, hora, 6);
    TEST_ASSERT_TRUE(alarma_activa);

    AlarmPostpone(reloj, 1);
    AlarmPostpone(reloj, 1);

    TEST_ASSERT_FALSE(alarma_activa); // pruebo que dejo de sonar la alarma

    for (int index = 0; index < (2 * ciclos); index++)
    {
        ClockRefresh(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(alarma_nueva, hora, 6);
    TEST_ASSERT_TRUE(alarma_activa);
}
// mostrar nueva alama al posponer