#ifndef API_DEBOUNCE_H
#define API_DEBOUNCE_H

#include "API_delay.h"
#include <stdbool.h>

typedef bool bool_t;

void debounceFSM_init(void);
void debounceFSM_update(void);

/* Devuelve true si hubo flanco descendente
   y resetea el estado */
bool_t readKey(void);

#endif
