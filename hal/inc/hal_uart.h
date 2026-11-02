#ifndef HAL_UART_H
#define HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

void HAL_UART_Init(uint32_t baudrate);
int HAL_UART_Transmit(const uint8_t *data, size_t len, uint32_t timeout_ms);
int HAL_UART_Receive(uint8_t *data, size_t len, uint32_t timeout_ms);

#ifdef __cplusplus
}
#endif

#endif /* HAL_UART_H */
