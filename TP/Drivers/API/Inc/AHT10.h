/*
 * AHT10.h
 *
 *  Created on: Apr 14, 2026
 *      Author: rberr
 */

#ifndef API_INC_AHT10_H_
#define API_INC_AHT10_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"
#include <stdint.h>

#define AHT10_I2C_ADDRESS 0x38 << 1 // AHT10 I2C address dado por el fabricante

typedef struct{
    float temperature;
    float humidity;
} AHT10_Data_t;

uint8_t AHT10_Init(I2C_HandleTypeDef *hi2c); // Función para inicializar el AHT10, debe ser llamada antes de leer los datos
uint8_t AHT10_conectado(I2C_HandleTypeDef *hi2c); // Función para verificar si el AHT10 está conectado
uint8_t AHT10_LeerDatos(I2C_HandleTypeDef *hi2c, AHT10_Data_t *data); // Función para leer los datos de temperatura y humedad del AHT10

#endif /* API_INC_AHT10_H_ */
