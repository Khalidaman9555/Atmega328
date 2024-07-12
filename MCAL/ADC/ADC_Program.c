/*
 * ADC_Program.c
 *
 *  Created on: 22 Jun 2024
 *      Author: hp
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/MACROS.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"

void ADC_voidInit(void) {

	/*1-Configuring Voltage Reference*/
	ADC_ADMUX_REG |= (ADC_VoltReference << ADC_ADCMUX_REFS0_BIT);

	/*Configure Result Adjustment*/
	ADC_ADMUX_REG |= (ADC_Result_Adjustment << ADC_ADCMUX_ADJUSTMENT_BIT);

	/*4-Set ADEN in ADCSRA REG*/
	SET_BIT(ADC_ADCSRA_REG , ADC_ADCSRA_ADEN);

	CLR_BIT(ADC_ADCSRA_REG , ADC_ADCSRA_ADATE);

	CLR_BIT(ADC_ADCSRA_REG , ADC_ADCSRA_ADIE);

	/*2-Configuring Prescaler*/
	ADC_ADCSRA_REG |= ADC_PS;

}

void ADC_voidStartConv(u8 Copy_u8Channel, u16 *Copy_Pu16ReturnValue) {

	if (Copy_u8Channel <= ADC_CHANNEL7) {

		ADC_ADMUX_REG &= 0xF0;
		// 1-Select the Channel
		ADC_ADMUX_REG |= Copy_u8Channel;
		//2-Set ADSC in ADCSRA REG to start conversion
		SET_BIT(ADC_ADCSRA_REG , ADC_ADCSRA_ADSC);
		//3-h3mal polling 3ala ADSC BIT law == 1 -> yb2a lesa by3mal conversion // law ==0 yb2a 5alas conversion
		while (GET_BIT(ADC_ADCSRA_REG , ADC_ADCSRA_ADSC)) {
			//busy wait -> wait for ADSC BIT to be zero (conversion ended)
#if ADC_Result_Adjustment==ADC_ADLAR
			*Copy_Pu16ReturnValue = (ADC_DATA_RE >> 6);
#elif ADC_Result_Adjustment==ADC_ADRAR
		*Copy_Pu16ReturnValue = (ADC_DATA_RE);
#endif
		}
	} else {
		//DO NOTHING
	}
}
