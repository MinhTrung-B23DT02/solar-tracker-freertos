#include "ina219.h"
#include "hal_i2c.h"

#define INA219_I2C_ADDRESS   (0x40U)

int INA219_Init(void)
{
    (void)INA219_I2C_ADDRESS;
    /* TODO (Nam): configure INA219 calibration and configuration registers.
     * Calibration depends on the actual shunt resistor fitted to the module.
     */
    return -1;
}

int INA219_ReadMeasurements(INA219_Measurement_t *measurement)
{
    (void)measurement;
    /* TODO (Nam): read bus voltage/current/power registers via HAL_I2C_MemRead. */
    return -1;
}
