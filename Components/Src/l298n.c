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

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
/**
 * @brief TODO
 * param[inout] hl298n :
 * retval None
 */
void L298N_Init(L298N_Handle_TypeDef* hl298n)
{
  PWM_WriteDuty(&(hl298n->ENA), 0);
  PWM_Init(&(hl298n->ENA));
  DIO_WriteLow(&(hl298n->IN1));
  DIO_WriteLow(&(hl298n->IN2));

  PWM_WriteDuty(&(hl298n->ENB), 0);
  PWM_Init(&(hl298n->ENB));
  DIO_WriteLow(&(hl298n->IN3));
  DIO_WriteLow(&(hl298n->IN4));
}

/**
 * @brief TODO
 * param[inout] hl298n  :
 * param[in]    channel :
 * param[in]    dir     :
 * param[in]    duty    :
 * retval None
 */
void L298N_WriteDuty(L298N_Handle_TypeDef* hl298n, int channel, _Bool dir, float duty)
{
  if(channel == 0)
  {
    if(dir == 0)
    {
      DIO_WriteHigh(&(hl298n->IN1));
      DIO_WriteLow(&(hl298n->IN2));
    }
    else
    {
      DIO_WriteHigh(&(hl298n->IN2));
      DIO_WriteLow(&(hl298n->IN1));
    }
    PWM_WriteDuty(&(hl298n->ENA), duty);
  }
  if(channel == 1)
  {
    if(dir == 0)
    {
      DIO_WriteHigh(&(hl298n->IN3));
      DIO_WriteLow(&(hl298n->IN4));
    }
    else
    {
      DIO_WriteHigh(&(hl298n->IN4));
      DIO_WriteLow(&(hl298n->IN3));
    }
    PWM_WriteDuty(&(hl298n->ENB), duty);
  }
}
