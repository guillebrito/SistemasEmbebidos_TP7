/************************************************************************************************
Copyright (c) 2023, Guillermo Nicolás Brito <guillermonbrito@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef RELOJ_H
#define RELOJ_H

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions ================================================================ */
#include <stdbool.h>
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C"
{
#endif

    /* === Public macros definitions =============================================================== */

    /* === Public data type declarations =========================================================== */

    typedef struct clock_s * clock_t;

    typedef void (*alarma_event_t)(bool estado);

    /* === Public variable declarations ============================================================ */

    /* === Public function declarations ============================================================ */

    //******Funciones asociadas al reloj*******//

    clock_t ClockCreate(int tics_por_segundo, alarma_event_t ActivarAlarma);

    void ClockIncrement(clock_t reloj);

    bool ClockSetTime(clock_t reloj, const uint8_t * hora, int size);

    bool ClockGetTime(clock_t reloj, uint8_t * hora, int size);

    //*****Funciones asociadas a la alarma*****//

    void AlarmEnamble(clock_t reloj, bool estado);

    void AlarmPostpone(clock_t reloj, uint8_t minutos);

    void AlarmCancel(clock_t reloj);

    bool AlarmSetTime(clock_t reloj, const uint8_t * alarma, int size);

    bool AlarmGetTime(clock_t reloj, uint8_t * alarma, int size);

    bool AlarmGetState(clock_t reloj);

    /* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* RELOJ_H */
