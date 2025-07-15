//#include "sensors.h"
//#include "stm32f1xx_hal.h"      // Основной HAL для вашего MCU (замените f1xx на вашу серию)
//#include "stm32f1xx_hal_tim.h"  // Специфичные для таймера функции
//#include "main.h"
//#include <stdio.h>
//
//volatile uint8_t current_sensor = 0;
//volatile bool is_first_sensor = true;
//extern bool isProcess;
//extern TIM_HandleTypeDef htim1;
//extern UART_HandleTypeDef huart2;
//
//SensorConfig sensors[NUM_SENSORS] = {
//	{GPIOA, GPIO_PIN_8, 0},   // Датчик 0: PA8 (TIM1_CH1)
//    {GPIOA, GPIO_PIN_4, 0},  // Датчик 1: PA4
//    {GPIOA, GPIO_PIN_5, 0},  // Датчик 2: PA5
//    {GPIOA, GPIO_PIN_6, 0},  // Датчик 3: PA6
//    {GPIOA, GPIO_PIN_7, 0},  // Датчик 4: PA7
//    {GPIOB, GPIO_PIN_0, 0},  // Датчик 5: PB0
//    {GPIOB, GPIO_PIN_1, 0},  // Датчик 6: PB1
//    {GPIOB, GPIO_PIN_2, 0}  // Датчик 7: PB2
//};
//
//void switchToSensor() {
//    GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//    // Сброс предыдущего пина
//	GPIO_InitStruct.Pin = sensors[current_sensor-1].pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//	HAL_GPIO_Init(sensors[current_sensor-1].port, &GPIO_InitStruct);
//
//    // Настройка нового пина
//    current_sensor = index;
//    GPIO_InitStruct.Pin = sensors[current_sensor].pin;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//
//    // Особые настройки для PA8 (TIM1_CH1)
//    if(sensors[current_sensor].pin == GPIO_PIN_8) {
//        GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
//    }
//
//    HAL_GPIO_Init(sensors[current_sensor].port, &GPIO_InitStruct);
//
//    // Очистка флагов и перезапуск
//    __HAL_TIM_SET_COUNTER(&htim1, 0);
//    __HAL_TIM_CLEAR_FLAG(&htim1, TIM_FLAG_CC1);
//    measurement_done = false;
//    HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
//}
//
//void handleMeasurements(){
//	if(is_first_sensor){
//		is_first_sensor = false;
//		// Остановка предыдущих измерений (если были)
//		    HAL_TIM_IC_Stop_IT(&htim1, TIM_CHANNEL_1);
//		    HAL_TIM_Base_Stop_IT(&htim1);
//
//		    // Старт измерений для датчика, который подключён к PA8, т.е. TIM1_CH1
//		    HAL_TIM_Base_Start_IT(&htim1);
//		    HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
//	}
//	else{
//		if(current_sensor < NUM_SENSORS){
//			switchToSensor();
//
//			// Отладочный вывод
//			char msg[64];
//			snprintf(msg, sizeof(msg), "Switched to sensor %d (Pin: P%c%d)\r\n",
//					 current_sensor-1,
//					 (sensors[current_sensor - 1].port == GPIOA) ? 'A' : 'B',
//					 __builtin_ctz(sensors[current_sensor].pin));
//			HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);
//
//
//			// Старт измерений для нового датчика
//			HAL_TIM_Base_Start_IT(&htim1);
//			HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
//		}
//
//		else{
//			current_sensor = 0;
//			is_first_sensor = true;
//			isProcess = false;
//		}
//	}
//}
