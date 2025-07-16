//#include "sensors.h"
//#include "stm32f1xx_hal.h"      // Основной HAL для вашего MCU (замените f1xx на вашу серию)
//#include "stm32f1xx_hal_tim.h"  // Специфичные для таймера функции
//#include <stdbool.h>
//#include "main.h"
//#include <stdio.h>
//
//extern TIM_HandleTypeDef htim1;
//extern uint32_t detectorNumber;
//extern volatile bool isProcess;
//
//
//const uint32_t IC_Channels[] = {
//    TIM_CHANNEL_1,
//    TIM_CHANNEL_2,
//    TIM_CHANNEL_3,
//    TIM_CHANNEL_4
//};
//
//
//void IC_Start() {
//    if (detectorNumber < NUMBER_OF_SENSORS) {
//        HAL_TIM_IC_Start_IT(&htim1, IC_Channels[detectorNumber]);
//        HAL_TIM_Base_Start_IT(&htim1);
//    }
//    else{
//    	isProcess = false;
//    }
//}
//
//void IC_Stop() {
//    if (detectorNumber < (uint32_t)NUMBER_OF_SENSORS) {
//        HAL_TIM_IC_Stop_IT(&htim1, IC_Channels[detectorNumber]);
//        HAL_TIM_Base_Stop_IT(&htim1);                 // Остановить переполнение
//        __HAL_TIM_SET_COUNTER(&htim1, 0); // обнуляем таймер
//    }
//}
