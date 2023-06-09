#include "reloj.h"
#include <stddef.h>
#include <string.h>

#define SEGUNDOS_UNI  hora[5]
#define SEGUNDOS_DEC  hora[4]
#define MINUTOS_UNI   hora[3]
#define MINUTOS_DEC   hora[2]
#define HORAS_UNI     hora[1]
#define HORAS_DEC     hora[0]

#define Compara(a, b) memcmp(reloj->a, reloj->b, sizeof(reloj->a)) == 0

struct clock_s
{
    uint8_t hora_actual[6];
    uint8_t alarma[6];
    uint8_t alarma_nueva[6];
    uint8_t tics_por_segundo;
    uint8_t tics_actual;
    alarma_event_t ActivarAlarma;
    bool hora_valida;
    bool alarma_habilitada;
    bool alarma_pospuesta;
};

void SecondsIncrement(uint8_t * hora);
void AlarmCheck(clock_t reloj);

void SecondsIncrement(uint8_t * hora)
{
    SEGUNDOS_UNI++;

    if (SEGUNDOS_UNI >= 10)
    {
        SEGUNDOS_UNI = 0;
        SEGUNDOS_DEC++;
    }

    if (SEGUNDOS_DEC >= 6)
    {
        SEGUNDOS_DEC = 0;
        MINUTOS_UNI++;
    }

    if (MINUTOS_UNI >= 10)
    {
        MINUTOS_UNI = 0;
        MINUTOS_DEC++;
    }

    if (MINUTOS_DEC >= 6)
    {
        MINUTOS_DEC = 0;
        HORAS_UNI++;
    }

    if (HORAS_UNI >= 10)
    {
        HORAS_UNI = 0;
        HORAS_DEC++;
    }

    if (HORAS_DEC >= 2 && HORAS_UNI >= 4)
    {
        HORAS_DEC = 0;
        HORAS_UNI = 0;
    }
}

void AlarmCheck(clock_t reloj)
{
    if (Compara(hora_actual, alarma) && reloj->alarma_habilitada && !(reloj->alarma_pospuesta))
    {
        reloj->ActivarAlarma(true);
    }

    if (Compara(hora_actual, alarma_nueva) && reloj->alarma_habilitada && reloj->alarma_pospuesta)
    {
        reloj->ActivarAlarma(true);
        reloj->alarma_pospuesta = false;
    }
}

clock_t ClockCreate(int tics_por_segundo, alarma_event_t ActivarAlarma)
{
    static struct clock_s self[1];

    memset(self, 0, sizeof(self));
    self->tics_por_segundo = tics_por_segundo;
    self->ActivarAlarma = ActivarAlarma;
    self->alarma_habilitada = false;
    self->alarma_pospuesta = false;

    return self;
}

void ClockIncrement(clock_t reloj)
{
    reloj->tics_actual++;

    if (reloj->tics_actual >= reloj->tics_por_segundo)
    {
        reloj->tics_actual = 0;
        SecondsIncrement(reloj->hora_actual);
        AlarmCheck(reloj);
    }

    return;
}

bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size)
{
    memcpy(reloj->hora_actual, hora, size);
    reloj->hora_valida = true;

    return true;
}

bool ClockGetTime(clock_t reloj, uint8_t * hora, int size)
{
    memcpy(hora, reloj->hora_actual, size);

    return reloj->hora_valida;
}

void AlarmSetTime(clock_t reloj, const uint8_t * alarma, int size)
{
    memcpy(reloj->alarma, alarma, size);
    AlarmEnamble(reloj, true);

    return;
}

void AlarmGetTime(clock_t reloj, uint8_t * alarma, int size)
{
    memcpy(alarma, reloj->alarma, size);

    return;
}

void AlarmEnamble(clock_t reloj, bool estado)
{
    reloj->alarma_habilitada = estado;

    return;
}

bool AlarmGetState(clock_t reloj)
{
    return reloj->alarma_habilitada;
}

void AlarmPostpone(clock_t reloj, uint8_t minutos)
{
    reloj->alarma_pospuesta = true;
    memcpy(reloj->alarma_nueva, reloj->alarma, sizeof(reloj->alarma_nueva));

    for (int index = 0; index < (minutos * 60); index++)
    {
        SecondsIncrement(reloj->alarma_nueva);
    }

    return;
}

void AlarmCancel(clock_t reloj)
{
    reloj->ActivarAlarma(false);

    return;
}