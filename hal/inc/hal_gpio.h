#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum {
    HAL_GPIO_PIN_RESET = 0,
    HAL_GPIO_PIN_SET = 1
} hal_gpio_pin_state_t;

void HAL_GPIO_Init(void);
void HAL_GPIO_WritePin(uint8_t port, uint16_t pin, hal_gpio_pin_state_t state);
hal_gpio_pin_state_t HAL_GPIO_ReadPin(uint8_t port, uint16_t pin);
void HAL_GPIO_TogglePin(uint8_t port, uint16_t pin);

#ifdef __cplusplus
}
#endif

#endif /* HAL_GPIO_H */
