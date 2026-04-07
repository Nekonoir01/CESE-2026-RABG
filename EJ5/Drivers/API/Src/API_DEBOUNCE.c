/*
 * API_debounce.c
 *
 *  Created on: Apr 1, 2026
 *      Author: rberr
 */
#include "API_debounce.h"
#include "main.h"

// Estados (PRIVADO)
typedef enum{
  BUTTON_UP,
  BUTTON_FALLING,
  BUTTON_DOWN,
  BUTTON_RAISING,
} debounceState_t;

// Variables privadas
static debounceState_t estado;
static delay_t delayDebounce;
static bool_t keyPressed = false;

// Inicialización
void debounceFSM_init(void)
{
  estado = BUTTON_UP;
  delayInit(&delayDebounce, 40);
}

// FSM anti-rebote
void debounceFSM_update(void)
{
  switch (estado)
  {
    case BUTTON_UP:
      if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
      {
        estado = BUTTON_FALLING;
        delayWrite(&delayDebounce, 40);
      }
      break;

    case BUTTON_FALLING:
      if (delayRead(&delayDebounce))
      {
        if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET)
        {
          estado = BUTTON_DOWN;
          keyPressed = true; //  flanco descendente
        }
        else
        {
          estado = BUTTON_UP;
        }
      }
      break;

    case BUTTON_DOWN:
      if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_SET)
      {
        estado = BUTTON_RAISING;
        delayWrite(&delayDebounce, 40);
      }
      break;

    case BUTTON_RAISING:
      if (delayRead(&delayDebounce))
      {
        if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_SET)
        {
          estado = BUTTON_UP;
        }
        else
        {
          estado = BUTTON_DOWN;
        }
      }
      break;
  }
}

// Función pedida
bool_t readKey(void)
{
  if (keyPressed)
  {
    keyPressed = false;
    return true;
  }
  return false;
}

