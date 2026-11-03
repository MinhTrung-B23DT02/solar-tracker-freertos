#include "hal_gpio.h"

void HAL_GPIO_Init(void)
{
    /* TODO: configure GPIO clocks and pin modes for the STM32F103C8T6. */
}

void HAL_GPIO_WritePin(uint8_t port, uint16_t pin, hal_gpio_pin_state_t state)
{
    (void)port;
    (void)pin;
    (void)state;
    /* TODO: write the selected GPIO output register. */
}

hal_gpio_pin_state_t HAL_GPIO_ReadPin(uint8_t port, uint16_t pin)
{
    (void)port;
    (void)pin;
    /* TODO: read the selected GPIO input register. */
    return HAL_GPIO_PIN_RESET;
}

void HAL_GPIO_TogglePin(uint8_t port, uint16_t pin)
{
    (void)port;
    (void)pin;
    /* TODO: toggle the selected GPIO output. */
}
