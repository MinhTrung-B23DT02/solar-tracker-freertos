#ifndef BSP_H
#define BSP_H

#include <stdint.h>

/* Board Support Package for STM32F103C8T6 (Blue Pill).
 * Clock-tree initialization belongs here and is owned by the project lead.
 */
void BSP_Init(void);

/* Project pin mapping (default peripheral remap is not used):
 * PA4 : GL5528 left  -> ADC1_IN4
 * PA5 : GL5528 right -> ADC1_IN5
 * PA0 : SG90 signal  -> TIM2_CH1
 * PB6 : I2C1_SCL     -> INA219 + SSD1306
 * PB7 : I2C1_SDA     -> INA219 + SSD1306
 */
#define BSP_LDR_LEFT_ADC_CHANNEL    (4U)
#define BSP_LDR_RIGHT_ADC_CHANNEL   (5U)
#define BSP_SERVO_TIM_CHANNEL      (1U)

#endif /* BSP_H */
