#ifndef HAL_PWM_H
#define HAL_PWM_H

#include <stdint.h>

/* PWM output for one positional SG90 servo. */
void HAL_PWM_Init(void);
int HAL_PWM_SetServoAngle(uint16_t angle_deg);

#endif /* HAL_PWM_H */
