#ifndef HAL_ADC_H
#define HAL_ADC_H

#include <stdint.h>

/* Return 0 on success; return a negative value on error. */
void HAL_ADC_Init(void);
int HAL_ADC_Read(uint8_t channel, uint16_t *value);

#endif /* HAL_ADC_H */
