#include "hal_i2c.h"

void HAL_I2C_Init(void)
{
    /* TODO (Nam/Leader review): initialize I2C1 on PB6=SCL and PB7=SDA. */
}

int HAL_I2C_MasterTransmit(uint16_t dev_addr, const uint8_t *data,
                           size_t len, uint32_t timeout_ms)
{
    (void)dev_addr;
    (void)data;
    (void)len;
    (void)timeout_ms;
    /* Not implemented yet: return error until the register-level driver exists. */
    return -1;
}

int HAL_I2C_MasterReceive(uint16_t dev_addr, uint8_t *data,
                          size_t len, uint32_t timeout_ms)
{
    (void)dev_addr;
    (void)data;
    (void)len;
    (void)timeout_ms;
    return -1;
}

int HAL_I2C_MemWrite(uint16_t dev_addr, uint8_t reg, const uint8_t *data,
                     size_t len, uint32_t timeout_ms)
{
    (void)dev_addr;
    (void)reg;
    (void)data;
    (void)len;
    (void)timeout_ms;
    return -1;
}

int HAL_I2C_MemRead(uint16_t dev_addr, uint8_t reg, uint8_t *data,
                    size_t len, uint32_t timeout_ms)
{
    (void)dev_addr;
    (void)reg;
    (void)data;
    (void)len;
    (void)timeout_ms;
    return -1;
}
