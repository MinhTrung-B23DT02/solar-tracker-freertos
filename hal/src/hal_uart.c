#include "hal_uart.h"

void HAL_UART_Init(uint32_t baudrate)
{
    (void)baudrate;
    /* TODO: Hardware-specific UART peripheral init */
}

int HAL_UART_Transmit(const uint8_t *data, size_t len, uint32_t timeout_ms)
{
    (void)data;
    (void)len;
    (void)timeout_ms;
    /* TODO: Transmit data over UART */
    return 0;
}

int HAL_UART_Receive(uint8_t *data, size_t len, uint32_t timeout_ms)
{
    (void)data;
    (void)len;
    (void)timeout_ms;
    /* TODO: Receive data over UART */
    return 0;
}
