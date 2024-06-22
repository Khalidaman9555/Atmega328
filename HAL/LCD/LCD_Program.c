/*
 * LCD_Program.c
 *
 *  Created on: 18 Jun 2024
 *      Author: hp
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"LCD_Private.h"
#include"LCD_Config.h"
#include"LCD_Interface.h"
#include<util/delay.h>

void LCD_voidInit(LCD_stConfiguration *Copy_PstConfiguration) {

	/*Set Direction for DATA PORT*/
#if LCD_u8_DATA_LENGTH == LCD_u8_4_BITMODE
	DIO_voidSetPinDirection (Copy_PstConfiguration->LCD_u8D4Port , Copy_PstConfiguration->LCD_u8D4pin , OUTPUT);
	DIO_voidSetPinDirection (Copy_PstConfiguration->LCD_u8D5Port , Copy_PstConfiguration->LCD_u8D5pin , OUTPUT);
	DIO_voidSetPinDirection (Copy_PstConfiguration->LCD_u8D6Port , Copy_PstConfiguration->LCD_u8D6pin , OUTPUT);
	DIO_voidSetPinDirection (Copy_PstConfiguration->LCD_u8D7Port , Copy_PstConfiguration->LCD_u8D7pin , OUTPUT);
#endif

	/*Set Direction for RS Pin*/
	DIO_voidSetPinDirection (Copy_PstConfiguration->LCD_u8RSPort , Copy_PstConfiguration->LCD_u8RSPin , OUTPUT);
	/*Set Direction for RW Pin*/
	DIO_voidSetPinDirection (Copy_PstConfiguration->LCD_u8RWPort , Copy_PstConfiguration->LCD_u8RWPin , OUTPUT);
	/*Set Direction for E Pin*/
	DIO_voidSetPinDirection (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , OUTPUT);

	_delay_ms (50);

#if LCD_u8_DATA_LENGTH == LCD_u8_4_BITMODE

	/*LCD_voidSendCommand(Copy_PstConfiguration,LCD_u84BIT_HALF_FUNCTION_SET);
	 _delay_ms(1);
	 LCD_voidSendCommand(Copy_PstConfiguration, LCD_u8_FUNCTION_SET &~ (1<<PIN5));
	 _delay_ms(1);*/
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D4Port , Copy_PstConfiguration->LCD_u8D4pin , 0);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D5Port , Copy_PstConfiguration->LCD_u8D5pin , 1);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D6Port , Copy_PstConfiguration->LCD_u8D6pin , 0);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D7Port , Copy_PstConfiguration->LCD_u8D7pin , 0);

	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , HIGH);
	_delay_ms (2);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , LOW);

	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D4Port , Copy_PstConfiguration->LCD_u8D4pin , 0);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D5Port , Copy_PstConfiguration->LCD_u8D5pin , 1);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D6Port , Copy_PstConfiguration->LCD_u8D6pin , 0);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D7Port , Copy_PstConfiguration->LCD_u8D7pin , 0);

	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , HIGH);
	_delay_ms (2);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , LOW);

	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D4Port , Copy_PstConfiguration->LCD_u8D4pin , 0);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D5Port , Copy_PstConfiguration->LCD_u8D5pin , 0);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D6Port , Copy_PstConfiguration->LCD_u8D6pin , GET_BIT(LCD_u8_FUNCTION_SET , 2));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D7Port , Copy_PstConfiguration->LCD_u8D7pin , GET_BIT(LCD_u8_FUNCTION_SET , 3));

	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , HIGH);
	_delay_ms (2);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , LOW);

#endif

	/*Send Display ON/OFF  Command*/
	LCD_voidSendCommand (Copy_PstConfiguration , LCD_u8Display_ON_OFF);
	_delay_ms (2);
	/*Send ClearDisplay Command*/
	LCD_voidSendCommand (Copy_PstConfiguration , LCD_u8_ClearDisplay);
	_delay_ms (2);
	/*Send Entry Mode Set Command*/
	LCD_voidSendCommand (Copy_PstConfiguration , LCD_u8_EntireModeSet);

}

void LCD_voidSendCommand(LCD_stConfiguration *Copy_PstConfiguration, u8 Copy_u8Command)
{
	/*Clear RS & RW */
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8RSPort , Copy_PstConfiguration->LCD_u8RSPin , LOW);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8RWPort , Copy_PstConfiguration->LCD_u8RWPin , LOW);

#if LCD_u8_DATA_LENGTH == LCD_u8_4_BITMODE

	/*in 4 bit mode must send enable after every instruction or half instruction*/
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D4Port , Copy_PstConfiguration->LCD_u8D4pin , GET_BIT(Copy_u8Command , 4));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D5Port , Copy_PstConfiguration->LCD_u8D5pin , GET_BIT(Copy_u8Command , 5));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D6Port , Copy_PstConfiguration->LCD_u8D6pin , GET_BIT(Copy_u8Command , 6));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D7Port , Copy_PstConfiguration->LCD_u8D7pin , GET_BIT(Copy_u8Command , 7));
	_delay_ms (5);

//Enable after half instruction.
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , HIGH);
	_delay_ms (2);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , LOW);

	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D4Port , Copy_PstConfiguration->LCD_u8D4pin , GET_BIT(Copy_u8Command , 0));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D5Port , Copy_PstConfiguration->LCD_u8D5pin , GET_BIT(Copy_u8Command , 1));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D6Port , Copy_PstConfiguration->LCD_u8D6pin , GET_BIT(Copy_u8Command , 2));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D7Port , Copy_PstConfiguration->LCD_u8D7pin , GET_BIT(Copy_u8Command , 3));
	_delay_ms (5);

//Enable after half instruction.
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , HIGH);
	_delay_ms (2);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , LOW);

#endif

}

void LCD_voidSendCharacter(LCD_stConfiguration *Copy_PstConfiguration, u8 Copy_u8Character)
{
	/*SET RS & Clear RW */
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8RSPort , Copy_PstConfiguration->LCD_u8RSPin , HIGH);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8RWPort , Copy_PstConfiguration->LCD_u8RWPin , LOW);

#if LCD_u8_DATA_LENGTH == LCD_u8_4_BITMODE

	/*in 4 bit mode must send enable after every instruction or half instruction*/
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D4Port , Copy_PstConfiguration->LCD_u8D4pin , GET_BIT(Copy_u8Character , 4));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D5Port , Copy_PstConfiguration->LCD_u8D5pin , GET_BIT(Copy_u8Character , 5));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D6Port , Copy_PstConfiguration->LCD_u8D6pin , GET_BIT(Copy_u8Character , 6));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D7Port , Copy_PstConfiguration->LCD_u8D7pin , GET_BIT(Copy_u8Character , 7));
	_delay_ms (5);

	//Enable after half instruction.
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , HIGH);
	_delay_ms (2);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , LOW);

	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D4Port , Copy_PstConfiguration->LCD_u8D4pin , GET_BIT(Copy_u8Character , 0));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D5Port , Copy_PstConfiguration->LCD_u8D5pin , GET_BIT(Copy_u8Character , 1));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D6Port , Copy_PstConfiguration->LCD_u8D6pin , GET_BIT(Copy_u8Character , 2));
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8D7Port , Copy_PstConfiguration->LCD_u8D7pin , GET_BIT(Copy_u8Character , 3));
	_delay_ms (5);

	//Enable after half instruction.
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , HIGH);
	_delay_ms (2);
	DIO_voidSetPinValue (Copy_PstConfiguration->LCD_u8EPort , Copy_PstConfiguration->LCD_u8EPin , LOW);

#endif

}

void LCD_voidClearDisplay(LCD_stConfiguration *Copy_PstConfiguration) {
	LCD_voidSendCommand (Copy_PstConfiguration , LCD_u8_ClearDisplay);
	_delay_ms (20);
}

void LCD_voidSendString(LCD_stConfiguration *Copy_PstConfiguration, u8 *Copy_Pu8String)
{
	u8 i = 0;
	while (Copy_Pu8String[i] != '\0') {
		LCD_voidSendCharacter (Copy_PstConfiguration , Copy_Pu8String[i++]);
	}
}

u8 LCD_u8NumbertoChar(u8 Copy_u8Number) {
	return (Copy_u8Number + 0x30);
}

void LCD_voidSendu32Number(LCD_stConfiguration *Copy_pstconfig, u32 num) {
	u8 *str;
	u8 i = 0;

	// Handle the base case (number is 0)
	if (num == 0) {
		str[i++] = '0';
		str[i] = '\0';
		return;
	}

	// Find the number of digits
	long long int temp = num;
	while (temp != 0) {
		temp /= 10;
		i++;
	}

	// Reverse the digits and store them as characters
	str[i] = '\0'; // Null terminate the string
	while (num != 0) {
		int remainder = num % 10;
		str[--i] = remainder + '0'; // Convert digit to ASCII character
		num /= 10;
	}
	LCD_voidSendString (Copy_pstconfig , str);
}
void LCD_voidSendf32Number(LCD_stConfiguration *Copy_PstConfiguration, f32 Copy_f64Number)
{
	u8 dot_point_location = 0;
	u8 numstr[11] = { 0 };

	s32 I_intPart = (s32) Copy_f64Number;
	f32 I_floatPart = Copy_f64Number - I_intPart;

	snprintf (numstr , 6 , "%d" , I_intPart);

	while (numstr[dot_point_location] != '\0')
		++dot_point_location;

	numstr[dot_point_location++] = '.';

	numstr[dot_point_location++] = ((u32) (I_floatPart * 10) % 10) + '0';
	numstr[dot_point_location] = ((u32) (I_floatPart * 100) % 10) + '0';

	LCD_voidSendString (Copy_PstConfiguration , numstr);
}

void LCD_voidDelay1sec(void) {
	_delay_ms (1000);
}

void LCD_voidShiftCurRight(LCD_stConfiguration *Copy_pstconfig) {
	LCD_voidSendCommand (Copy_pstconfig , LCD_u8Shift_Cur_Right);
}
void LCD_voidShiftCurLeft(LCD_stConfiguration *Copy_pstconfig) {
	LCD_voidSendCommand (Copy_pstconfig , LCD_u8Shift_Cur_Left);
}

void LCD_voidShiftScreenRight(LCD_stConfiguration *Copy_pstconfig) {
	LCD_voidSendCommand (Copy_pstconfig , LCD_u8ShiftAll_Right);
}
void LCD_voidShiftScreenLeft(LCD_stConfiguration *Copy_pstconfig) {
	LCD_voidSendCommand (Copy_pstconfig , LCD_u8ShiftAll_Left);
}

void LCD_voidSetCur(LCD_stConfiguration *Copy_pstconfig, u8 Copy_u8Row, u8 Copy_u8Colum)
{
	if (Copy_pstconfig && Copy_u8Colum <= LCD_u8Col20 && Copy_u8Row <= LCD_u8Row4)
	{
		LCD_voidSendCommand (Copy_pstconfig , LCD_u8DDRAM_Offset | (Copy_u8Row + Copy_u8Colum));
	} else {
		/*empty*/
	}
}
void LCD_voidSendCharacter_Position(LCD_stConfiguration *Copy_pstconfig, u8 Copy_u8Char, u8 Copy_u8Row, u8 Copy_u8Colum)
{
	LCD_voidSetCur (Copy_pstconfig , Copy_u8Row , Copy_u8Colum);
	LCD_voidSendCharacter (Copy_pstconfig , Copy_u8Char);
}
void LCD_voidSendString_Position(LCD_stConfiguration *Copy_pstconfig, u8 *Copy_pu8String, u8 Copy_u8Row, u8 Copy_u8Colum)
{
	LCD_voidSetCur (Copy_pstconfig , Copy_u8Row , Copy_u8Colum);
	LCD_voidSendString (Copy_pstconfig , Copy_pu8String);
}

