#ifndef HAL_I2C_H
#define HAL_I2C_H

#include <stdint.h>
#include <stddef.h>

/* Device addresses use the unshifted 7-bit I2C format (e.g. INA219 0x40,
 * SSD1306 commonly 0x3C). Return 0 on success, negative on error.
 */
void HAL_I2C_Init(void);
int HAL_I2C_MasterTransmit(uint16_t dev_addr, const uint8_t *data,
                           size_t len, uint32_t timeout_ms);
int HAL_I2C_MasterReceive(uint16_t dev_addr, uint8_t *data,
                          size_t len, uint32_t timeout_ms);
int HAL_I2C_MemWrite(uint16_t dev_addr, uint8_t reg, const uint8_t *data,
                     size_t len, uint32_t timeout_ms);
int HAL_I2C_MemRead(uint16_t dev_addr, uint8_t reg, uint8_t *data,
                    size_t len, uint32_t timeout_ms);

#endif /* HAL_I2C_H */
