/*
 * DIO_Private.h
 *
 *  Created on: Jun 15, 2024
 *      Author: hp
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#define DIO_PORTB_REG ((volatile u8*) 0x25)
#define DIO_DDRB_REG  ((volatile u8*) 0x24)
#define DIO_PINB_REG  ((volatile u8*) 0x23)

#define DIO_PORTC_REG ((volatile u8*) 0x28)
#define DIO_DDRC_REG  ((volatile u8*) 0x27)
#define DIO_PINC_REG  ((volatile u8*) 0x26)

#define DIO_PORTD_REG ((volatile u8*) 0x2B)
#define DIO_DDRD_REG  ((volatile u8*) 0x2A)
#define DIO_PIND_REG  ((volatile u8*) 0x29)

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
