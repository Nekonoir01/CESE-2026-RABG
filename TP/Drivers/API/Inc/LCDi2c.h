#ifndef LCDI2C_H
#define LCDI2C_H
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"
#define LCD_I2C_ADDRESS (0x27 << 1) // Dirección I2C del PCF8574T, ajustada para HAL (7 bits + bit de lectura/escritura)

void LCD_init(I2C_HandleTypeDef *hi2c); // Función para inicializar el LCD, debe ser llamada antes de usar cualquier otra función relacionada con el LCD
void LCD_sendCommand(uint8_t command); // Función para enviar un comando al LCD
void LCD_sendData(uint8_t data); // Función para enviar datos al LCD    
void LCD_print(char *str); // Función para enviar una cadena de caracteres al LCD
void LCD_setCursor(uint8_t row, uint8_t col); // Función para establecer la posición del cursor en el LCD, row es la fila (0 o 1) y col es la columna (0 a 15)
void LCD_clear(void); // Función para limpiar la pantalla del LCD   

#endif /* LCDI2C_H */
