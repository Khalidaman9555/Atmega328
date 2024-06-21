/*
 * DIO_Program.c
 *
 *  Created on: Jun 15, 2024
 *      Author: hp
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

volatile u8 *DIO_ArrPVu8_DDR[3] = { DIO_DDRB_REG , DIO_DDRC_REG , DIO_DDRD_REG };
volatile u8 *DIO_ArrPVu8_PORT[3] = {DIO_PORTB_REG , DIO_PORTC_REG , DIO_PORTD_REG };
volatile u8 *DIO_ArrPVu8_PIN[3] = { DIO_PINB_REG , DIO_PINC_REG , DIO_PIND_REG };

//Pin Level
void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	//check for the range
	if (Copy_u8Port <= PORTD && Copy_u8Pin <= PIN7) {
		//Only one check for the direction
		if (Copy_u8Direction == OUTPUT) {
			SET_BIT( *DIO_ArrPVu8_DDR[Copy_u8Port] , Copy_u8Pin);
		} else if (Copy_u8Direction == INPUT) {
			CLR_BIT( *DIO_ArrPVu8_DDR[Copy_u8Port] , Copy_u8Pin);
		} else {
			//Copy_u8Direction Neither OUTPUT Nor INPUT -> { DO NOTHING }.
		}
	} else {
		//Copy_u8Port Or Copy_u8Pin is out of the range -> { Do Noting }.
	}
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
	//check for the range
	if (Copy_u8Port <= PORTD && Copy_u8Pin <= PIN7) {
		//Only one check for the Value
		if (Copy_u8Value == HIGH) {
			SET_BIT( *DIO_ArrPVu8_PORT[Copy_u8Port] , Copy_u8Pin);
		} else if (Copy_u8Value == LOW) {
			CLR_BIT( *DIO_ArrPVu8_PORT[Copy_u8Port] , Copy_u8Pin);
		} else {
			//Copy_u8Value Neither HIGH Nor LOW -> { DO NOTHING }.
		}
	} else {
		//Copy_u8Port Or Copy_u8Pin is out of the range -> { Do Noting }.
	}
}

void DIO_voidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin) {
	//check for the range
	if (Copy_u8Port <= PORTD && Copy_u8Pin <= PIN7) {
		TOG_BIT( *DIO_ArrPVu8_PORT[Copy_u8Port] , Copy_u8Pin);
	} else {
		//Copy_u8Port Or Copy_u8Pin is out of the range -> { Do Noting }.
	}
}

void DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_Pu8Return) {
	//check for the range
	if (Copy_u8Port <= PORTD && Copy_u8Pin <= PIN7) {
		*Copy_Pu8Return = GET_BIT( *DIO_ArrPVu8_PIN[Copy_u8Port] , Copy_u8Pin);
	} else {
		//Copy_u8Port Or Copy_u8Pin is out of the range -> { Do Noting }.
	}
}

//Port Level
void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
	//check for the range
	if (Copy_u8Port <= PORTD) {
		//only one check for the Direction.
		if (Copy_u8Direction == OUTPUT) {
			*DIO_ArrPVu8_DDR[Copy_u8Port] = 0XFF;
		} else if (Copy_u8Direction == INPUT) {
			*DIO_ArrPVu8_DDR[Copy_u8Port] = 0X00;
		} else {
			//Copy_u8Direction Neither OUTPUT Nor INPUT -> { DO NOTHING }.
		}
	} else {
		//Copy_u8Port is out of the range -> { Do Noting }.
	}

}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {
	//check for the range
	if (Copy_u8Port <= PORTD && Copy_u8Value <= 0xFF) {
		//only one check for the Direction.
		if (Copy_u8Value == HIGH) {
			*DIO_ArrPVu8_PORT[Copy_u8Port] = 0XFF;
		} else if (Copy_u8Value == LOW) {
			*DIO_ArrPVu8_PORT[Copy_u8Port] = 0X00;
		} else {
			//Copy_u8Value Neither HIGH Nor LOW -> { SET The Value entered}.
			*DIO_ArrPVu8_PORT[Copy_u8Port] = Copy_u8Value;
		}
	} else {
		//Copy_u8Port or Copy_u8Value is out of the range -> { Do Noting }.
	}

}

void DIO_voidGetPortValue(u8 Copy_u8Port, u8 *Copy_Pu8Return) {
	//check for the range
	if (Copy_u8Port <= PORTD) {
		*Copy_Pu8Return = *DIO_ArrPVu8_PIN[Copy_u8Port];
	} else {
		//Copy_u8Port is out of the range -> { Do Noting }.
	}

}

//4 Bit Level
void DIO_voidSet4BitDirection(u8 Copy_u8Port, u8 Copy_u8FMOLSBit, u8 Copy_u8Direction)
{
	//check for the range
	if (Copy_u8Port <= PORTD) {
		if (Copy_u8FMOLSBit == FMOSTSBIT) {
			switch (Copy_u8Direction) {
				case OUTPUT:
					*DIO_ArrPVu8_DDR[Copy_u8Port] |= (0xF0); //ex:0000 1010 | 1111 0000 = 1111 1010
				break;
				case INPUT:
					*DIO_ArrPVu8_DDR[Copy_u8Port] &= (0x0F); //ex:1111 0101 & 0000 1111 = 0000 0101
				break;
				default:
				break;
			}
		} else if (Copy_u8FMOLSBit == FLEASTSBIT) {
			switch (Copy_u8Direction) {
				case OUTPUT:
					*DIO_ArrPVu8_DDR[Copy_u8Port] |= (0x0F); //ex:1010 1010 | 0000 1111 = 1010 1111
				break;
				case INPUT:
					*DIO_ArrPVu8_DDR[Copy_u8Port] &= (0xF0); //ex:0110 0101 & 1111 0000 = 0110 0000
				break;
				default:
				break;
			}
		} else {
			//Copy_u8FMOLSBit Neither FMOSTSBIT Nor FLEASTSBIT -> { DO NOTHING }.
		}

	} else {
		//Copy_u8Port is out of the range -> { Do Noting }.
	}
}

void DIO_voidSet4BitValue(u8 Copy_u8Port, u8 Copy_u8FMOLSBit, u8 Copy_u8Value) {
	//check for the range
	if (Copy_u8Port <= PORTD && Copy_u8Value <= 15) //EX:if(Copy_u8FMOLSBit==FMOSTSBIT)
	{                                //PORT=0110 0110 , Copy_u8Value=9=0000 1001
		if (Copy_u8FMOLSBit == FMOSTSBIT) //PORT=((PORT & 0x0F) | (Copy_u8Value<<4))
		{                      //PORT=   0000 0110   |    1001 0000  = 1001 0110
			*DIO_ArrPVu8_PORT[Copy_u8Port] = (( *(DIO_ArrPVu8_PORT[Copy_u8Port]) & (0x0F)) | (Copy_u8Value << 4));
		}
		//EX:if(Copy_u8FMOLSBit==FLEASTSBIT)
		else if (Copy_u8FMOLSBit == FLEASTSBIT) //PORT=1100 0100  ,  Copy_u8Value=9=0000 1001
												//PORT=((PORT & 0xF0) | (Copy_u8Value))
		{                      //PORT=   1100 0000   |    0000 1001  = 1100 1001
			*DIO_ArrPVu8_PORT[Copy_u8Port] = (( *(DIO_ArrPVu8_PORT[Copy_u8Port]) & (0xF0)) | (Copy_u8Value));
		} else {
			//Copy_u8FMOLSBit Neither FMOSTSBIT Nor FLEASTSBIT -> { DO NOTHING }.
		}

	} else {
		//Copy_u8Port or Copy_u8Value is out of the range -> { Do Noting }.
	}

}

void DIO_voidGet4BitValue(u8 Copy_u8Port, u8 Copy_u8FMOLSBit, u8 *Copy_Pu8Return)
{
	//check for the range
	if (Copy_u8Port <= PORTD) {
		if (Copy_u8FMOLSBit == FMOSTSBIT) {
			*Copy_Pu8Return = ( *(DIO_ArrPVu8_PIN[Copy_u8Port]) >> 4); //*Copy_Pu8Return=0101 1100 >> 4=0000 0101
		} else if (Copy_u8FMOLSBit == FLEASTSBIT) {
			*Copy_Pu8Return = ( *(DIO_ArrPVu8_PIN[Copy_u8Port]) & (0x0F)); //*Copy_Pu8Return=0101 1100 & 0x0F = 0000 1100
		} else {
			//Copy_u8FMOLSBit Neither FMOSTSBIT Nor FLEASTSBIT -> { DO NOTHING }.
		}

	} else {
		//Copy_u8Port is out of the range -> { Do Noting }.
	}

}

