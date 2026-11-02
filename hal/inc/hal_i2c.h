#ifndef HAL_I2C_H
#define HAL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

void HAL_I2C_Init(void);
int HAL_I2C_MasterTransmit(uint16_t dev_addr, const uint8_t *data, size_t len, uint32_t timeout_ms);
int HAL_I2C_MasterReceive(uint16_t dev_addr, uint8_t *data, size_t len, uint32_t timeout_ms);

#ifdef __cplusplus
}
#endif

#endif /* HAL_I2C_H */
