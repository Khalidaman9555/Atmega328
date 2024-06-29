/*
 * ADC_Interface.h
 *
 *  Created on: 22 Jun 2024
 *      Author: hp
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

//Reference voltage selection options
#define ADC_VREF_AREF	  0 	//AREF, internal VREF turned of
#define ADC_VREF_AVCC	  1		//AV CC with external capacitor at AREF pin
#define ADC_VREF_REV 	  2		//Reserved
#define ADC_VREF_INV_AREF 3	//Internal 1.1V voltage reference with external capacitor at AREF pin

void ADC_voidInit(void);

void ADC_voidStartConv(u8 Copy_u8Channel, u16 *Copy_Pu16ReturnValue);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
