#include "hal_pwm.h"

void HAL_PWM_Init(void)
{
    /* TODO: configure TIM2_CH1 on PA0 for a 50 Hz servo control signal. */
}

int HAL_PWM_SetServoAngle(uint16_t angle_deg)
{
    (void)angle_deg;
    /* Not implemented yet: validate 0..180 and update TIM2 CCR1 pulse width. */
    return -1;
}
