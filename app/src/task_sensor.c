#include "task_sensor.h"
#include "task.h"
#include "app_cfg.h"
#include "app_ipc.h"
#include "bsp.h"
#include "hal_adc.h"

static void prvSensorTask(void *pvParameters)
{
    LDR_Data_t sample;
    TickType_t last_wake = xTaskGetTickCount();
    const TickType_t period = pdMS_TO_TICKS(APP_SENSOR_PERIOD_MS);
    (void)pvParameters;

    for (;;) {
        if ((HAL_ADC_Read(BSP_LDR_LEFT_ADC_CHANNEL, &sample.ldr_left) == 0) &&
            (HAL_ADC_Read(BSP_LDR_RIGHT_ADC_CHANNEL, &sample.ldr_right) == 0)) {
            /* Queue length is one: publish the newest pair of LDR readings. */
            (void)xQueueOverwrite(qLDR, &sample);
        }
        vTaskDelayUntil(&last_wake, period);
    }
}

BaseType_t task_sensor_create(void)
{
    return xTaskCreate(prvSensorTask, "Sensor", TASK_SENSOR_STACK_SIZE,
                       NULL, TASK_SENSOR_PRIORITY, NULL);
}
