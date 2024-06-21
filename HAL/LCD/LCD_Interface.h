/*
 * LCD_Interface.h
 *
 *  Created on: 18 Jun 2024
 *      Author: hp
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#define LCD_u8PORTB 0
#define LCD_u8PORTC 1
#define LCD_u8PORTD 2

#define LCD_u8PIN0  0
#define LCD_u8PIN1  1
#define LCD_u8PIN2  2
#define LCD_u8PIN3  3
#define LCD_u8PIN4  4
#define LCD_u8PIN5  5
#define LCD_u8PIN6  6
#define LCD_u8PIN7  7

#define ShiftDRight 1
#define ShiftDLeft 0

#define LCD_u8Row1  0
#define LCD_u8Row2  0x40
#define LCD_u8Row3	0x14
#define LCD_u8Row4	0x54

#define LCD_u8Col1 0
#define LCD_u8Col2 1
#define LCD_u8Col3 2
#define LCD_u8Col4 3
#define LCD_u8Col5 4
#define LCD_u8Col6 5
#define LCD_u8Col7 6
#define LCD_u8Col8 7
#define LCD_u8Col9 8
#define LCD_u8Col10 9
#define LCD_u8Col11 10
#define LCD_u8Col12 11
#define LCD_u8Col13 12
#define LCD_u8Col14 13
#define LCD_u8Col15 14
#define LCD_u8Col16 15
#define LCD_u8Col17 0x10
#define LCD_u8Col18 0x11
#define LCD_u8Col19 0x12
#define LCD_u8Col20 0x13

#define PIN_OUTPUT 0

//Post built Configuration

/*While using 4-bit mode (D0->D3) will be neglected*/

typedef struct {
	u8 LCD_u8D4Port;
	u8 LCD_u8D4pin;
	u8 LCD_u8D5Port;
	u8 LCD_u8D5pin;
	u8 LCD_u8D6Port;
	u8 LCD_u8D6pin;
	u8 LCD_u8D7Port;
	u8 LCD_u8D7pin;

	u8 LCD_u8RSPort;
	u8 LCD_u8RSPin;
	u8 LCD_u8RWPort;
	u8 LCD_u8RWPin;
	u8 LCD_u8EPort;
	u8 LCD_u8EPin;
} LCD_stConfiguration;

void LCD_voidInit(LCD_stConfiguration *Copy_PstConfiguration);
void LCD_voidSendCommand(LCD_stConfiguration *Copy_PstConfiguration, u8 Copy_u8Command);
void LCD_voidSendCharacter(LCD_stConfiguration *Copy_PstConfiguration, u8 Copy_u8Character);

void LCD_voidClearDisplay(LCD_stConfiguration *Copy_PstConfiguration);

void LCD_voidSendString(LCD_stConfiguration *Copy_PstConfiguration, u8 *Copy_Pu8String);

u8 LCD_u8NumbertoChar(u8 Copy_u8Number);

void LCD_voidSetCur(LCD_stConfiguration *Copy_pstconfig, u8 Copy_u8Row, u8 Copy_u8Colum);

void LCD_voidShiftCurRight(LCD_stConfiguration *Copy_pstconfig);
void LCD_voidShiftCurLeft(LCD_stConfiguration *Copy_pstconfig);

void LCD_voidShiftScreenRight(LCD_stConfiguration *Copy_pstconfig);
void LCD_voidShiftScreenLeft(LCD_stConfiguration *Copy_pstconfig);

void LCD_voidSendString_Position(LCD_stConfiguration *Copy_pstconfig, u8 *Copy_pu8String, u8 Copy_u8Row, u8 Copy_u8Colum);

void LCD_voidSendCharacter_Position(LCD_stConfiguration *Copy_pstconfig, u8 Copy_u8Char, u8 Copy_u8Row, u8 Copy_u8Colum);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
