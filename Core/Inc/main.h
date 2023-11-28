/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Position_Pin GPIO_PIN_0
#define Position_GPIO_Port GPIOF
#define Turbine_Pin GPIO_PIN_1
#define Turbine_GPIO_Port GPIOF
#define Negatescope_Pin GPIO_PIN_0
#define Negatescope_GPIO_Port GPIOA
#define RS485DIR_Pin GPIO_PIN_1
#define RS485DIR_GPIO_Port GPIOA
#define RS485Tx_Pin GPIO_PIN_2
#define RS485Tx_GPIO_Port GPIOA
#define RS485Rx_Pin GPIO_PIN_3
#define RS485Rx_GPIO_Port GPIOA
#define WW_Pin GPIO_PIN_4
#define WW_GPIO_Port GPIOA
#define Right_Pin GPIO_PIN_5
#define Right_GPIO_Port GPIOA
#define Down_Pin GPIO_PIN_6
#define Down_GPIO_Port GPIOA
#define Up_Pin GPIO_PIN_7
#define Up_GPIO_Port GPIOA
#define Left_Pin GPIO_PIN_0
#define Left_GPIO_Port GPIOB
#define Bowl_Pin GPIO_PIN_1
#define Bowl_GPIO_Port GPIOB
#define Suction_Pin GPIO_PIN_8
#define Suction_GPIO_Port GPIOA
#define Glass_Pin GPIO_PIN_11
#define Glass_GPIO_Port GPIOA
#define Light_Pin GPIO_PIN_12
#define Light_GPIO_Port GPIOA
#define Buzzer_Pin GPIO_PIN_4
#define Buzzer_GPIO_Port GPIOB
#define Act_LED_Pin GPIO_PIN_5
#define Act_LED_GPIO_Port GPIOB
#define End_Pin GPIO_PIN_7
#define End_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define Status_LED_ON() HAL_GPIO_WritePin(Act_LED_GPIO_Port, Act_LED_Pin, GPIO_PIN_SET)
#define Status_LED_OFF() HAL_GPIO_WritePin(Act_LED_GPIO_Port, Act_LED_Pin, GPIO_PIN_RESET)

#define Buzzer_OFF() HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_SET)
#define Buzzer_ON() HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_RESET)

#define Light() HAL_GPIO_ReadPin(Light_GPIO_Port, Light_Pin)
#define Glass() HAL_GPIO_ReadPin(Glass_GPIO_Port, Glass_Pin)
#define Suction() HAL_GPIO_ReadPin(Suction_GPIO_Port, Suction_Pin)
#define Bowl() HAL_GPIO_ReadPin(Bowl_GPIO_Port, Bowl_Pin)
#define Up() HAL_GPIO_ReadPin(Up_GPIO_Port, Up_Pin)
#define Down() HAL_GPIO_ReadPin(Down_GPIO_Port, Down_Pin)
#define Left() HAL_GPIO_ReadPin(Left_GPIO_Port, Left_Pin)
#define Right() HAL_GPIO_ReadPin(Right_GPIO_Port, Right_Pin)
#define WarmWater() HAL_GPIO_ReadPin(WW_GPIO_Port, WW_Pin)
#define Negatoscope() HAL_GPIO_ReadPin(Negatescope_GPIO_Port, Negatescope_Pin)
#define End() HAL_GPIO_ReadPin(End_GPIO_Port, End_Pin)
#define Position() HAL_GPIO_ReadPin(Position_GPIO_Port, Position_Pin)
#define Turbine() HAL_GPIO_ReadPin(Turbine_GPIO_Port, Turbine_Pin)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
