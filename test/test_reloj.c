// Fijar la hora de la alarma y consultarla.
// Fijar la alarma y avanzar el reloj para que suene.
// Fijar la alarma, deshabilitarla y avanzar el reloj para no suene.
// Hacer sonar la alarma y posponerla.
// Hacer sonar la alarma y cancelarla hasta el otro dia..
// Probar horas invalidas y verificar que las rechaza

#include "unity.h"
#include "reloj.h"

#define TICS 5

// Al inicializar el reloj está en 00:00 y con hora invalida.
void test_inicializa_con_hora_invalida(void)
{
    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6] = {0xFF};

    clock_t reloj = ClockCreate(TICS);

    TEST_ASSERT_FALSE(ClockGetTime(reloj, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Al ajustar la hora el reloj queda en hora y es válida.
void test_ajustar_hora_valida(void)
{
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};
    uint8_t hora[6];

    clock_t reloj = ClockCreate(TICS);
    TEST_ASSERT_TRUE(ClockSetTime(reloj, ESPERADO, 4));

    TEST_ASSERT_TRUE(ClockGetTime(reloj, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 5 ciclos de reloj la hora avanza un segundo
void test_avance_seg_unidad(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 0, 1};
    uint8_t hora[6];
    int ciclos = 5;
    clock_t reloj = ClockCreate(TICS);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockIncrement(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 50 ciclos de reloj la hora avanza diez segundos
void test_avance_seg_decenas(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 1, 0};
    uint8_t hora[6];
    int ciclos = 50;
    clock_t reloj = ClockCreate(TICS);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockIncrement(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de n ciclos de reloj la hora avanza un minuto
void test_avance_min_unidades(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 1, 0, 0};
    uint8_t hora[6];
    int ciclos = 300;
    clock_t reloj = ClockCreate(TICS);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockIncrement(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 3000 ciclos de reloj la hora avanza diez minutos
void test_avance_min_decenas(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 1, 0, 0, 0};
    uint8_t hora[6];
    int ciclos = 3000;
    clock_t reloj = ClockCreate(TICS);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockIncrement(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 18000 ciclos de reloj la hora avanza una hora
void test_avance_horas_unidades(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 1, 0, 0, 0, 0};
    uint8_t hora[6];
    int ciclos = 18000;
    clock_t reloj = ClockCreate(TICS);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockIncrement(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de 180000 ciclos de reloj la hora avanza diez horas
void test_avance_horas_decenas(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {1, 0, 0, 0, 0, 0};
    uint8_t hora[6];
    int ciclos = 180000;
    clock_t reloj = ClockCreate(TICS);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockIncrement(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}

// Después de n ciclos de reloj la hora avanza un día completo.
void test_avance_24_horas(void)
{
    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6];
    int ciclos = 432000;
    clock_t reloj = ClockCreate(TICS);

    ClockSetTime(reloj, INICIO, 6);
    for (int index = 0; index < ciclos; index++)
    {
        ClockIncrement(reloj);
    }
    ClockGetTime(reloj, hora, 6);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, 6);
}