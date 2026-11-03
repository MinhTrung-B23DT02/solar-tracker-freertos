#ifndef APP_CFG_H
#define APP_CFG_H

/* Stack sizes are expressed in FreeRTOS StackType_t words, not bytes. */
#define TASK_SENSOR_STACK_SIZE       (256U)
#define TASK_TRACKING_STACK_SIZE     (256U)
#define TASK_DISPLAY_STACK_SIZE      (384U)

#define TASK_SENSOR_PRIORITY         (2U)
#define TASK_TRACKING_PRIORITY       (3U)
#define TASK_DISPLAY_PRIORITY        (1U)

#define APP_SENSOR_PERIOD_MS         (100U)
#define APP_TRACKING_PERIOD_MS       (100U)
#define APP_DISPLAY_PERIOD_MS        (500U)

#define APP_LDR_DEADBAND             (30)
#define APP_SERVO_INITIAL_ANGLE      (90U)
#define APP_SERVO_STEP_DEG           (1U)
#define APP_SERVO_MIN_ANGLE          (0U)
#define APP_SERVO_MAX_ANGLE          (180U)

#endif /* APP_CFG_H */
