#include "LCDi2c.h"
#include "port.h" 

#define PCF8574T_backlight 0x08 // Pin para controlar la luz de fondo del LCD
#define PCF8574T_RS 0x01 // Pin para el registro de selección (RS)
#define PCF8574T_ENABLE 0x04    // Pin para el control de habilitación (Enable)

static I2C_HandleTypeDef *hi2c_lcd; // Puntero al manejador de I2C para el LCD

static void LCD_write(uint8_t data)
{
    I2C_Write(hi2c_lcd, LCD_I2C_ADDRESS, &data, 1); // Enviar datos al PCF8574T  
}


static void LCD_pulseEnable(uint8_t data)
{
    LCD_write(data | PCF8574T_ENABLE); // Establecer el pin de habilitación
    PORT_delay(1); // Pequeña demora para asegurar que el LCD registre el pulso
    LCD_write(data & ~PCF8574T_ENABLE); // Limpiar el pin de habilitación
    PORT_delay(1); // Pequeña demora para asegurar que el LCD registre el pulso
}

static void LCD_write4Bits(uint8_t data)
{
    LCD_write(data | PCF8574T_backlight); // Asegurar que la luz de fondo esté encendida
    LCD_pulseEnable(data); // Pulsar el pin de habilitación para enviar los datos
}

void LCD_sendCommand(uint8_t command)
{
    LCD_write4Bits((command & 0xF0) | PCF8574T_backlight); // Enviar los 4 bits altos del comando
    LCD_write4Bits(((command << 4) & 0xF0) | PCF8574T_backlight); // Enviar los 4 bits bajos del comando
}
void LCD_sendData(uint8_t data)
{
    LCD_write4Bits((data & 0xF0) | PCF8574T_RS | PCF8574T_backlight); // Enviar los 4 bits altos del dato con RS activo
    LCD_write4Bits(((data << 4) & 0xF0) | PCF8574T_RS | PCF8574T_backlight); // Enviar los 4 bits bajos del dato con RS activo
}
void LCD_init(I2C_HandleTypeDef *hi2c)
{
    hi2c_lcd = hi2c; 

    PORT_delay(50); // Esperar a que el LCD se estabilice después de la alimentación

    // Secuencia de inicialización para LCD en modo 4 bits
    LCD_write4Bits(0x30); // Enviar 0x30 para configurar el LCD en modo 8 bits
    PORT_delay(5); 
    LCD_write4Bits(0x30); // Repetir el comando para asegurar la configuración
    PORT_delay(1); 
    LCD_write4Bits(0x30); // Repetir nuevamente
    PORT_delay(1);
    LCD_write4Bits(0x20); // Enviar 0x20 para configurar el LCD en modo 4 bits
    PORT_delay(1);

    // Configuración del LCD: 2 líneas, fuente de 5x8 puntos
    LCD_sendCommand(0x28);
    // Encender el display, sin cursor, sin parpadeo
    LCD_sendCommand(0x0C);
    // Limpiar la pantalla
    LCD_sendCommand(0x01);
    PORT_delay(2); // Esperar a que se complete la limpieza

    // Configurar el modo de entrada: incremento del cursor, sin desplazamiento de pantalla
    LCD_sendCommand(0x06);
}

void LCD_print(char *str)
{
    while (*str)
    {
        LCD_sendData((uint8_t)(*str)); // Enviar cada carácter de la cadena al LCD
        str++;
    }
}
void LCD_setCursor(uint8_t row, uint8_t col)
{
    uint8_t address;
    switch(row)
    {
        case 0: address = 0x00 + col; break; // Primera fila
        case 1: address = 0x40 + col; break; // Segunda fila
        default: address = 0x00 + col; break; // Por defecto, primera fila
    }
    LCD_sendCommand(0x80 | address); // Enviar comando para establecer la dirección del cursor
}
void LCD_clear(void)
{
    LCD_sendCommand(0x01); // Comando para limpiar la pantalla
    PORT_delay(2); // Esperar a que se complete la limpieza
}