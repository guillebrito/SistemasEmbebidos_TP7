#include "inc/reloj.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








static 

      _Bool 

           alarma_activa = 

                           0

                                ;



void ActivarAlarma(

                  _Bool 

                       estado);



void ActivarAlarma(

                  _Bool 

                       estado)

{

    alarma_activa = estado;



    return;

}





void test_inicializa_con_hora_invalida(void)

{

    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6] = {0xFF};



    clock_t reloj = ClockCreate(10, ActivarAlarma);



    do {if (!(ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(26)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_ajustar_hora_valida(void)

{

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};

    uint8_t hora[6];



    clock_t reloj = ClockCreate(10, ActivarAlarma);



    do {if ((ClockSetTime(reloj, ESPERADO, 4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(38)));}} while(0);

    do {if ((ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(39)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_seg_unidad(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 0, 1};

    uint8_t hora[6];

    int ciclos = 10;

    clock_t reloj = ClockCreate(10, ActivarAlarma);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_seg_decenas(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 1, 0};

    uint8_t hora[6];

    int ciclos = 10 * 10;

    clock_t reloj = ClockCreate(10, ActivarAlarma);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_min_unidades(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 1, 0, 0};

    uint8_t hora[6];

    int ciclos = 10 * 60;

    clock_t reloj = ClockCreate(10, ActivarAlarma);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_min_decenas(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 1, 0, 0, 0};

    uint8_t hora[6];

    int ciclos = 10 * 600;

    clock_t reloj = ClockCreate(10, ActivarAlarma);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_horas_unidades(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 1, 0, 0, 0, 0};

    uint8_t hora[6];

    int ciclos = 10 * 3600;

    clock_t reloj = ClockCreate(10, ActivarAlarma);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_horas_decenas(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {1, 0, 0, 0, 0, 0};

    uint8_t hora[6];

    int ciclos = 10 * 36000;

    clock_t reloj = ClockCreate(10, ActivarAlarma);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(148), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_24_horas(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6];

    int ciclos = 10 * 86400;

    clock_t reloj = ClockCreate(10, ActivarAlarma);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(166), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_fijar_alarma(void)

{

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};

    uint8_t alarma[6];



    clock_t reloj = ClockCreate(10, ActivarAlarma);



    do {if ((AlarmSetTime(reloj, ESPERADO, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(177)));}} while(0);

    do {if ((AlarmGetTime(reloj, alarma, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(178)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(179), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_sonar_alarma(void)

{

    static const uint8_t INICIO[] = {1, 2, 3, 4, 0, 0};

    uint8_t alarma[] = {1, 2, 3, 5, 0, 0}, hora[6];

    int ciclos = 10 * 60;

    alarma_activa = 

                   0

                        ;



    clock_t reloj = ClockCreate(10, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);

    AlarmSetTime(reloj, alarma, 6);



    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }



    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(201), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(202)));}} while(0);

}





void test_deshabilitar_alarma(void)

{

    static const uint8_t INICIO[] = {1, 2, 3, 4, 0, 0};

    uint8_t alarma[] = {1, 2, 3, 5, 0, 0}, hora[6];

    int ciclos = 10 * 60;

    alarma_activa = 

                   0

                        ;



    clock_t reloj = ClockCreate(10, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);

    AlarmSetTime(reloj, alarma, 6);

    AlarmEnamble(reloj, 

                       0

                            );



    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }



    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(225), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if (!(AlarmGetState(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(226)));}} while(0);

    do {if (!(alarma_activa)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(227)));}} while(0);

}





void test_posponer_alarma(void)

{

    static const uint8_t INICIO[] = {1, 2, 3, 4, 0, 0};

    uint8_t alarma[] = {1, 2, 3, 5, 0, 0}, alarma_nueva[] = {1, 2, 3, 6, 0, 0}, hora[6];

    int ciclos = 10 * 60;

    alarma_activa = 

                   0

                        ;



    clock_t reloj = ClockCreate(10, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);

    AlarmSetTime(reloj, alarma, 6);



    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(248), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(249)));}} while(0);



    AlarmPostpone(reloj, 1);

    do {if (!(alarma_activa)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(252)));}} while(0);



    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma_nueva)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(260), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(261)));}} while(0);

}





void test_cancelar_alarma_24_hs(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0};

    uint8_t alarma[] = {0, 0, 0, 1, 0, 0}, hora[6];

    int ciclos_minuto = 10 * 60, ciclos_dia = 10 * 86400;

    alarma_activa = 

                   0

                        ;



    clock_t reloj = ClockCreate(10, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);

    AlarmSetTime(reloj, alarma, 6);



    for (int index = 0; index < ciclos_minuto; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(282), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(283)));}} while(0);



    AlarmCancel(reloj);



    do {if (!(alarma_activa)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(287)));}} while(0);



    for (int index = 0; index < ciclos_dia; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(295), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(296)));}} while(0);

}





void test_probar_horas_invalidas(void)

{

    static const uint8_t ESPERADO[] = {2, 4, 0, 0, 0, 0};

    uint8_t hora[6];



    clock_t reloj = ClockCreate(10, ActivarAlarma);



    do {if (!(ClockSetTime(reloj, ESPERADO, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(307)));}} while(0);

    do {if (!(ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(308)));}} while(0);

    if (memcmp(ESPERADO, hora, sizeof(ESPERADO)) == 0)

        UnityFail( (("No rechaza hora invalida")), (UNITY_UINT)(310));

}





void test_probar_alarmas_invalidas(void)

{

    static const uint8_t ESPERADO[] = {2, 4, 0, 0, 0, 0}, INICIO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6];



    clock_t reloj = ClockCreate(10, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);



    do {if (!(AlarmSetTime(reloj, ESPERADO, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(322)));}} while(0);

    do {if (!(AlarmGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(323)));}} while(0);

    if (memcmp(ESPERADO, hora, sizeof(ESPERADO)) == 0)

        UnityFail( (("No rechaza hora invalida")), (UNITY_UINT)(325));

}





void test_posponer_alarma_dos_veces(void)

{

    static const uint8_t INICIO[] = {1, 2, 3, 4, 0, 0};

    uint8_t alarma[] = {1, 2, 3, 5, 0, 0}, alarma_nueva[] = {1, 2, 3, 7, 0, 0}, hora[6];

    int ciclos = 10 * 60;

    alarma_activa = 

                   0

                        ;



    clock_t reloj = ClockCreate(10, ActivarAlarma);

    ClockSetTime(reloj, INICIO, 6);

    AlarmSetTime(reloj, alarma, 6);



    for (int index = 0; index < ciclos; index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(346), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(347)));}} while(0);



    AlarmPostpone(reloj, 1);

    AlarmPostpone(reloj, 1);



    do {if (!(alarma_activa)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(352)));}} while(0);



    for (int index = 0; index < (2 * ciclos); index++)

    {

        ClockRefresh(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma_nueva)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(360), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(361)));}} while(0);

}
