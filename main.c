#include "bsp.h"
#include "hal_gpio.h"
#include "hal_adc.h"
#include "hal_i2c.h"
#include "hal_pwm.h"
#include "app_ipc.h"
#include "task_sensor.h"
#include "task_tracking.h"
#include "task_display.h"
#include "FreeRTOS.h"
#include "task.h"

static void Error_Handler(void)
{
    /* TODO: add a board-level error indication (e.g. LED blink). */
    taskDISABLE_INTERRUPTS();
    for (;;) {
    }
}

void vApplicationStackOverflowHook(TaskHandle_t task, char *task_name)
{
    (void)task;
    (void)task_name;
    Error_Handler();
}

void vApplicationMallocFailedHook(void)
{
    Error_Handler();
}

int main(void)
{
    /* Stage 1: board and peripheral initialization. */
    BSP_Init();
    HAL_GPIO_Init();
    HAL_ADC_Init();
    HAL_I2C_Init();
    HAL_PWM_Init();

    /* Stage 2: create shared RTOS objects before creating tasks. */
    if (app_ipc_init() != pdPASS) {
        Error_Handler();
    }

    /* Stage 3: create the three project tasks (no generic Comm task). */
    if (task_sensor_create() != pdPASS) {
        Error_Handler();
    }
    if (task_tracking_create() != pdPASS) {
        Error_Handler();
    }
    if (task_display_create() != pdPASS) {
        Error_Handler();
    }

    /* Stage 4: start FreeRTOS scheduler. */
    vTaskStartScheduler();

    /* Reaching here usually means the scheduler could not start (e.g. heap). */
    Error_Handler();
    return 0;
}
