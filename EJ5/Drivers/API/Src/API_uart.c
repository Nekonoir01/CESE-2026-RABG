#include "API_uart.h"
#include <string.h>

static UART_HandleTypeDef huart2;


/**
 * Inicializa el periférico UART2 con configuración estándar.
 *
 * Configura UART2 con:
 * - Baudrate: 115200
 * - 8 bits de datos
 * - Sin paridad
 * - 1 bit de stop
 *
 * return true si la inicialización fue exitosa
 * return false si ocurrió un error
 */
bool_t uartInit(void)
{
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        return false;
    }

    const char *msg = "UART Init: 115200 8N1\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

    return true;
}

/**
 * Envía una cadena terminada en NULL por UART.
 *
 * pstring Puntero a la cadena a enviar
 * return None
 */
void uartSendString(uint8_t *pstring)
{
    if (pstring == NULL)
        return;

    uint16_t length = strlen((char*)pstring);

    if (length == 0)
        return;

    if (HAL_UART_Transmit(&huart2, pstring, length, HAL_MAX_DELAY) != HAL_OK)
    {

    }
}

/**
 * Envía una cadena de tamaño específico por UART.
 *
 * param pstring Puntero al buffer a enviar
 * param size Cantidad de bytes a enviar
 * return None
 */
void uartSendStringSize(uint8_t *pstring, uint16_t size)
{
    if (pstring == NULL)
        return;

    if (size == 0)
        return;

    if (HAL_UART_Transmit(&huart2, pstring, size, HAL_MAX_DELAY) != HAL_OK)
    {
    }
}

/**
 * Recibe una cantidad específica de bytes por UART.
 *
 * pstring Puntero al buffer de recepción
 * size Cantidad de bytes a recibir
 * return None
 */
void uartReceiveStringSize(uint8_t *pstring, uint16_t size)
{
    if (pstring == NULL)
        return;

    if (size == 0)
        return;

    if (HAL_UART_Receive(&huart2, pstring, size, HAL_MAX_DELAY) != HAL_OK)
    {
    }
}

