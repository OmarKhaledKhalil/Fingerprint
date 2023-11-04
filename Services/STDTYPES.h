/*
 * STD_TYPES.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Ezz Al-Qurtubi
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// Unsigned integer data types
typedef unsigned char               uint8 ;
typedef unsigned short              uint16 ;
typedef unsigned int                uint32 ;
typedef unsigned long long int      uint64 ;

// Signed integer data types
typedef signed char                 sint8 ;
typedef signed short                sint16 ;
typedef signed int                  sint32 ;
typedef signed long long int        sint64 ;

// volatile unsigned integer data types
typedef volatile unsigned char              vuint8 ;
typedef volatile unsigned short             vuint16 ;
typedef volatile unsigned int               vuint32 ;
typedef volatile unsigned long long int     vuint64 ;

// volatile signed integer data types
typedef volatile signed char                vsint8 ;
typedef volatile signed short               vsint16 ;
typedef volatile signed int                 vsint32 ;
typedef volatile signed long long int       vsint64 ;

// Float data types
typedef float       float32;
typedef double      float64;

// Boolean date types
typedef enum
{
	false,
	ture
}bool;

// Error types which used in ErrorIndication Function in any Default Case in Switch
typedef enum
{
	InvalidArgument,    //in any configuration to Pins or Ports
	OverFlow            //in any configuration to LEDs For Example
}ErrorType;

#define NULL_PTR ((void *)0)

#define TRUE			1
#define FALSE			0

#endif /* STD_TYPES_H_ */


