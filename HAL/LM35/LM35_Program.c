/*
 * LM35_Program.c
 *
 *  Created on: Jun 27, 2024
 *      Author: hp
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "LM35_Interface.h"

void LM35_voidGetTemp(u8 Copy_u8LM35Channel, u32 *Copy_Pu16ReturnValue) {

	u16 Local_u16ADCResult;
	u16 Local_u16AnalogValue;

	u8 Local_u8ADCReference = (ADC_VREF_AVCC * 1000); // To Convert from ( V --> mV )

	ADC_voidInit ( );
	ADC_voidStartConv (Copy_u8LM35Channel , &Local_u16ADCResult);

	/* Check for ADC Resolution  */

	*Copy_Pu16ReturnValue = (u16) (((u32) Local_u16ADCResult * (u32) Local_u8ADCReference) / 512UL);

	/* Convert ( mv --> Temp ) */

}
