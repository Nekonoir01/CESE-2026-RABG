#include "API_delay.h"
#include "stm32f4xx_hal.h"

void delayInit(delay_t *delay, tick_t duration)/** Inicializa temporizador */
{
  delay->duration  = duration; /** Guarda cuanto tiempo debe durar el delay */
  delay->startTime = HAL_GetTick(); /** Guarda el tiempo en ms */
  delay->running   = true; /** Marca el temporizador como activo */
}

bool_t delayRead(delay_t *delay)
{
  if (delay->running &&
      (HAL_GetTick() - delay->startTime >= delay->duration)) /** calcula el tiempo desde la inicializacion */
  {
    delay->running = false;   // se dispara una sola vez
    return true;
  }

  return false;
}

void delayWrite(delay_t *delay, tick_t duration) /** reinicia el temporizador con nueva duracion */
{
  delay->duration  = duration; /** cambia tiempo de retardo*/
  delay->startTime = HAL_GetTick();
  delay->running   = true;
}

/* --- OPCIONAL PERO NECESARIA SI LA USAS EN main.c --- */
bool_t delayIsRunning(delay_t *delay)
{
  return delay->running;
}
