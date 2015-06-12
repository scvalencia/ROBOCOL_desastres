/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : BrazoFrontalForwardPWM.h
**     Project     : ZZZ_Robocol
**     Processor   : MKL46Z256VLL4
**     Component   : PWM
**     Version     : Component 02.240, Driver 01.01, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-13, 19:34, # CodeGen: 26
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       71            |  LCD_P21/ADC0_SE15/TSI0_CH14/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0/I2S0_TXD0
**             ----------------------------------------------------
**
**         Timer name                  : TPM0_CNT [16-bit]
**         Counter                     : TPM0_CNT  [0x40038004]
**         Mode register               : TPM0_SC   [0x40038000]
**         Run register                : TPM0_SC   [0x40038000]
**         Prescaler                   : TPM0_SC   [0x40038000]
**         Compare register            : TPM0_C0V  [0x40038010]
**         Flip-flop register          : TPM0_C0SC [0x4003800C]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTC
**         Bit number (in port)        : 1
**         Bit mask of the port        : 0x0002
**         Port data register          : GPIOC_PDOR [0x400FF080]
**         Port control register       : GPIOC_PDDR [0x400FF094]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-[driven by slave component]
**             Clock                   : [driven by slave component] Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : ---        ---
**             microseconds            : 40         40
**             milliseconds            : ---        ---
**             seconds                 : ---        ---
**             seconds (real)          : 40         40
**
**     Contents    :
**         SetRatio16 - byte BrazoFrontalForwardPWM_SetRatio16(word Ratio);
**         SetDutyUS  - byte BrazoFrontalForwardPWM_SetDutyUS(word Time);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file BrazoFrontalForwardPWM.h
** @version 01.01
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup BrazoFrontalForwardPWM_module BrazoFrontalForwardPWM module documentation
**  @{
*/         

#ifndef __BrazoFrontalForwardPWM_H
#define __BrazoFrontalForwardPWM_H

/* MODULE BrazoFrontalForwardPWM. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PwmLdd3.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#define BrazoFrontalForwardPWM_PERIOD_VALUE PwmLdd3_PERIOD_VALUE /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define BrazoFrontalForwardPWM_PERIOD_VALUE_HIGH PwmLdd3_PERIOD_VALUE_0 /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */


/*
** ===================================================================
**     Method      :  BrazoFrontalForwardPWM_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define BrazoFrontalForwardPWM_SetRatio16(Ratio) (PwmLdd3_SetRatio16(PwmLdd3_DeviceData, Ratio))

/*
** ===================================================================
**     Method      :  BrazoFrontalForwardPWM_SetDutyUS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to 40 us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
#define BrazoFrontalForwardPWM_SetDutyUS(Time) (PwmLdd3_SetDutyUS(PwmLdd3_DeviceData, Time))

/* END BrazoFrontalForwardPWM. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __BrazoFrontalForwardPWM_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
