/*
 * DIO_Interface.h
 *
 *  Created on: Jun 15, 2024
 *      Author: hp
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

//Pin Level
/*Name: DIO_voidSetPinDirection
 * Description:To set pin direction.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8Pin
 * @u8 Copy_u8Direction
 * Return: void
 */
void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/*Name: DIO_voidSetPinValue
 * Description:To set pin Value.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8Pin
 * @u8 Copy_u8Value
 * Return: void
 */
void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/*Name: DIO_voidTogglePinValue
 * Description:To toggle pin Value.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8Pin
 * Return: void
 */
void DIO_voidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

/*Name: DIO_voidGetPinValue
 * Description:To get pin Value.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8Pin
 * @u8* Copy_Pu8Return
 * Return: void
 */
void DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_Pu8Return);

//PORT level
/*Name: DIO_voidSetPortDirection
 * Description:To set port direction.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8Direction
 * Return: void
 */
void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);

/*Name: DIO_voidSetPortValue
 * Description:To set port value.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8Value
 * Return: void
 */
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);

/*Name: DIO_voidGetPortValue
 * Description:To get port value.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8* Copy_Pu8Return
 * Return: void
 */
void DIO_voidGetPortValue(u8 Copy_u8Port,u8* Copy_Pu8Return);

//4BIT level
/*Name: DIO_voidSet4BitDirection
 * Description:To set 4bit direction.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8FMOLSBit
 * @u8 Copy_u8Direction
 * Return: void
 */
void DIO_voidSet4BitDirection(u8 Copy_u8Port,u8 Copy_u8FMOLSBit,u8 Copy_u8Direction);

/*Name: DIO_voidSet4BitValue
 * Description:To set 4bit value.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8FMOLSBit
 * @u8 Copy_u8Value
 * Return: void
 */
void DIO_voidSet4BitValue(u8 Copy_u8Port,u8 Copy_u8FMOLSBit,u8 Copy_u8Value);

/*Name: DIO_voidGet4BitValue
 * Description:To get 4bit value.
 * Inputs:
 * @u8 Copy_u8Port
 * @u8 Copy_u8FMOLSBit
 * @u8* Copy_Pu8Return
 * Return: void
 */
void DIO_voidGet4BitValue(u8 Copy_u8Port,u8 Copy_u8FMOLSBit,u8* Copy_Pu8Return);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
