#include "inc/reloj.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






















void test_inicializa_con_hora_invalida(void)

{

    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6] = {0xFF};



    clock_t reloj = ClockCreate(5);



    do {if (!(ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(21)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_ajustar_hora_valida(void)

{

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};

    uint8_t hora[6];



    clock_t reloj = ClockCreate(5);

    do {if ((ClockSetTime(reloj, ESPERADO, 4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(32)));}} while(0);



    do {if ((ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(34)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_seg_unidad(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 0, 1};

    uint8_t hora[6];

    int ciclos = 5;

    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_seg_decenas(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 1, 0};

    uint8_t hora[6];

    int ciclos = 50;

    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_min_unidades(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 1, 0, 0};

    uint8_t hora[6];

    int ciclos = 300;

    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_min_decenas(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 1, 0, 0, 0};

    uint8_t hora[6];

    int ciclos = 3000;

    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_horas_unidades(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 1, 0, 0, 0, 0};

    uint8_t hora[6];

    int ciclos = 18000;

    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(125), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_horas_decenas(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {1, 0, 0, 0, 0, 0};

    uint8_t hora[6];

    int ciclos = 180000;

    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_avance_24_horas(void)

{

    static const uint8_t INICIO[] = {0, 0, 0, 0, 0, 0}, ESPERADO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6];

    int ciclos = 432000;

    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj, INICIO, 6);

    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(161), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
