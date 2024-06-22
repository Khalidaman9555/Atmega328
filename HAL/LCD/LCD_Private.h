/*
 * LCD_Private.h
 *
 *  Created on: 18 Jun 2024
 *      Author: hp
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

//FUNCTION SET (8-BIT_MODE) Option Macros
#define LCD_u8_4_BITMODE 0x00
#define LCD_u8_8_BITMODE 0x10

#define LCD_u8_1_LINEMODE 0x00
#define LCD_u8_2_LINEMODE 0x08

#define LCD_u8_5x7_FONT 0x00
#define LCD_u8_5x10_FONT 0x04

//HALF-FUNCTION SET (4-BIT_MODE)
#define LCD_u84BIT_HALF_FUNCTION_SET 0x22

//DISPLAY ON/OFF Option Macros
#define LCD_u8_DisplayON 0x04
#define LCD_u8_DisplayOFF 0x00

#define LCD_u8_DispayCursor 0x02
#define LCD_u8_D_DispayCursor 0x00

#define LCD_u8_BlinkCursor 0x01
#define LCD_u8_D_BlinkCursor 0x00

//Entry Mode Set Option Macros
#define LCD_u8_Cursor_Increases 0x02
#define LCD_u8_Cursor_Decreases 0x00

#define LCD_u8_ShiftDisplay 0x01
#define LCD_u8_D_ShiftDisplay 0x00

// CLEAR DISPLAY
#define LCD_u8_ClearDisplay 0x01

#define LCD_u8Shift_Cur_Left   0x14
#define LCD_u8Shift_Cur_Right  0x10

#define LCD_u8ShiftAll_Left    0x1C
#define LCD_u8ShiftAll_Right   0x18

#define LCD_u8DDRAM_Offset     0x80

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
