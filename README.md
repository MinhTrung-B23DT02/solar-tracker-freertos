# MCU Project - Embedded Systems & FreeRTOS

Dự án Hệ thống nhúng (Bài tập lớn) cấu trúc theo mô hình phân lớp (Layered Architecture):

## Cấu trúc thư mục

```text
├── bsp/             # Board Support Package & Pin mapping
├── hal/             # Hardware Abstraction Layer (Drivers ngoại vi)
│   ├── inc/         # Header files: hal_gpio.h, hal_uart.h, hal_i2c.h...
│   └── src/         # Source files: hal_gpio.c, hal_uart.c, hal_i2c.c...
├── middlewares/     # FreeRTOS source (Kernel, Port, Heap)
├── app/             # Ứng dụng: FreeRTOS Tasks & IPC
│   ├── inc/         # Header files: task_sensor.h, task_display.h, app_ipc.h...
│   └── src/         # Source files: task_sensor.c, task_display.c, app_ipc.c...
├── main.c           # Init hardware, tạo task, vTaskStartScheduler()
├── .gitignore
└── README.md
```

## Mô tả các tầng

1. **BSP (Board Support Package)**: Khởi tạo phần cứng chuyên biệt cho board mạch và cấu hình định nghĩa chân (Pin mapping).
2. **HAL (Hardware Abstraction Layer)**: Các driver giao tiếp ngoại vi (GPIO, UART, I2C, SPI, ADC, ...), che giấu tầng thanh ghi trực tiếp của MCU.
3. **Middlewares**: Chứa mã nguồn hệ điều hành thời gian thực (FreeRTOS) bao gồm Kernel, Porting layer và Heap memory manager.
4. **App**: Các tác vụ nghiệp vụ (Tasks) chạy trên FreeRTOS và cơ chế truyền tin liên tiến trình (IPC - Queue, Semaphore, Event Group, Mutex).
5. **main.c**: Điểm vào chính của chương trình, khởi tạo xung nhịp, ngoại vi, khởi tạo FreeRTOS tasks/queues và bắt đầu bộ lập lịch `vTaskStartScheduler()`.
