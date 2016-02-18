
/*!
 * $Source: Practica1.c $
 * $Revision: 1.0 $
 * $Author: Fill with team number $
 * $Date: 2015/08/26 22:53:07CEST $
 */


/* Includes */
/*============================================================================*/
#include "Practica1.h"
#include "Practica1_int.h"

/* Constants and types  */
/*============================================================================*/
typedef struct{
    T_UBYTE rub_aux1   : 2;
    T_UBYTE rub_aux2   : 2;
    T_UBYTE rub_aux3   : 2;
    T_UBYTE rub_aux4   : 2;
}S_AUX1;

typedef enum
{
    Aux1 = 0,
    Aux2,
    Aux3,
    Aux4
}E_AUX1;

typedef enum
{
    R_1_state    = 0,
    R_2_state    ,
    R_3_state    ,
    R_4_state    ,
    R_5_state    ,
    RANGES
}E_RANGES;

typedef enum
{
    Aux5,
    Aux6,
    Aux7,
    Aux8
}E_AUX2;

typedef enum
{
    Aux9,
    AuxA,
    AuxB,
    AuxC
}E_AUX3;

typedef struct
{
    T_UWORD ruw_aux1: 3;
    T_UWORD ruw_aux2: 3;
    T_UWORD ruw_aux3: 3;
    T_UWORD ruw_aux4: 1;
    T_UWORD ruw_aux5:12;
    T_UWORD ruw_aux6: 1;
    T_UWORD ruw_aux7: 1;
}S_AUX2;

/* Variables */
/*============================================================================*/
static T_UBYTE rub_color_LED;
static S_AUX2 rs_aux2;
static S_AUX1 rs_aux1;
static T_UBYTE rub_operative_counter;
static T_UBYTE rub_demature_timer;

/* Exported functions */
/*============================================================================*/
void p_Init(void);
void p_manager(void);
E_LED p_Get_LEDRangeValid(void);

/* Private functions prototypes */
/*============================================================================*/
static void p_random_Filtered(void);
static void p_Set_Color_LED(E_LED le_led);
static void p_load_counter(volatile T_UBYTE *lpub_counter, T_UBYTE lub_TIME);
static void p_stop_counter(volatile T_UBYTE *lpub_counter);
static T_UBYTE p_counter_is_expire(T_UBYTE lub_counter);
static T_UBYTE p_counter_is_stopped(T_UBYTE lub_counter);
static void p_decrement_counter(volatile T_UBYTE *lpub_counter);
static void p_f1(T_UBYTE lub_battery_filtered);
static void p_f2(T_UBYTE lub_battery_filtered);
static void p_f3(T_UBYTE lub_battery_filtered);
static void p_f4(void);

/* Private functions */
/*============================================================================*/
/**************************************************************
 *  Name                 :
 *  Description          :
 *  Parameters           :
 *  Return               :
 *  Critical/explanation :
 **************************************************************/
static void p_random_Filtered(void)
{
}

/**************************************************************
 *  Name                 : p_Set_Color_LED
 *  Description          : Update color led
 *  Parameters           : E_LED le_led:
 *  Return               : void
 *  Critical/explanation : No
 **************************************************************/
static void p_Set_Color_LED(E_LED le_led)
{
    rub_color_LED = le_led;
}

/**************************************************************
 *  Name                 : p_load_counter
 *  Description          : Load a counter with the correct value
 *  Parameters           : [Input] volatile T_UBYTE *lpub_counter (counter), T_UBYTElub_TIME (time for load)
 *  Return               : return void
 *  Critical/explanation : [Yes] Only works with T_UBYTE
 **************************************************************/
static void p_load_counter(volatile T_UBYTE *lpub_counter, T_UBYTE lub_TIME)
{
    *lpub_counter = lub_TIME;
}

/**************************************************************
 *  Name                 :
 *  Description          :
 *  Parameters           :
 *  Return               :
 *  Critical/explanation :
 **************************************************************/
static void p_stop_counter(volatile T_UBYTE *lpub_counter)
{
    *lpub_counter = COUNTER_STOPPED;
}

/**********************************************************************************************
 *  Name                 : p_counter_is_expire
 *  Description          : Function to check if the counter is not expire
 *  Parameters           : lub_counter (counter to analyze)
 *  Return               : BOOLEAN (TRUE: counter is 0x00, FALSE: counter is different to 0x00)
 *  Critical/explanation : [Yes] Only works with T_UBYTE
 *********************************************************************************************/
static T_UBYTE p_counter_is_expire(T_UBYTE lub_counter)
{
	return lub_counter == COUNTER_EXPIRE;
}

/**************************************************************
 *  Name                 : p_counter_is_stopped
 *  Description          : Function to check if the counter is not countering
 *  Parameters           : lub_counter (counter to analyze)
 *  Return               : BOOLEAN (TRUE: counter is 0xFF, FALSE: counter is different to 0xff)
 *  Critical/explanation : [Yes] Only works with T_UBYTE
 **************************************************************/
static T_UBYTE p_counter_is_stopped(T_UBYTE lub_counter)
{
	return lub_counter == COUNTER_STOPPED;
}

/**************************************************************
 *  Name                 : p_decrement_counter
 *  Description          : Function where the counter is decremented, it is only possible when the value is different to expire or stop
 *  Parameters           : *lpub_counter (punter to counter to decrement)
 *  Return               : void
 *  Critical/explanation : [Yes] Only works to T_UBYTE
 **************************************************************/
static void p_decrement_counter(volatile T_UBYTE *lpub_counter)
{
	if( !p_counter_is_stopped(*lpub_counter) && !p_counter_is_expire(*lpub_counter))
		*lpub_counter--;
}

/*********************************************************************************************
 *  Name                 :
 *  Description          : Auxiliar
 *  Parameters           :
 *  Return               :
 *  Critical/explanation :
 *********************************************************************************************/
static void p_f1(T_UBYTE lub_v_f1)
{
}

/*********************************************************************************************
 *  Name                 :
 *  Description          : Auxiliar
 *  Parameters           :
 *  Return               :
 *  Critical/explanation :
 *********************************************************************************************/
static void p_f2(T_UBYTE lub_v_f2)
{
}

/*********************************************************************************************
 *  Name                 :
 *  Description          : Auxliar
 *  Parameters           :
 *  Return               :
 *  Critical/explanation :
 *********************************************************************************************/
static void p_f3(T_UBYTE lub_v_f3)
{
}

/**************************************************************
 *  Name                 :
 *  Description          : Auxliar
 *  Parameters           :
 *  Return               :
 *  Critical/explanation :
 **************************************************************/
static void p_f4(void)
{
	//turn on the selected led
}


/* Exported functions */
/*============================================================================*/
/**************************************************************
 *  Name                 : p_Get_LEDRangeValid
 *  Description          : Return the current color
 *  Parameters           : void
 *  Return               : E_LED (Return the current color)
 *  Critical/explanation : [No]
 **************************************************************/
E_LED p_Get_LEDRangeValid(void)
{
    return rub_color_LED;
}


/**************************************************************
 *  Name                 : p_Init
 *  Description          : Function to initialize the variables
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_Init(void)
{
    p_Set_Color_LED(LED_OFF);
    p_stop_counter(&rub_operative_counter);
    p_stop_counter(&rub_demature_timer);
}


/**************************************************************
 *  Name                 : p_manager
 *  Description          : Run all the cyclic task for select the color
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [Yes] It must be call each 1s before ESCL manager
 **************************************************************/
void p_manager(void)
{
    p_random_Filtered();
    p_decrement_counter(&rub_operative_counter);
    p_decrement_counter(&rub_demature_timer);
    p_f4();
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */

