#ifndef OLED_SSD1306_H
#define OLED_SSD1306_H

#include <stdint.h>

int OLED_SSD1306_Init(void);
int OLED_SSD1306_ShowTrackerStatus(float voltage_v, float current_ma,
                                   float power_mw, uint16_t servo_angle_deg,
                                   int16_t light_error, uint8_t tracking_active);

#endif /* OLED_SSD1306_H */
