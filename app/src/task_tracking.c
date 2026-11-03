#include "task_tracking.h"
#include "task.h"
#include "app_cfg.h"
#include "app_ipc.h"
#include "hal_pwm.h"

static void prvTrackingTask(void *pvParameters)
{
    LDR_Data_t sample;
    Tracking_Status_t status = {
        .servo_angle_deg = APP_SERVO_INITIAL_ANGLE,
        .light_error = 0,
        .tracking_active = 0U
    };
    const TickType_t receive_timeout = pdMS_TO_TICKS(APP_TRACKING_PERIOD_MS);
    (void)pvParameters;

    (void)HAL_PWM_SetServoAngle(status.servo_angle_deg);

    for (;;) {
        if (xQueueReceive(qLDR, &sample, receive_timeout) == pdPASS) {
            status.light_error = (int16_t)sample.ldr_left - (int16_t)sample.ldr_right;
            status.tracking_active = 0U;

            if (status.light_error > APP_LDR_DEADBAND) {
                if (status.servo_angle_deg < APP_SERVO_MAX_ANGLE) {
                    status.servo_angle_deg += APP_SERVO_STEP_DEG;
                }
                status.tracking_active = 1U;
            } else if (status.light_error < -APP_LDR_DEADBAND) {
                if (status.servo_angle_deg > APP_SERVO_MIN_ANGLE) {
                    status.servo_angle_deg -= APP_SERVO_STEP_DEG;
                }
                status.tracking_active = 1U;
            }

            /* If the servo moves in the wrong direction on the real rig,
             * reverse the +/- angle adjustment after checking the mechanics.
             */
            (void)HAL_PWM_SetServoAngle(status.servo_angle_deg);
            (void)xQueueOverwrite(qStatus, &status);
        }
    }
}

BaseType_t task_tracking_create(void)
{
    return xTaskCreate(prvTrackingTask, "Tracking", TASK_TRACKING_STACK_SIZE,
                       NULL, TASK_TRACKING_PRIORITY, NULL);
}
