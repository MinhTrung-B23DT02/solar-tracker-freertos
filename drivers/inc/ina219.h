#ifndef INA219_H
#define INA219_H

typedef struct {
    float bus_voltage_v;
    float current_ma;
    float power_mw;
} INA219_Measurement_t;

int INA219_Init(void);
int INA219_ReadMeasurements(INA219_Measurement_t *measurement);

#endif /* INA219_H */
