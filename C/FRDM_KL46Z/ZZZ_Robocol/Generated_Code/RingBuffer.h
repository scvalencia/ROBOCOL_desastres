/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : RingBuffer.h
**     Project     : ZZZ_Robocol
**     Processor   : MKL46Z256VLL4
**     Component   : RingBufferUInt8
**     Version     : Component 01.003, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-13, 19:34, # CodeGen: 26
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         Put             - byte RingBuffer_Put(byte elem);
**         Get             - byte RingBuffer_Get(byte *elemP);
**         NofElements     - byte RingBuffer_NofElements(void);
**         NofFreeElements - byte RingBuffer_NofFreeElements(void);
**         Init            - void RingBuffer_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file RingBuffer.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup RingBuffer_module RingBuffer module documentation
**  @{
*/         

#ifndef __RingBuffer_H
#define __RingBuffer_H

/* MODULE RingBuffer. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"


#define RingBuffer_BUF_SIZE   32  /* number of elements in the buffer */


byte RingBuffer_Put(byte elem);
/*
** ===================================================================
**     Method      :  RingBuffer_Put (component RingBufferUInt8)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte RingBuffer_Get(byte *elemP);
/*
** ===================================================================
**     Method      :  RingBuffer_Get (component RingBufferUInt8)
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte RingBuffer_NofElements(void);
/*
** ===================================================================
**     Method      :  RingBuffer_NofElements (component RingBufferUInt8)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void RingBuffer_Init(void);
/*
** ===================================================================
**     Method      :  RingBuffer_Init (component RingBufferUInt8)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

byte RingBuffer_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  RingBuffer_NofFreeElements (component RingBufferUInt8)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

/* END RingBuffer. */

#endif
/* ifndef __RingBuffer_H */
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
