/*
 * ADC_Private.h
 *
 *  Created on: 22 Jun 2024
 *      Author: hp
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/* Bit Masking Macros  */
/* Bit Masking Macros  */
#define ADC_Pre_Mask				0b11111000
#define ADC_Ch_Mask			    0b11100000

#define ADC_DISABLE             0
#define ADC_ENABLE              1

/*ADMUX REGESTER BITS*/
#define ADC_ADCMUX_MUX0_BIT       0
#define ADC_ADCMUX_MUX1_BIT       1
#define ADC_ADCMUX_MUX2_BIT       2
#define ADC_ADCMUX_MUX3_BIT       3
#define ADC_ADCMUX_ADJUSTMENT_BIT 5
#define ADC_ADCMUX_REFS0_BIT 6
#define ADC_ADCMUX_REFS1_BIT 7

/*Prescaler select options*/ //Freq = F_CPU/Division Factor
#define ADC_PS_2    0
#define ADC_PS_4    2
#define ADC_PS_8    3
#define ADC_PS_16   4
#define ADC_PS_32   5
#define ADC_PS_64   6
#define ADC_PS_128  7

/*Result Adjustment select options*/
#define ADC_ADLAR 1
#define ADC_ADRAR 0

/*ADCSRA REGESTER BITS*/
#define ADC_ADCSRA_ADPS0 0
#define ADC_ADCSRA_ADPS1 1
#define ADC_ADCSRA_ADPS2 2
#define ADC_ADCSRA_ADIE  3
#define ADC_ADCSRA_ADIF  4
#define ADC_ADCSRA_ADATE 5
#define ADC_ADCSRA_ADSC  6
#define ADC_ADCSRA_ADEN  7

#define ADC_ADMUX_REG (*(volatile u8*) 0x7C)

#define ADC_ADCSRA_REG (*(volatile u8*) 0x7A)

/* Data Reg  */
#define ADC_ADCH_REG (*(volatile u8*) 0x79)
#define ADC_ADCL_REG (*(volatile u8*) 0x78)
#define ADC_DATA_RE  (*(volatile u16*)0x78)		//ADC Low + High

/* Values of the global var (ADC_u8ISRSource)  */
#define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH  1

#define ADC_SINGLE_CONVERSION   0
#define ADC_FREE_RUNNING        1
#define ADC_ANALOG_COMPARATOR   2
#define ADC_EXTI0               3
#define ADC_TIM0_CTC            4
#define ADC_TIM0_OVF            5
#define ADC_TIM1_CTC_CHANNEL_B  6
#define ADC_TIM1_OVF            7
#define ADC_TIM1_ICU            8

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
