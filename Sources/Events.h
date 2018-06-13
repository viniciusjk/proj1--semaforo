/* ###################################################################
**     Filename    : Events.h
**     Project     : Semaforo
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-03-07, 20:21, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "LED_VERMELHO.h"
#include "BitIoLdd1.h"
#include "TIMER2.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "LED_AMARELO.h"
#include "BitIoLdd2.h"
#include "LED_VERDE.h"
#include "BitIoLdd3.h"
#include "LED_VERMELHO_PEDESTRE.h"
#include "BitIoLdd4.h"
#include "LED_VERDE_PEDESTRE.h"
#include "BitIoLdd5.h"
#include "BOTON.h"
#include "ExtIntLdd1.h"
#include "LDRConverter.h"
#include "AdcLdd1.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


/*
** ===================================================================
**     Event       :  TIMER2_OnInterrupt (module Events)
**
**     Component   :  TIMER2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TIMER2_OnInterrupt(void);

void BOTON_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  BOTON_OnInterrupt (module Events)
**
**     Component   :  BOTON [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LDRConverter_OnEnd(void);
/*
** ===================================================================
**     Event       :  LDRConverter_OnEnd (module Events)
**
**     Component   :  LDRConverter [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LDRConverter_OnCalibrationEnd(void);
/*
** ===================================================================
**     Event       :  LDRConverter_OnCalibrationEnd (module Events)
**
**     Component   :  LDRConverter [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
