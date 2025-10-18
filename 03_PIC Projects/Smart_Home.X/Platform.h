/* 
 * File:   Platform.h
 * Author: mohammedel-ahmady
 *
 * Created on October 17, 2025, 8:06 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef PLATFORM_H
#define	PLATFORM_H

/******************* Section 1 : Includes *******************/

#include "device_cfg.h"
#include "pic18f46k20.h"
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/******************* Section 2 : Macros Declarations *******************/

#define ZERO_INIT                           (uint8)0x00

#define BIT_MASK                            (uint8)0x01
#define PORT_MASK                           (uint8)0xFF

#define STD_LOW                             (uint8)0x00
#define STD_HIGH                            (uint8)0x01

#define STD_OFF                             (uint8)0x00
#define STD_ON                              (uint8)0x01

#define STD_IDLE                            (uint8)0x00
#define STD_ACTIVE                          (uint8)0x01

#define CPU_TYPE_08                         0x08 
#define CPU_TYPE_16                         0x10 
#define CPU_TYPE_32                         0x20
#define CPU_TYPE_64                         0x40

#define CPU_TYPE                            (CPU_TYPE_08)

/******************* Section 3 : User Defined Data Types & Variables Declarations *******************/

/*************** CPU_TYPE_64 *******************/
#if (CPU_TYPE == CPU_TYPE_64)

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

#define HWREG64(__X)             (*((volatile uint64 *)(__X)))

#define SET_BIT(REG, BIT_POS)               (REG |= (uint64)(BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG, BIT_POS)             (REG &= ~(uint64)(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG, BIT_POS)            (REG ^= (uint64)(BIT_MASK << BIT_POS))
#define READ_BIT(REG, BIT_POS)              ((REG >> BIT_POS) & (uint64)BIT_MASK)

/*************** CPU_TYPE_32 *******************/
#elif (CPU_TYPE == CPU_TYPE_32)

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

#define HWREG32(__X)             (*((volatile uint32 *)(__X)))

#define SET_BIT(REG, BIT_POS)               (REG |= (uint32)(BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG, BIT_POS)             (REG &= ~(uint32)(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG, BIT_POS)            (REG ^= (uint32)(BIT_MASK << BIT_POS))
#define READ_BIT(REG, BIT_POS)              ((REG >> BIT_POS) & (uint32)BIT_MASK)

/*************** CPU_TYPE_16 *******************/
#elif (CPU_TYPE == CPU_TYPE_16)

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

#define HWREG16(__X)             (*((volatile uint16 *)(__X)))

#define SET_BIT(REG, BIT_POS)               (REG |= (uint16)(BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG, BIT_POS)             (REG &= ~(uint16)(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG, BIT_POS)            (REG ^= (uint16)(BIT_MASK << BIT_POS))
#define READ_BIT(REG, BIT_POS)              ((REG >> BIT_POS) & (uint16)BIT_MASK)

/*************** CPU_TYPE_8 *******************/
#elif (CPU_TYPE == CPU_TYPE_08)

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

#define HWREG8(__X)                         (*((volatile uint8 *)(__X)))

#define SET_BIT(REG, BIT_POS)               (REG |= (uint8)(BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG, BIT_POS)             (REG &= ~(uint8)(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG, BIT_POS)            (REG ^= (uint8)(BIT_MASK << BIT_POS))
#define READ_BIT(REG, BIT_POS)              ((REG >> BIT_POS) & (uint8)BIT_MASK)

#else

#error

#endif

#endif	/* PLATFORM_H */

