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



    do {if (!(ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(27)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_ajustar_hora_valida(void)

{

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};

    uint8_t hora[6];



    clock_t reloj = ClockCreate(10, ActivarAlarma);



    do {if ((ClockSetTime(reloj, ESPERADO, 4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(39)));}} while(0);

    do {if ((ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(40)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(149), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_fijar_alarma(void)

{

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};

    uint8_t alarma[6];



    clock_t reloj = ClockCreate(10, ActivarAlarma);

    AlarmSetTime(reloj, ESPERADO, 6);

    AlarmGetTime(reloj, alarma, 6);



    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(180), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        ClockIncrement(reloj);

    }



    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(202), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(203)));}} while(0);

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

        ClockIncrement(reloj);

    }



    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(226), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if (!(AlarmGetState(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(227)));}} while(0);

    do {if (!(alarma_activa)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(228)));}} while(0);

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

    AlarmPostpone(reloj, 1);



    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(250), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if (!(alarma_activa)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(251)));}} while(0);



    for (int index = 0; index < ciclos; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma_nueva)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(259), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(260)));}} while(0);

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

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(281), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(282)));}} while(0);



    AlarmCancel(reloj);



    do {if (!(alarma_activa)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(286)));}} while(0);



    for (int index = 0; index < ciclos_dia; index++)

    {

        ClockIncrement(reloj);

    }

    ClockGetTime(reloj, hora, 6);



    UnityAssertEqualIntArray(( const void*)((alarma)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(294), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((alarma_activa)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(295)));}} while(0);

}
