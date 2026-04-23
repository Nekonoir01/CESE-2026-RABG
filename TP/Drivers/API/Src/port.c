/*
 * port.c
 *
 *  Created on: Apr 22, 2026
 *      Author: rberr
 */
#include "port.h"

HAL_StatusTypeDef I2C_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
    return HAL_I2C_Master_Transmit(hi2c, DevAddress, pData, Size, 100);
}

HAL_StatusTypeDef I2C_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
    return HAL_I2C_Master_Receive(hi2c, DevAddress, pData, Size, 100);
}

uint8_t I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress)
{
    return (HAL_I2C_IsDeviceReady(hi2c, DevAddress, 3, 100) == HAL_OK);
}

void PORT_delay(uint32_t ms)
{
    HAL_Delay(ms);
}
