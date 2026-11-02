#include "hal_gpio.h"

void HAL_GPIO_Init(void)
{
    /* TODO: Hardware-specific GPIO configuration */
}

void HAL_GPIO_WritePin(uint8_t port, uint16_t pin, hal_gpio_pin_state_t state)
{
    (void)port;
    (void)pin;
    (void)state;
    /* TODO: Write state to MCU pin register */
}

hal_gpio_pin_state_t HAL_GPIO_ReadPin(uint8_t port, uint16_t pin)
{
    (void)port;
    (void)pin;
    /* TODO: Read pin register */
    return HAL_GPIO_PIN_RESET;
}

void HAL_GPIO_TogglePin(uint8_t port, uint16_t pin)
{
    (void)port;
    (void)pin;
    /* TODO: Toggle pin */
}
