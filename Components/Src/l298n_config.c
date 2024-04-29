/**
  ******************************************************************************
  * @file     : l298n.c
  * @author   : AW    Adrian.Wojcik@put.poznan.pl
  * @version  : 1.0.0
  * @date     : Apr 29, 2024
  * @brief    : L298N driver
  *
  ******************************************************************************
  */

/* Private includes ----------------------------------------------------------*/
#include "l298n.h"
#include "main.h"
#include "tim.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/
L298N_Handle_TypeDef hdrive = {
    .ENA = PWM_INIT_HANDLE(&htim4, TIM_CHANNEL_3),
    .ENB = PWM_INIT_HANDLE(&htim4, TIM_CHANNEL_4),
    .IN1 = DIO_INIT_HANDLE(L298N_IN1),
    .IN2 = DIO_INIT_HANDLE(L298N_IN2),
    .IN3 = DIO_INIT_HANDLE(L298N_IN3),
    .IN4 = DIO_INIT_HANDLE(L298N_IN4)
};
/* Private function prototypes -----------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

