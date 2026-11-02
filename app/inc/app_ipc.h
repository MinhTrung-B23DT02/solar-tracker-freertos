#ifndef APP_IPC_H
#define APP_IPC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/* FreeRTOS includes (Bỏ comment khi đã cấu hình FreeRTOS)
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
*/

/* Data structure for inter-task communication (IPC) */
typedef struct {
    float temperature;
    float humidity;
    uint32_t timestamp;
} sensor_data_msg_t;

/* Khởi tạo các hàng đợi (Queue), Semaphore, Mutex phục vụ IPC */
void App_IPC_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* APP_IPC_H */
