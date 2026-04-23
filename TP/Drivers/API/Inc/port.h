/*
 * port.h
 *
 *  Created on: Apr 22, 2026
 *      Author: rberr
 */

#ifndef API_INC_PORT_H_
#define API_INC_PORT_H_

#include "stm32f4xx_hal.h"

 HAL_StatusTypeDef I2C_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size); // Función para escribir datos a través de I2C
 HAL_StatusTypeDef I2C_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size); // Función para leer datos a través de I2C
 uint8_t I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress); // Función para verificar si un dispositivo está listo en el bus I2C 
void PORT_delay(uint32_t ms); // Función para generar una demora en milisegundos, útil para temporizaciones en la máquina de estados

#endif /* API_INC_PORT_H_ */
