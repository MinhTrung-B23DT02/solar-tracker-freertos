#include "task_display.h"
#include "app_ipc.h"
#include "hal_uart.h"

void Task_Display_Init(void)
{
    /* TODO: Khởi tạo task bằng xTaskCreate hoặc osThreadNew */
}

void Task_Display_Function(void *argument)
{
    (void)argument;

    for (;;) {
        /* TODO: Chờ nhận dữ liệu từ Queue (xQueueReceive)
         * Hiển thị dữ liệu lên màn hình OLED/LCD hoặc gửi qua UART
         */
    }
}
