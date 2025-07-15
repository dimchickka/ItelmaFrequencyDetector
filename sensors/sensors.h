//#pragma once
//#include "stm32f1xx_hal.h"
//#include <stdbool.h>
//
//#define NUM_SENSORS 7   // сначала происходит измерение 8-го сенсора, который уже подключён к PA8 TIM1-CH1
//// эту переменную сделать 0, если мы работаем с одним датчиком
//
//extern volatile uint8_t current_sensor;
//extern volatile bool is_first_sensor;
//
//typedef struct {
//    GPIO_TypeDef* port;
//    uint16_t pin;
//    uint32_t measurement;
//} SensorConfig;
//
//void switchToSensor();
//void handleMeasurements();
