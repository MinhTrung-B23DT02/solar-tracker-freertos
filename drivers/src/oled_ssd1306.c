#include "oled_ssd1306.h"
#include "hal_i2c.h"

#define OLED_SSD1306_I2C_ADDRESS  (0x3CU)

int OLED_SSD1306_Init(void)
{
    (void)OLED_SSD1306_I2C_ADDRESS;
    /* TODO (Nam): send the SSD1306 initialization command sequence. */
    return -1;
}

int OLED_SSD1306_ShowTrackerStatus(float voltage_v, float current_ma,
                                   float power_mw, uint16_t servo_angle_deg,
                                   int16_t light_error, uint8_t tracking_active)
{
    (void)voltage_v;
    (void)current_ma;
    (void)power_mw;
    (void)servo_angle_deg;
    (void)light_error;
    (void)tracking_active;
    /* TODO (Nam): render measurement and tracking information on the OLED. */
    return -1;
}
