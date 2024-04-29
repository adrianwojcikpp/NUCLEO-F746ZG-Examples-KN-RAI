/**
  ******************************************************************************
  * @file     : l298n.h
  * @author   : AW    Adrian.Wojcik@put.poznan.pl
  * @version  : 1.0.0
  * @date     : Apr 29, 2024
  * @brief    : L298N driver
  *
  ******************************************************************************
  */

#ifndef INC_L298N_H_
#define INC_L298N_H_

/* Public includes -----------------------------------------------------------*/
#include "dio.h"
#include "pwm.h"

/* Public typedef ------------------------------------------------------------*/
typedef struct {
  PWM_Handle_TypeDef ENA;
  DIO_Handle_TypeDef IN1;
  DIO_Handle_TypeDef IN2;
  PWM_Handle_TypeDef ENB;
  DIO_Handle_TypeDef IN3;
  DIO_Handle_TypeDef IN4;
} L298N_Handle_TypeDef;

/* Public define -------------------------------------------------------------*/

/* Public macro --------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief TODO
 * param[inout] hl298n :
 * retval None
 */
void L298N_Init(L298N_Handle_TypeDef* hl298n);

/**
 * @brief TODO
 * param[inout] hl298n  :
 * param[in]    channel :
 * param[in]    dir     :
 * param[in]    duty    :
 * retval None
 */
void L298N_WriteDuty(L298N_Handle_TypeDef* hl298n, int channel, _Bool dir, float duty);

#endif /* INC_L298N_H_ */
