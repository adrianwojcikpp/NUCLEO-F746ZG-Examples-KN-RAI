/**
  ******************************************************************************
  * @file     : serial_readcstring.c
  * @author   : AW    Adrian.Wojcik@put.poznan.pl
  * @version  : 1.0.0
  * @date     : 2024-04-15 19:14
  * @brief    : Serial port utility for reading C-String to buffer
  *
  ******************************************************************************
  */

/* Private includes ----------------------------------------------------------*/
#include "usart.h"
#include <string.h>

/* Private variables ---------------------------------------------------------*/
const UART_HandleTypeDef *serial = &huart3;
const uint16_t serial_timeout = 10; //< ms

/* Public functions ----------------------------------------------------------*/
/**
 * @brief Reads C-String from serial port
 * @param[out] rx_buffer     : received C-String buffer
 * @param[in]  rx_buffer_len : received C-String buffer length
 * retval Number of received characters.
 *        -1 if error occurs.
 **/
int Serial_readCString(char* rx_buffer, unsigned int rx_buffer_len)
{
  unsigned int rx_i = 0;
  unsigned char rx_tmp;
  HAL_StatusTypeDef status;
  while((status = HAL_UART_Receive((UART_HandleTypeDef*)serial, &rx_tmp, sizeof(unsigned char), (uint16_t)serial_timeout)) == HAL_OK)
  {
    rx_buffer[rx_i] = rx_tmp;
    rx_buffer[rx_i+1] = '\0';
    rx_i = (rx_i+1) % (rx_buffer_len-1);
  }
  if(status == HAL_ERROR)
    return -1;
  else
    return rx_i;
}
