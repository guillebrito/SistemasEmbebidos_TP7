#include "reloj.h"
#include <stddef.h>
#include <string.h>

#define SEGUNDOS_UNI reloj->hora_actual[5]
#define SEGUNDOS_DEC reloj->hora_actual[4]
#define MINUTOS_UNI  reloj->hora_actual[3]
#define MINUTOS_DEC  reloj->hora_actual[2]
#define HORAS_UNI    reloj->hora_actual[1]
#define HORAS_DEC    reloj->hora_actual[0]

struct clock_s
{
    uint8_t hora_actual[6];
    uint8_t tics;
    uint8_t tics_actual;
    bool valida;
};

void SecondsIncrement(clock_t reloj);

void SecondsIncrement(clock_t reloj)
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

clock_t ClockCreate(int tics_por_segundo)
{
    static struct clock_s self[1];

    memset(self, 0, sizeof(self));
    self->tics = tics_por_segundo;

    return self;
}

void ClockIncrement(clock_t reloj)
{
    reloj->tics_actual++;
    if (reloj->tics_actual >= reloj->tics)
    {
        reloj->tics_actual = 0;
        SecondsIncrement(reloj);
    }

    return;
}

bool ClockGetTime(clock_t reloj, uint8_t * hora, int size)
{
    memcpy(hora, reloj->hora_actual, size);

    return reloj->valida;
}

bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size)
{
    memcpy(reloj->hora_actual, hora, size);
    reloj->valida = true;

    return true;
}
