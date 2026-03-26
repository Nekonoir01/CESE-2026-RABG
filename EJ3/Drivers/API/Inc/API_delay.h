#ifndef API_DELAY_H
#define API_DELAY_H

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t tick_t;
typedef bool bool_t;

typedef struct {
  tick_t startTime;
  tick_t duration;
  bool_t running;
} delay_t;

void delayInit(delay_t *delay, tick_t duration); /** Inicializa temporizador */
bool_t delayRead(delay_t *delay); /** lee el estado del temporizador */
void delayWrite(delay_t *delay, tick_t duration); /** Establece un nuevo temporizador */
bool_t delayIsRunning(delay_t *delay); /** Indica si esta activo el temporizador */
#endif
