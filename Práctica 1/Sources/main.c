/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "Practica1_int.h"



T_UWORD ruw_AP0_1;

void delay_1s(void);


int main(void)
{
	E_LED led;
	ruw_AP0_1 = 0;
	p_Init();
	E_RANGES r=R_1_state,ant;
	int input [] = {100, 2000, 3562, 4092, 500, 60, 700, 8, 999, 1000, 11, 1200 };
	int n=0;
	for(;;) {	   
		ant = r;
		ruw_AP0_1 = input[n];
		if(ruw_AP0_1> 0 && ruw_AP0_1<928)
			r = R_1_state;
		else if(ruw_AP0_1>= 928 && ruw_AP0_1<1258)
			r = R_2_state;
		else if(ruw_AP0_1>=1258 && ruw_AP0_1 <=2518)
			r = R_3_state;
		else if(ruw_AP0_1 >2518 && ruw_AP0_1<=3708)
			r = R_4_state;
		else if(ruw_AP0_1>3078 && ruw_AP0_1 <=4095)
			r = R_5_state;
		
		
		delay_1s();
		p_manager();
		led = p_Get_LEDRangeValid();
		n++;
	}
	
	return 0;
}

void delay_1s(void){
	int cnt;
	for(cnt=0;cnt < 1000000; ++cnt);
}
