/* 
 * File:   mcal_std_types.h
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:39 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/******************* Section 1 : Includes *******************/

#include "std_libraries.h"
#include "compiler.h"

/******************* Section 2 : Macros Declarations *******************/

#define STD_LOW                      0x00
#define STD_HIGH                     0x01

#define STD_OFF                      0x00
#define STD_ON                       0x01

#define STD_IDLE                     0x00
#define STD_ACTIVE                   0x01

#define CPU_TYPE_08                  0x08
#define CPU_TYPE_16                  0x10
#define CPU_TYPE_32                  0x20
#define CPU_TYPE_64                  0x40

#define CPU_TYPE                     (CPU_TYPE_08)

/******************* Section 3 : User Defined Data Types & Variables Declarations *******************/

#if (CPU_TYPE == CPU_TYPE_64)

/*************** CPU_TYPE_64 *******************/

typedef bool                    boolean;
typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed char             sint8;
typedef signed short            sint16;
typedef signed long             sint32;
typedef signed long long        sint64;

typedef float                   float32;
typedef double                  float64;
typedef long double             float128;

#define HWREG64(__X)            (*((volatile uint64 *)(__X)))

#elif (CPU_TYPE == CPU_TYPE_32)

/*************** CPU_TYPE_32 *******************/

typedef bool                    boolean;
typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed char             sint8;
typedef signed short            sint16;
typedef signed long             sint32;
typedef signed long long        sint64;

typedef float                   float32;
typedef double                  float64;
typedef long double             float128;

#define HWREG32(__X)            (*((volatile uint32 *)(__X)))

#elif (CPU_TYPE == CPU_TYPE_16)

/*************** CPU_TYPE_16 *******************/

typedef bool                    boolean;
typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed char             sint8;
typedef signed short            sint16;
typedef signed long             sint32;
typedef signed long long        sint64;

typedef float                   float32;
typedef double                  float64;
typedef long double             float128;

#define HWREG16(__X)            (*((volatile uint16 *)(__X)))

#elif (CPU_TYPE == CPU_TYPE_08)

/*************** CPU_TYPE_8 *******************/

typedef bool                    boolean;
typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed char             sint8;
typedef signed short            sint16;
typedef signed long             sint32;
typedef signed long long        sint64;

typedef float                   float32;
typedef double                  float64;
typedef long double             float128;

#define HWREG8(__X)            (*((volatile uint8 *)(__X)))

#else
#error
#endif

typedef enum{
    E_NOT_OK     = (uint8)0x00,
    E_OK         = (uint8)0x01
}Std_ReturnType;

#endif	/* MCAL_STD_TYPES_H */

