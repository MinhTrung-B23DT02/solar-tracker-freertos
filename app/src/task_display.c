#include "task_display.h"
#include "task.h"
#include "app_cfg.h"
#include "app_ipc.h"
#include "ina219.h"
#include "oled_ssd1306.h"

static void prvDisplayTask(void *pvParameters)
{
    INA219_Measurement_t measurement = {0};
    Tracking_Status_t status = {
        .servo_angle_deg = APP_SERVO_INITIAL_ANGLE,
        .light_error = 0,
        .tracking_active = 0U
    };
    TickType_t last_wake = xTaskGetTickCount();
    const TickType_t period = pdMS_TO_TICKS(APP_DISPLAY_PERIOD_MS);
    (void)pvParameters;

    /* INA219 and OLED share I2C1. Keep the bus protected by one mutex. */
    if (xSemaphoreTake(xI2CMutex, portMAX_DELAY) == pdTRUE) {
        (void)INA219_Init();
        (void)OLED_SSD1306_Init();
        (void)xSemaphoreGive(xI2CMutex);
    }

    for (;;) {
        (void)xQueueReceive(qStatus, &status, 0U);

        if (xSemaphoreTake(xI2CMutex, portMAX_DELAY) == pdTRUE) {
            if (INA219_ReadMeasurements(&measurement) == 0) {
                (void)OLED_SSD1306_ShowTrackerStatus(
                    measurement.bus_voltage_v,
                    measurement.current_ma,
                    measurement.power_mw,
                    status.servo_angle_deg,
                    status.light_error,
                    status.tracking_active);
            }
            (void)xSemaphoreGive(xI2CMutex);
        }

        vTaskDelayUntil(&last_wake, period);
    }
}

BaseType_t task_display_create(void)
{
    return xTaskCreate(prvDisplayTask, "Display", TASK_DISPLAY_STACK_SIZE,
                       NULL, TASK_DISPLAY_PRIORITY, NULL);
}
