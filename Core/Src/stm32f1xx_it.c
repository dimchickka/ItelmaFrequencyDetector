/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>
#include "sensors.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern UART_HandleTypeDef huart2;
volatile uint32_t numberOfOverflow = 0;
volatile bool isFirstImpulse = true;
uint32_t capture_count = 0;
uint32_t total_frequency = 0;
bool isProcess = false;

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line1 interrupt.
  */
void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI1_IRQn 0 */
  /* USER CODE END EXTI1_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(button_Pin);
  /* USER CODE BEGIN EXTI1_IRQn 1 */

  /* USER CODE END EXTI1_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update interrupt.
  */
void TIM1_UP_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_IRQn 0 */
	// Обработчик переполнения
	if (__HAL_TIM_GET_FLAG(&htim1, TIM_FLAG_UPDATE)){
		__HAL_TIM_CLEAR_IT(&htim1, TIM_IT_UPDATE); //сброс флага
	  numberOfOverflow++;        // Увеличиваем счётчик
	  char msg[64];
	  int len = snprintf(msg, sizeof(msg), "Overflowed, %lu\r\n", numberOfOverflow);
	  HAL_UART_Transmit(&huart2, (uint8_t*)msg, len, HAL_MAX_DELAY);
	}

  /* USER CODE END TIM1_UP_IRQn 0 */
  //HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_IRQn 1 */

  /* USER CODE END TIM1_UP_IRQn 1 */
}

/**
  * @brief This function handles TIM1 capture compare interrupt.
  */
void TIM1_CC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_CC_IRQn 0 */
	// Обработчик захвата фронта
	if (__HAL_TIM_GET_FLAG(&htim1, TIM_FLAG_CC1)){
			 __HAL_TIM_CLEAR_IT(&htim1, TIM_IT_CC1); //если не сбросить флаг, прерывание будет срабатывать снова и снова — как только ты выйдешь из обработчика, оно снова вызовется
					if (isFirstImpulse) {
						isFirstImpulse = false;
					   __HAL_TIM_SET_COUNTER(&htim1, 0); // обнуляем таймер
		return;
		}

	if(capture_count < 11){
		uint32_t now = HAL_TIM_ReadCapturedValue(&htim1, TIM_CHANNEL_1);
		total_frequency += (72000000) / (72 * (now + 65536 * numberOfOverflow));
		__HAL_TIM_SET_COUNTER(&htim1, 0); // обнуляем таймер
		numberOfOverflow = 0; // сбрасываем после захвата
		capture_count++;
	}
	else{
		HAL_TIM_IC_Stop_IT(&htim1, TIM_CHANNEL_1);    // Остановить Input Capture + прерывание
		HAL_TIM_Base_Stop_IT(&htim1);                 // Остановить переполнение + прерывание
		__HAL_TIM_SET_COUNTER(&htim1, 0); // обнуляем таймер

		uint32_t frequency_average = total_frequency/capture_count;
		// Передаём частоту в UART
		char msg[64];
		int len = snprintf(msg, sizeof(msg), "10 Fronts detected!, Freq: %lu Hz\r\n", frequency_average);
		HAL_UART_Transmit(&huart2, (uint8_t*)msg, len, HAL_MAX_DELAY);

		numberOfOverflow = 0; // сбрасываем после захвата
		total_frequency = 0;
		capture_count = 0;
		isProcess = false;
		//current_sensor++;
		//handleMeasurements();
}
	    }
  /* USER CODE END TIM1_CC_IRQn 0 */
  //HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_CC_IRQn 1 */

  /* USER CODE END TIM1_CC_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_1 && !isProcess)
  {
	isProcess = true;
    HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);   // Включить захват
    HAL_TIM_Base_Start_IT(&htim1);                // Включить переполнение

    char msg[] = "Button is pressed\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, sizeof(msg) - 1, HAL_MAX_DELAY);
  }
}


//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//  if (GPIO_Pin == GPIO_PIN_1 && !isProcess)
//  {
//	  char msg[] = "Button is pressed\r\n";
//	  HAL_UART_Transmit(&huart2, (uint8_t*)msg, sizeof(msg) - 1, HAL_MAX_DELAY);
//	  isProcess = true;
//	  handleMeasurements();
//    }
//}



/* USER CODE END 1 */

