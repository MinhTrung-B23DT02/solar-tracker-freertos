#ifndef TASK_SENSOR_H
#define TASK_SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Khởi tạo Task Sensor */
void Task_Sensor_Init(void);

/* FreeRTOS Task function */
void Task_Sensor_Function(void *argument);

#ifdef __cplusplus
}
#endif

#endif /* TASK_SENSOR_H */
