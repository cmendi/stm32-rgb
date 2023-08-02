/* USER CODE BEGIN Header */

/*
 ________  ________        ___  ________          ________  _______   ________  ___  ________  ________   ________
|\   __  \|\   __  \      |\  \|\   __  \        |\   ___ \|\  ___ \ |\   ____\|\  \|\   ____\|\   ___  \|\   ____\
\ \  \|\ /\ \  \|\  \     \ \  \ \  \|\  \       \ \  \_|\ \ \   __/|\ \  \___|\ \  \ \  \___|\ \  \\ \  \ \  \___|_
 \ \   __  \ \   __  \  __ \ \  \ \   __  \       \ \  \ \\ \ \  \_|/_\ \_____  \ \  \ \  \  __\ \  \\ \  \ \_____  \
  \ \  \|\  \ \  \ \  \|\  \\_\  \ \  \ \  \       \ \  \_\\ \ \  \_|\ \|____|\  \ \  \ \  \|\  \ \  \\ \  \|____|\  \
   \ \_______\ \__\ \__\ \________\ \__\ \__\       \ \_______\ \_______\____\_\  \ \__\ \_______\ \__\\ \__\____\_\  \
    \|_______|\|__|\|__|\|________|\|__|\|__|        \|_______|\|_______|\_________\|__|\|_______|\|__| \|__|\_________\
                                                                        \|_________|                        \|_________|



 ________  ________  ___  ___  ________  ________  ________  ________  ________            _______      ________
|\   ____\|\   __  \|\  \|\  \|\   __  \|\   ___ \|\   __  \|\   __  \|\   ___  \         /  ___  \    |\   __  \
\ \  \___|\ \  \|\  \ \  \\\  \ \  \|\  \ \  \_|\ \ \  \|\  \ \  \|\  \ \  \\ \  \       /__/|_/  /|   \ \  \|\  \
 \ \_____  \ \  \\\  \ \  \\\  \ \   __  \ \  \ \\ \ \   _  _\ \  \\\  \ \  \\ \  \      |__|//  / /    \ \  \\\  \
  \|____|\  \ \  \\\  \ \  \\\  \ \  \ \  \ \  \_\\ \ \  \\  \\ \  \\\  \ \  \\ \  \         /  /_/__  __\ \  \\\  \
    ____\_\  \ \_____  \ \_______\ \__\ \__\ \_______\ \__\\ _\\ \_______\ \__\\ \__\       |\________\\__\ \_______\
   |\_________\|___| \__\|_______|\|__|\|__|\|_______|\|__|\|__|\|_______|\|__| \|__|        \|_______\|__|\|_______|
   \|_________|     \|__|
*/

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

	// EEPROM Flash address 0x08000000

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

	uint8_t sins[360] = {
		127,129,131,134,136,138,140,143,145,147,149,151,154,156,158,160,162,164,166,169,171,173,175,177,179,181,183,185,187,189,191,193,195,196,198,200,
		202,204,205,207,209,211,212,214,216,217,219,220,222,223,225,226,227,229,230,231,233,234,235,236,237,239,240,241,242,243,243,244,245,246,247,248,
		248,249,250,250,251,251,252,252,253,253,253,254,254,254,254,254,254,254,255,254,254,254,254,254,254,254,253,253,253,252,252,251,251,250,250,249,
		248,248,247,246,245,244,243,243,242,241,240,239,237,236,235,234,233,231,230,229,227,226,225,223,222,220,219,217,216,214,212,211,209,207,205,204,
		202,200,198,196,195,193,191,189,187,185,183,181,179,177,175,173,171,169,166,164,162,160,158,156,154,151,149,147,145,143,140,138,136,134,131,129,
		127,125,123,120,118,116,114,111,109,107,105,103,100,98,96,94,92,90,88,85,83,81,79,77,75,73,71,69,67,65,63,61,59,58,56,54,
		52,50,49,47,45,43,42,40,38,37,35,34,32,31,29,28,27,25,24,23,21,20,19,18,17,15,14,13,12,11,11,10,9,8,7,6,
		6,5,4,4,3,3,2,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,3,3,4,4,5,
		6,6,7,8,9,10,11,11,12,13,14,15,17,18,19,20,21,23,24,25,27,28,29,31,32,34,35,37,38,40,42,43,45,47,49,50,
		52,54,56,58,59,61,63,65,67,69,71,73,75,77,79,81,83,85,88,90,92,94,96,98,100,103,105,107,109,111,114,116,118,120,123,125
	};

    uint32_t led_off_tick;

  enum button_state_e {
      BUTTON_NOT_PRESSED,
      BUTTON_JUST_PRESSED,
      BUTTON_PRESSED
  };

  static enum button_state_e button_state = BUTTON_NOT_PRESSED;
  static uint8_t color_sequence = 0;



  void red_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  };

  void green_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 230); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  };

  void blue_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 230); // Blue
  };

  void pink_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 50); // Blue
  };

  void teal_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 230); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 230); // Blue
  };

  void yellow_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 140); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  };

  void orange_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 25); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  };

  void purple_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 100); // Blue
  };

  void white_sequence_full(void) {
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 230); // Red
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 230); // Green
  	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 230); // Blue
  };

  void party_sequence_full(void) {

      int i = 0;

      while (1) {
          for (i = 0; i < 360; i++) {
              __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, sins[i]); // Red
              __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, sins[(i + 120) % 360]); // Green
              __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, sins[(i + 240) % 360]); // Blue

              HAL_Delay(2);

              if (HAL_GPIO_ReadPin(Toggle_Switch_GPIO_Port, Toggle_Switch_Pin) != GPIO_PIN_SET)
                  return;
          }
      }
  };

  void red_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  }
  void green_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 115); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  }
  void blue_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 115); // Blue
  }
  void pink_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 25); // Blue
  }
  void teal_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 115); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 115); // Blue
  }
  void yellow_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 120); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  }
  void orange_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 13); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  }
  void purple_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 50); // Blue
  }
  void white_sequence_half() {
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 115); // Red
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 115); // Green
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 115); // Blue
  }

  void party_sequence_half(void) {

      int i = 0;

      while (1) {
          for (i = 0; i < 360; i++) {
              __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, sins[i] / 2); // Red
              __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, sins[(i + 120) % 360] / 2); // Green
              __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, sins[(i + 240) % 360] / 2); // Blue

              HAL_Delay(2);

              if (HAL_GPIO_ReadPin(Toggle_Switch_GPIO_Port, Toggle_Switch_Pin) != GPIO_PIN_SET)
                    return;
          }
      }
  };

  void switch_off_all_leds(void)
  {
      __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0); // Red
      __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0); // Green
      __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0); // Blue
  };

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	 bool pressed = (HAL_GPIO_ReadPin(Toggle_Switch_GPIO_Port, Toggle_Switch_Pin) == GPIO_PIN_SET);

	 if(HAL_GPIO_ReadPin(Main_input_GPIO_Port, Main_input_Pin) == GPIO_PIN_SET) {

	    switch (button_state)
	    {
	        case BUTTON_NOT_PRESSED:
	            if (pressed)
	                button_state = BUTTON_JUST_PRESSED;
	            break;


	        case BUTTON_JUST_PRESSED:
	            if (pressed)
	            {
	                button_state = BUTTON_PRESSED;

	                if ((HAL_GetTick() - led_off_tick) < 2000u)
	                    color_sequence = (color_sequence + 1) % 10;

	                switch (color_sequence) {

                    case 0:
                        red_sequence_full();
                        break;
                    case 1:
                        green_sequence_full();
                        break;
                    case 2:
                        blue_sequence_full();
                        break;
                    case 3:
                        pink_sequence_full();
                        break;
                    case 4:
                        teal_sequence_full();
                        break;
                    case 5:
                        yellow_sequence_full();
                        break;
                    case 6:
                        orange_sequence_full();
                        break;
                    case 7:
                        purple_sequence_full();
                        break;
                    case 8:
                        white_sequence_full();
                        break;
                    case 9:
                        party_sequence_full();
                        break;
	                }
	            }
	            else
	                button_state = BUTTON_NOT_PRESSED;
	            break;

	        case BUTTON_PRESSED:
	            if (!pressed)
	            {
	                button_state = BUTTON_NOT_PRESSED;
	                switch_off_all_leds();
	                led_off_tick = HAL_GetTick();
	            }
	            break;
	    }

	 } else {

		    switch (button_state)
		    {
		        case BUTTON_NOT_PRESSED:
		            if (pressed)
		                button_state = BUTTON_JUST_PRESSED;
		            break;


		        case BUTTON_JUST_PRESSED:
		            if (pressed)
		            {
		                button_state = BUTTON_PRESSED;

		                if ((HAL_GetTick() - led_off_tick) < 2000u)
		                    color_sequence = (color_sequence + 1) % 10;

		                switch (color_sequence) {

	                    case 0:
	                        red_sequence_half();
	                        break;
	                    case 1:
	                        green_sequence_half();
	                        break;
	                    case 2:
	                        blue_sequence_half();
	                        break;
	                    case 3:
	                        pink_sequence_half();
	                        break;
	                    case 4:
	                        teal_sequence_half();
	                        break;
	                    case 5:
	                        yellow_sequence_half();
	                        break;
	                    case 6:
	                        orange_sequence_half();
	                        break;
	                    case 7:
	                        purple_sequence_half();
	                        break;
	                    case 8:
	                        white_sequence_half();
	                        break;
	                    case 9:
	                        party_sequence_half();
	                        break;
		                }
		            }
		            else
		                button_state = BUTTON_NOT_PRESSED;
		            break;

		        case BUTTON_PRESSED:
		            if (!pressed)
		            {
		                button_state = BUTTON_NOT_PRESSED;
		                switch_off_all_leds();
		                led_off_tick = HAL_GetTick();
		            }

		            break;
		    }

	 }

	    HAL_Delay(10);

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
  HAL_GPIO_WritePin(Toggle_Switch_GPIO_Port, Toggle_Switch_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : Toggle_Switch_Pin */
  GPIO_InitStruct.Pin = Toggle_Switch_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Toggle_Switch_GPIO_Port, &GPIO_InitStruct);

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
