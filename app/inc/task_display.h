#ifndef TASK_DISPLAY_H
#define TASK_DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

/* Khởi tạo Task Display */
void Task_Display_Init(void);

/* FreeRTOS Task function */
void Task_Display_Function(void *argument);

#ifdef __cplusplus
}
#endif

#endif /* TASK_DISPLAY_H */
