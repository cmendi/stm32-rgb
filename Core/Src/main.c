/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); // Red
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); // Green
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); // Blue


  const int DEBOUNCE_DELAY = 400; // debounce delay in milliseconds
  uint32_t currentMillis;
  uint32_t lastPressTime = 0;
  int mode = 0;
  bool isOn = false;


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // Store the current Milliseconds to currentMillis variable
	  currentMillis = HAL_GetTick();

	  if (HAL_GPIO_ReadPin(Button_GPIO_Port, Button_Pin) == GPIO_PIN_SET) {

		  if(HAL_GetTick() - lastPressTime > DEBOUNCE_DELAY) {

			  if (!isOn) {

				  isOn = true;

			  } else {

				  mode++;

				  if(mode > 3) {

					  mode = 1;

				  }
			  }
		  }

	  } else if (HAL_GPIO_ReadPin(Main_input_GPIO_Port, Main_input_Pin) == GPIO_PIN_SET) {

	  	  if (isOn) {

			  if (mode == 1) {
				  // Red Final (230)
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
			  } else if (mode == 2) {
				  // Green Final (230)
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 230); // Green
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
			  } else if (mode == 3) {
				  // Blue Final (230)
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 230); // Blue
			  }
//				  // Pink Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 50); // Blue
//				  HAL_Delay(1000);
//				  // Teal Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 230); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 230); // Blue
//				  HAL_Delay(1000);
//				  // Yellow Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 140); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
//				  HAL_Delay(1000);
//				  // Orange Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 25); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
//				  HAL_Delay(1000);
//				  // Purple FInal (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 100); // Blue
//				  HAL_Delay(1000);
//				  // White Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 230); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 230); // Blue
//				  HAL_Delay(1000);
			  }

//			  else {
//				// Turn on LEDs brightness to 110 out of 255
//				  // Red Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
//				  HAL_Delay(1000);
//				  // Green Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 115); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
//				  HAL_Delay(1000);
//				  // Blue Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 115); // Blue
//				  HAL_Delay(1000);
//				  // Pink Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 25); // Blue
//				  HAL_Delay(1000);
//				  // Teal Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 115); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 115); // Blue
//				  HAL_Delay(1000);
//				  // Yellow Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 120); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
//				  HAL_Delay(1000);
//				  // Orange Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 13); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
//				  HAL_Delay(1000);
//				  // Purple FInal (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 50); // Blue
//				  HAL_Delay(1000);
//				  // White Final (230)
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 115); // Green
//				  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 115); // Blue
//				  HAL_Delay(1000);
//			  }
	  }


  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 255;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Button_GPIO_Port, Button_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : Button_Pin */
  GPIO_InitStruct.Pin = Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Main_input_Pin */
  GPIO_InitStruct.Pin = Main_input_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Main_input_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
