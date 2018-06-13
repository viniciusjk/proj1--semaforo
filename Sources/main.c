
#include "Cpu.h"
#include "Events.h"
#include "LED_VERMELHO.h"
#include "BitIoLdd1.h"
#include "TIMER2.h"
#include "TimerIntLdd1.h"
#include "LED_VERDE_PEDESTRE.h"
#include "BitIoLdd5.h"
#include "LED_VERMELHO_PEDESTRE.h"
#include "BitIoLdd4.h"
#include "BOTON.h"
#include "ExtIntLdd1.h"
#include "LDRConverter.h"
#include "AdcLdd1.h"
#include "TIMER2.h"
#include "TU1.h"
#include "LED_AMARELO.h"
#include "BitIoLdd2.h"
#include "LED_VERDE.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "LDRConverter.h"

#define SEMAFORO_VERDE LED_VERMELHO_PutVal(0); LED_AMARELO_PutVal(0); LED_VERDE_PutVal(1);
#define SEMAFORO_AMARELO LED_VERMELHO_PutVal(0); LED_AMARELO_PutVal(1); LED_VERDE_PutVal(0);
#define SEMAFORO_VERMELHO LED_VERMELHO_PutVal(1); LED_AMARELO_PutVal(0); LED_VERDE_PutVal(0);
#define BOTON_PRESIONADO	0
#define BOTON_LIVRE		1
#define SEMAFORO_VERDE_PEDESTRE LED_VERMELHO_PEDESTRE_PutVal(0); LED_VERDE_PEDESTRE_PutVal(1);
#define SEMAFORO_VERMELHO_PEDESTRE LED_VERMELHO_PEDESTRE_PutVal(1); LED_VERDE_PEDESTRE_PutVal(0);



#define LDR_COUNTER					(4)


/* User includes (#include below this line is not maintained by Processor Expert)*/
int estado = 1;
int flag_delay2 = 0;
int flag_delay3= 0;
int flag_delayPisca= 0;
int flag_Pisca = 0;
int flag_isButtonPressed = 0;
static uint16_t LDRMeasure;
int thresholdNoite = 39985;
int LDRMeasureInt = 0;
int isNightFlag = 0;
int countNight = 0;
int countDay = 0;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
void main(void)
{

PE_low_level_init();


for(;;){
	LDRConverter_Measure(TRUE);
	LDRConverter_GetValue16(&LDRMeasure);
	LDRMeasureInt = LDRMeasure;
	
	
	if (isNightFlag==1){
		LED_VERMELHO_PutVal(0);
		LED_AMARELO_PutVal(0);		
		LED_VERDE_PutVal(0);
		LED_VERMELHO_PEDESTRE_PutVal(0);
		LED_VERDE_PEDESTRE_PutVal(0);
		
		if (countNight%2 == 0){
		LED_AMARELO_NegVal();
		LED_VERMELHO_PEDESTRE_NegVal();
		}
	}
	
	else if (isNightFlag ==0){
	//else if (countNight<=(countMax-4)){
		
	
	
	switch (estado){
	case 1:
		SEMAFORO_VERDE;
		SEMAFORO_VERMELHO_PEDESTRE;
	//if( flag_isButtonPressed == 1){
	if (BOTON_GetVal()==0){
		estado = 2;
		flag_isButtonPressed = 0;

} else{
	estado = 1;	
}

break;

	case 2:

	SEMAFORO_AMARELO;

	if(flag_delay2 == 0){
	
		estado =2;
	} 
	else {
	
		estado =3;
		flag_delay2 = 0;
			}

break;

case 3 :

	SEMAFORO_VERMELHO;
	
	if(flag_delay3 == 0 && flag_delayPisca == 0) {
	SEMAFORO_VERDE_PEDESTRE;
	estado =3;
      }
	else if(flag_delay3 == 0 && flag_delayPisca == 1){
		
		estado=3;
		SEMAFORO_VERMELHO_PEDESTRE;
		
		
		if (flag_Pisca == 1){
			
			LED_VERMELHO_PEDESTRE_PutVal(1);
		}
		
		else {
			
			LED_VERMELHO_PEDESTRE_PutVal(0);
		}
	}
	else {

		estado = 1;
		flag_delay3=0;
		flag_delayPisca= 0;
		flag_Pisca=0;
	}

	break;

	}
	
	}

}


#ifdef PEX_RTOS_START
	PEX_RTOS_START();


#endif

for(;;){}

  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
