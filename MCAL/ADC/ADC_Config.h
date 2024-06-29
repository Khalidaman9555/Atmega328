/*
 * ADC_Config.h
 *
 *  Created on: 22 Jun 2024
 *      Author: hp
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*
 * Voltage Reference Options:
 * ADC_VREF_AREF
 * ADC_VREF_AVCC
 * ADC_VREF_REV
 * ADC_VREF_I_AREF(1.1V)
 */
#define ADC_VoltReference ADC_VREF_AVCC

/*
 *  Options:-
 *   	 1-ADC_SINGLE_CONVERSION
 *   	 2-ADC_FREE_RUNNING
 *   	 3-ADC_ANALOG_COMPARATOR
 *   	 4-ADC_EXTI0
 *   	 5-ADC_TIM0_CTC
 *   	 6-ADC_TIM0_OVF
 *   	 7-ADC_TIM1_CTC_CHANNEL_B
 *   	 8-ADC_TIM1_OVF
 *   	 9-ADC_TIM1_ICU
 */
#define ADC_TRIGGERING_SOURCE   ADC_SINGLE_CONVERSION

/*
 * Prescaler options:
 * ADC_PS_2
 * ADC_PS_4
 * ADC_PS_8
 * ADC_PS_16
 * ADC_PS_32
 * ADC_PS_64
 * ADC_PS_128
 */
#define ADC_PS ADC_PS_128

#define  ADC_TIMEOUT      50000

/*
 * Result Adjustment Options :
 * ADC_ADLAR
 * ADC_ADRAR
 */
#define ADC_Result_Adjustment ADC_ADRAR

/*
 * Options:-
 *  1-ADC_ENABLE
 *  2-ADC_DISABLE
 */
#define ADC_STATUS   ADC_ENABLE

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
