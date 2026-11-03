#include "app_ipc.h"

QueueHandle_t qLDR = NULL;
QueueHandle_t qStatus = NULL;
SemaphoreHandle_t xI2CMutex = NULL;

BaseType_t app_ipc_init(void)
{
    /* Queue length 1 keeps the newest measurement/status only. */
    qLDR = xQueueCreate(1U, sizeof(LDR_Data_t));
    qStatus = xQueueCreate(1U, sizeof(Tracking_Status_t));
    xI2CMutex = xSemaphoreCreateMutex();

    if ((qLDR == NULL) || (qStatus == NULL) || (xI2CMutex == NULL)) {
        if (qLDR != NULL) {
            vQueueDelete(qLDR);
            qLDR = NULL;
        }
        if (qStatus != NULL) {
            vQueueDelete(qStatus);
            qStatus = NULL;
        }
        if (xI2CMutex != NULL) {
            vSemaphoreDelete(xI2CMutex);
            xI2CMutex = NULL;
        }
        return pdFAIL;
    }

    return pdPASS;
}
