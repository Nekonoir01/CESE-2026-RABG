/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
#include "API_uart.h" 
#include <string.h>
UART_HandleTypeDef huart2;
bool_t uartInit()
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
    return false;
  
  return true;
}  
void uartSendString(uint8_t * pstring) // Send a null-terminated string over UART*/
{
    if(pstring == NULL) return;
    HAL_UART_Transmit(&huart2, pstring, strlen((char*)pstring), HAL_MAX_DELAY);
}
void uartReceiveStringSize(uint8_t * pstring, uint16_t size) // Receive a string of specified size over UART*/
{
  if(pstring == NULL) return;
  HAL_UART_Receive(&huart2, pstring, size, HAL_MAX_DELAY);

}
void uartSendStringSize(uint8_t * pstring, uint16_t size) // Send a string of specified size over UART*/
{
  if(pstring == NULL) return;
  HAL_UART_Transmit(&huart2, pstring, size, HAL_MAX_DELAY);
}

