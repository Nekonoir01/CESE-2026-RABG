/*
 * AHT10.c
 *
 *  Created on: Apr 14, 2026
 *      Author: rberr
 */
#include "AHT10.h"
#include "port.h" // Incluir el header de port para usar las funciones de I2C abstractas    

// Inicialización del sensor
uint8_t AHT10_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t cmd[3] = {0xE1, 0x08, 0x00}; // Comando de inicialización

    if (I2C_Write(hi2c, AHT10_I2C_ADDRESS, cmd, 3) != HAL_OK)
        return 0;

    PORT_delay(100); // Tiempo de inicialización

    return 1;
}

// Verificar conexión del sensor
uint8_t AHT10_conectado(I2C_HandleTypeDef *hi2c)
{
    return (I2C_IsDeviceReady(hi2c, AHT10_I2C_ADDRESS) == 1);
}

// Lectura de temperatura y humedad
uint8_t AHT10_LeerDatos(I2C_HandleTypeDef *hi2c, AHT10_Data_t *data)
{
    uint8_t cmd[3] = {0xAC, 0x33, 0x00}; // Comando de medición
    uint8_t buffer[6]; // Buffer para datos crudos

    // 1. Enviar comando de medición
    if (I2C_Write(hi2c, AHT10_I2C_ADDRESS, cmd, 3) != HAL_OK)
        return 0;

    PORT_delay(75); // Tiempo de medición    

    if (I2C_Read(hi2c, AHT10_I2C_ADDRESS, buffer, 6) != HAL_OK)
        return 0;

    if (buffer[0] & 0x80) // Verificar bit de error
        return 0; // Si el bit de error está activo, no se pueden usar los datos leídos

    /**
     Formato de datos:
     Byte 0: estado
     Byte 1-3: humedad (20 bits)
     Byte 3-5: temperatura (20 bits)
    */

    uint32_t hum  = ((buffer[1] << 16) | (buffer[2] << 8) | buffer[3]) >> 4;

    uint32_t temp = ((buffer[3] & 0x0F) << 16) | (buffer[4] << 8) | buffer[5];

    data->humidity    = (hum * 100.0f) / 1048576.0f;        // porcentaje de humedad relativa
    data->temperature = (temp * 200.0f) / 1048576.0f - 50;  // grado Celsius

    return 1;
}
