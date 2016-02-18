/*!
 * $Source: Practica1_int.h $
 * $Revision: 1.0 $
 * $Author: Fill with team number $
 * $Date: 2015/08/26 22:53:15CEST $
 */

#ifndef PRACTICA1_INT_H
#define PRACTICA1_INT_H

typedef enum
{
    LED_OFF = 0,
    LED_BLUE,
    LED_RED,
    LED_GREEN,
    LED_WHITE,
    LED_TOOGLE
}E_LED;


/* Exported functions prototypes */
/*============================================================================*/
extern void p_Init(void);
extern void p_manager(void);
extern E_LED p_Get_LEDRangeValid(void);


#endif
