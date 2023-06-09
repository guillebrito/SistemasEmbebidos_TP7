#include <stdbool.h>
#include <stdint.h>

typedef struct clock_s * clock_t;

typedef void (*alarma_event_t)(bool estado);

clock_t ClockCreate(int tics_por_segundo, alarma_event_t ActivarAlarma);

void ClockIncrement(clock_t reloj);

bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size);

bool ClockGetTime(clock_t reloj, uint8_t * hora, int size);

void AlarmSetTime(clock_t reloj, const uint8_t * alarma, int size);

void AlarmGetTime(clock_t reloj, uint8_t * alarma, int size);

void AlarmEnamble(clock_t reloj, bool estado);

bool AlarmGetState(clock_t reloj);

void AlarmPostpone(clock_t reloj, uint8_t minutos);

void AlarmCancel(clock_t reloj);