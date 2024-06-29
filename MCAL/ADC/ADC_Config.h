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

/*
 * Result Adjustment Options :
 * ADC_ADLAR
 * ADC_ADRAR
 */
#define ADC_Result_Adjustment ADC_ADRAR

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
