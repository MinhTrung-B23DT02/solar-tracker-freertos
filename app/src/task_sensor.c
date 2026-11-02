#include "task_sensor.h"
#include "app_ipc.h"
#include "hal_i2c.h"

void Task_Sensor_Init(void)
{
    /* TODO: Khởi tạo task bằng xTaskCreate hoặc osThreadNew */
}

void Task_Sensor_Function(void *argument)
{
    (void)argument;

    for (;;) {
        /* TODO: Đọc dữ liệu từ cảm biến qua HAL (ví dụ I2C / ADC)
         * Đẩy dữ liệu vào Queue để Task Display hoặc Task khác xử lý
         * vTaskDelay(pdMS_TO_TICKS(1000));
         */
    }
}
