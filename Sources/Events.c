/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

	extern int estado;
	extern int flag_delay2;
	static int t = 0;
	extern int flag_delay3;
	extern int flag_delayPisca;
	extern int flag_Pisca;
	extern int flag_isButtonPressed;

/* User includes (#include below this line is not maintained by Processor Expert) */

void TIMER2_OnInterrupt(void)
{
	
	if (estado==2){
		t++;
		if (t>=10) { // 2 segundos
			flag_delay2 = 1;
			t = 0;
		}
	}
	
	else if (estado==3){
		t++;
		if (t>=17 && t<25){
			flag_delayPisca = 1;
			if (t%3 == 0){
				
				flag_Pisca = 1;
				
			}
			else {
				
				flag_Pisca = 0;
			}
		}
		if (t>=25) { // 5 segundos
			flag_delay3 = 1;
			flag_delayPisca = 0;
			t = 0;
		}
	}
	
	extern int isNightFlag;
	extern int thresholdNoite;
	extern int countNight;
	extern int countDay;
	extern int LDRMeasureInt;

	
	if (LDRMeasureInt>thresholdNoite){
		countNight++;
		 if (countNight>=8){
			 isNightFlag =1;
			 countDay = 0;
		 }
	}
	else{
		countDay++;
		countNight++;
		 if (countDay>=8){
			 isNightFlag =0;
			 countNight = 0;
		 }
	}
	
}

/*
void TIMER3_OnInterrupt(void)
{
	extern int estado;
	extern int flag_delay3;
	extern int flag_delayPisca;
	extern int flag_Pisca;
	static int t = 0;

	if (estado==3){
		t++;
		if (t>=35 && t<50){
			flag_delayPisca = 1;
			if (t%2 == 0){
				
				flag_Pisca = 1;
				
			}
			else {
				
				flag_Pisca = 0;
			}
		}
		if (t>=50) { // 5 segundos
			flag_delay3 = 1;
			flag_delayPisca = 0;
			t = 0;
		}
	}

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
/*void TIMER2_OnInterrupt(void)
{
  /* Write your code here ... */

/*
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
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

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
void BOTON_OnInterrupt(void)
{
	
	if (estado == 1){
		
		flag_isButtonPressed = 1;
	}
	
	else {
		
		flag_isButtonPressed = 0;
		
	}
}

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
void LDRConverter_OnEnd(void)
{
  /* Write your code here ... */
}

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
void LDRConverter_OnCalibrationEnd(void)
{
  /* Write your code here ... */
}


