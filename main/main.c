#include "main.h"
#include "gpio.h"
#include "linalg.h"
#include "usart.h"
#include <stdarg.h>
#include <stdio.h>

int matrix_printf(char const* format, ...)
{
    va_list args;
    va_start(args);
    vprintf(format, args);
    va_end(args);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_USART2_UART_Init();

    HAL_Delay(500U);

    matrix3_t matrix1;
    matrix3_t matrix2;
    matrix3_t matrix3;

    matrix3_data_t array1[3U][3U] = {{1.0F, 2.0F, 3.0F},
                                     {4.0F, 5.0F, 6.0F},
                                     {7.0F, 8.0F, 9.0F}};
    matrix3_data_t array2[3U][3U] = {{9.0F, 8.0F, 7.0F},
                                     {6.0F, 5.0F, 4.0F},
                                     {3.0F, 2.0F, 1.0F}};

    matrix3_fill_with_array(&matrix1, &array1);
    matrix3_fill_with_array(&matrix2, &array2);

    matrix3_product(&matrix1, &matrix2, &matrix3);
    matrix3_print(&matrix3, matrix_printf, "\n\r");

    matrix3_inverse(&matrix2, &matrix3);
    matrix3_print(&matrix3, matrix_printf, "\n\r");

    matrix3_transpose(&matrix1, &matrix3);
    matrix3_print(&matrix3, matrix_printf, "\n\r");
}
