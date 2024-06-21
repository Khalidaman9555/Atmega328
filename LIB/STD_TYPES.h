/*
 * STD_TYPES.h
 *
 *  Created on: June 15, 2024
 *      Author: hp
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

/*Pointer to Function*/
typedef void (*FUNC_PTR)(void);

#define NULL ((void*)0x00)

#endif /* LIB_STD_TYPES_H_ */
