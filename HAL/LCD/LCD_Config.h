/*
 * LCD_Config.h
 *
 *  Created on: 18 Jun 2024
 *      Author: hp
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

//PRE-BUILT Configuration
/*
 * Function Set: 1-Data Length (DL)->DB4 : 8-bits : 1
 *                                       : 4-bits : 0
 *               2-No of Lines (N)->DB3 : 1-Lines : 0
 *                                      : 2-Lines : 1
 *               3-Character Font (F)->B2 : 5*7 Dots : 0
 *                                        : 5*10 Dots : 1
 */

/*
 * Options:
 * LCD_u8_4_BITMODE
 * LCD_u8_8_BITMODE
 */
#define LCD_u8_DATA_LENGTH LCD_u8_4_BITMODE

/*
 * Options:
 * LCD_u8_1_LINEMODE
 * LCD_u8_2_LINEMODE
 */
#define LCD_u8_NO_OF_LINES LCD_u8_2_LINEMODE

/*
 * Options:
 * LCD_u8_5x7_FONT
 * LCD_u8_5x10_FONT
 */
#define LCD_u8_FONT_Size  LCD_u8_5x7_FONT

#define LCD_u8_FUNCTION_SET ( 0x20 | LCD_u8_DATA_LENGTH | LCD_u8_NO_OF_LINES | LCD_u8_FONT_Size )

/*
 * Display ON/OFF Control: 1-DisplayScreen  (D)->DB2 : ON : 1
 *                                                   : OFF: 0
 *                         2-   Cursor      (C)->DB1 : Display : 1
 *                                                   : Don't Display : 0
 *                         3-CursorBlinking (B)->DB0 : Blink : 1
 *                                                   : Don't Blink : 0
 */

/*Options:
 * LCD_u8_DisplayON
 * LCD_u8_DisplayOFF
 */
#define LCD_u8_DisplayScreen LCD_u8_DisplayON

/*Options:
 * LCD_u8_DispayCursor
 * LCD_u8_D_DispayCursor
 */
#define LCD_u8_Cursor LCD_u8_DispayCursor

/*Options:
 * LCD_u8_BlinkCursor
 * LCD_u8_D_BlinkCursor
 */
#define LCD_u8_CursorMode LCD_u8_D_BlinkCursor

#define LCD_u8Display_ON_OFF (0x08 | LCD_u8_DisplayScreen | LCD_u8_Cursor | LCD_u8_CursorMode )

/*
 *Entry Mode Set: 1- Cursor Move Direction  (I/D)->DB1 : Increases: 1
 *                                                     : Decreases: 0
 *                2-Shift the Entire display (SH)->DB0 : Shift :1 ->To Right if(I/D=0)
 *                                                                ->To Left if(I/D=1)
 *                                                     : Don't Shift : 0
 */

/*Options:
 * LCD_u8_Cursor_Increases
 * LCD_u8_Cursor_Decreases
 */
#define LCD_u8_CursorDirection LCD_u8_Cursor_Increases

/*Options:
 * LCD_u8_ShiftDisplay
 * LCD_u8_D_ShiftDisplay
 */
#define LCD_u8_DisplayShiftMode LCD_u8_D_ShiftDisplay

#define LCD_u8_EntireModeSet (0x04 | LCD_u8_CursorDirection | LCD_u8_DisplayShiftMode )

#endif /* HAL_LCD_LCD_CONFIG_H_ */
