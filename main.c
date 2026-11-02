#include <stdint.h>
#include "bsp.h"
#include "hal_gpio.h"
#include "hal_uart.h"
#include "hal_i2c.h"
#include "app_ipc.h"
#include "task_sensor.h"
#include "task_display.h"

/* FreeRTOS Header files (Bỏ comment khi đã thêm FreeRTOS source vào middlewares)
#include "FreeRTOS.h"
#include "task.h"
*/

static void SystemHardware_Init(void)
{
    /* 1. Khởi tạo xung nhịp và cấu hình chân board mạch */
    BSP_Init();

    /* 2. Khởi tạo ngoại vi HAL */
    HAL_GPIO_Init();
    HAL_UART_Init(115200);
    HAL_I2C_Init();
}

int main(void)
{
    /* 1. Khởi tạo phần cứng */
    SystemHardware_Init();

    /* 2. Khởi tạo cơ chế IPC (Queue, Semaphore, Mutex) */
    App_IPC_Init();

    /* 3. Khởi tạo các FreeRTOS Tasks */
    Task_Sensor_Init();
    Task_Display_Init();

    /* 4. Khởi động bộ lập lịch FreeRTOS */
    /* vTaskStartScheduler(); */

    /* Nếu đến được đây nghĩa là bộ nhớ heap không đủ để chạy scheduler */
    for (;;) {
    }

    return 0;
}
