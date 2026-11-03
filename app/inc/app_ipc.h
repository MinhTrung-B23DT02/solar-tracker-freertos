#ifndef APP_IPC_H
#define APP_IPC_H

#include <stdint.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"

typedef struct {
    uint16_t ldr_left;
    uint16_t ldr_right;
} LDR_Data_t;

typedef struct {
    uint16_t servo_angle_deg;
    int16_t light_error;
    uint8_t tracking_active;
} Tracking_Status_t;

/* qLDR: Sensor -> Tracking; qStatus: Tracking -> Display.
 * xI2CMutex protects the shared INA219 + SSD1306 I2C bus.
 */
extern QueueHandle_t qLDR;
extern QueueHandle_t qStatus;
extern SemaphoreHandle_t xI2CMutex;

BaseType_t app_ipc_init(void);

#endif /* APP_IPC_H */
