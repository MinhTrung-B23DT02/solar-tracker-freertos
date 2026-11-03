# Solar Tracker – STM32F103C8T6 + FreeRTOS

Dự án theo dõi mặt trời **một trục**, dùng hai cảm biến ánh sáng GL5528 và một servo SG90. INA219 đo điện áp/dòng điện/công suất của tải; OLED SSD1306 hiển thị trạng thái.

## 1. Cấu trúc mã nguồn

```text
mcu-project/
├── bsp/                 # Board Support Package, clock và pin mapping
│   ├── inc/bsp.h
│   └── src/bsp.c
├── hal/                 # HAL ngoại vi mức thấp
│   ├── inc/              # GPIO, ADC, I2C, PWM
│   └── src/
├── drivers/             # Driver thiết bị INA219 và SSD1306
│   ├── inc/
│   └── src/
├── middlewares/FreeRTOS/ # FreeRTOS Kernel và port ARM_CM3
├── app/                 # Ba FreeRTOS task và IPC
│   ├── inc/
│   └── src/
├── startup/             # Startup assembly của STM32F103
├── linker/              # Linker script STM32F103C8T6
├── config/              # FreeRTOSConfig.h
├── main.c
├── Makefile
├── .gitignore
└── README.md
```

## 2. Phân công ba task

| Task | Người phụ trách | Chức năng |
|---|---|---|
| `TaskSensor` | Hùng | Đọc LDR trái/phải qua ADC và gửi `LDR_Data_t` vào `qLDR` |
| `TaskTracking` | Trung (Leader) | Nhận dữ liệu LDR, tính sai lệch, điều khiển góc servo qua PWM và gửi `Tracking_Status_t` vào `qStatus` |
| `TaskDisplay` | Nam | Đọc INA219 và cập nhật điện áp, dòng điện, công suất cùng trạng thái tracking lên OLED |

## 3. IPC dùng chung

- `qLDR`: Queue độ dài 1, truyền từ `TaskSensor` sang `TaskTracking`.
- `qStatus`: Queue độ dài 1, truyền từ `TaskTracking` sang `TaskDisplay`.
- `xI2CMutex`: Mutex bảo vệ bus I2C1 dùng chung cho INA219 và OLED SSD1306.

## 4. Pin mapping dự kiến

| Chức năng | Chân STM32F103C8T6 | Ngoại vi |
|---|---|---|
| LDR trái | PA4 | ADC1_IN4 |
| LDR phải | PA5 | ADC1_IN5 |
| Servo SG90 | PA0 | TIM2_CH1 |
| I2C SCL | PB6 | I2C1_SCL |
| I2C SDA | PB7 | I2C1_SDA |

Dùng nguồn 5 V riêng phù hợp cho servo và nối chung GND với STM32. Không cấp nguồn servo từ chân 3.3 V của board. Điện áp đưa vào ADC không được vượt quá 3.3 V. INA219 phải mắc nối tiếp với tải cần đo; hệ số hiệu chuẩn phụ thuộc điện trở shunt thực tế.

## 5. Quy trình Git theo tài liệu nhóm

1. `main`: phiên bản ổn định, không commit trực tiếp.
2. `develop`: nhánh tích hợp chính.
3. `feature/*`: mỗi thành viên phát triển phần việc độc lập, sau đó tạo Pull Request vào `develop`.
4. Khi ba task đã được merge, tạo `integration/system-v1` để ghép IPC và `main.c`, kiểm thử rồi mới merge/release.

Nhánh feature của dự án:
- `feature/task-sensor`
- `feature/task-tracking`
- `feature/task-display`
- `feature/project-structure` (hoàn thiện cấu trúc ban đầu)

Trong giai đoạn phát triển task độc lập, không tự ý sửa `main.c`. Chỉ Leader quản lý clock, startup, linker và cấu hình FreeRTOS dùng chung. Trong ISR chỉ gọi API FreeRTOS có hậu tố `FromISR`; trong task dùng `vTaskDelay()`/`vTaskDelayUntil()` thay cho delay chặn phần cứng.

## 6. Trạng thái hiện tại và phần còn phải hoàn thiện

Đây là **bộ khung đã sắp xếp lại**, chưa phải firmware có thể nạp chạy. Các hàm HAL và driver thiết bị hiện được đánh dấu TODO và trả lỗi khi chưa triển khai. Cần bổ sung CMSIS/device headers, FreeRTOS Kernel cùng port `ARM_CM3`, startup assembly, linker script, code cấu hình clock và Makefile trước khi build firmware.

`config/FreeRTOSConfig.h` là cấu hình khởi đầu; Leader phải xác nhận tần số clock thực tế, port FreeRTOS và mức ưu tiên ngắt trước khi dùng.
