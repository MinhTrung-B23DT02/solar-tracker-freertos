#include "hal_adc.h"

void HAL_ADC_Init(void)
{
    /* TODO (Hùng/Leader review): initialize ADC1 for GL5528 voltage dividers.
     * Use PA4/ADC1_IN4 and PA5/ADC1_IN5; ADC input voltage must stay <= 3.3 V.
     */
}

int HAL_ADC_Read(uint8_t channel, uint16_t *value)
{
    (void)channel;
    (void)value;
    /* Not implemented yet: do not report false success. */
    return -1;
}
