#include "hal_i2c.h"

void HAL_I2C_Init(void)
{
    /* TODO: Hardware-specific I2C peripheral init */
}

int HAL_I2C_MasterTransmit(uint16_t dev_addr, const uint8_t *data, size_t len, uint32_t timeout_ms)
{
    (void)dev_addr;
    (void)data;
    (void)len;
    (void)timeout_ms;
    /* TODO: Master transmit I2C */
    return 0;
}

int HAL_I2C_MasterReceive(uint16_t dev_addr, uint8_t *data, size_t len, uint32_t timeout_ms)
{
    (void)dev_addr;
    (void)data;
    (void)len;
    (void)timeout_ms;
    /* TODO: Master receive I2C */
    return 0;
}
