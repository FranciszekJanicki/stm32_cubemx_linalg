#include "usart.h"
#include <stdio.h>

__attribute__((used)) int _write(int file, char* ptr, int len)
{
    HAL_StatusTypeDef err = HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, len);

    return err == HAL_OK ? len : 0;
}
