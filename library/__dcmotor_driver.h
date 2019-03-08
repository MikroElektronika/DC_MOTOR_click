/*
    __dcmotor_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __dcmotor_driver.h
@brief    DC_Motor Driver
@mainpage DC_Motor Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   DCMOTOR
@brief      DC_Motor Click Driver
@{

| Global Library Prefix | **DCMOTOR** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _DCMOTOR_H_
#define _DCMOTOR_H_

/** 
 * @macro T_DCMOTOR_P
 * @brief Driver Abstract type 
 */
#define T_DCMOTOR_P    const uint8_t*

/** @defgroup DCMOTOR_COMPILE Compilation Config */              /** @{ */

//  #define   __DCMOTOR_DRV_SPI__                            /**<     @macro __DCMOTOR_DRV_SPI__  @brief SPI driver selector */
//  #define   __DCMOTOR_DRV_I2C__                            /**<     @macro __DCMOTOR_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __DCMOTOR_DRV_UART__                           /**<     @macro __DCMOTOR_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup DCMOTOR_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup DCMOTOR_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup DCMOTOR_INIT Driver Initialization */              /** @{ */

#ifdef   __DCMOTOR_DRV_SPI__
void dcmotor_spiDriverInit(T_DCMOTOR_P gpioObj, T_DCMOTOR_P spiObj);
#endif
#ifdef   __DCMOTOR_DRV_I2C__
void dcmotor_i2cDriverInit(T_DCMOTOR_P gpioObj, T_DCMOTOR_P i2cObj, uint8_t slave);
#endif
#ifdef   __DCMOTOR_DRV_UART__
void dcmotor_uartDriverInit(T_DCMOTOR_P gpioObj, T_DCMOTOR_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void dcmotor_gpioDriverInit(T_DCMOTOR_P gpioObj);
                                                                       /** @} */
/** @defgroup DCMOTOR_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Enable the motor function
 *
 * Function enable the motor
 * by set AN pin on DC Motor Click board.
 */
void dcmotor_enable();

/**
 * @brief Set sleep mode function
 *
 * Function set sleep mode the motor
 * by clear AN pin on DC Motor Click board.
 */
void dcmotor_sleepMode();

/**
 * @brief Select left direction, fast decay function
 *
 * Function select left direction, fast decay from MAX to MIN movement speed
 * by clear RST and CS pins on DC Motor Click board.
 */
void dcmotor_leftDirectionFast();

/**
 * @brief Select right direction, fast decay function
 *
 * Function select right direction, fast decay from MAX to MIN movement speed
 * by clear RST pin and set CS pins on DC Motor Click board.
 */
void dcmotor_rightDirectionFast();

/**
 * @brief Select left direction, slow decay function
 *
 * Function select left direction, slow decay from MIN to MAX movement speed
 * by sets RST and CS pins on DC Motor Click board.
 */
void dcmotor_leftDirectionSlow();

/**
 * @brief Select right direction, slow decay function
 *
 * Function select right direction, slow decay from MIN to MAX movement speed
 * by sets RST pin and clear CS pins on DC Motor Click board.
 */
void dcmotor_rightDirectionSlow();

/**
 * @brief Get diagnostic function
 *
 * @return
 * state of INT pin:
 * - 0 : FAULT conditions.
 * - 1 : OK conditions.
 *
 * Function get diagnostic by return state of the INT pin
 * on DC Motor Click board.
 */
uint8_t dcmotor_getDiagnostic();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_DC_Motor_STM.c
    @example Click_DC_Motor_TIVA.c
    @example Click_DC_Motor_CEC.c
    @example Click_DC_Motor_KINETIS.c
    @example Click_DC_Motor_MSP.c
    @example Click_DC_Motor_PIC.c
    @example Click_DC_Motor_PIC32.c
    @example Click_DC_Motor_DSPIC.c
    @example Click_DC_Motor_AVR.c
    @example Click_DC_Motor_FT90x.c
    @example Click_DC_Motor_STM.mbas
    @example Click_DC_Motor_TIVA.mbas
    @example Click_DC_Motor_CEC.mbas
    @example Click_DC_Motor_KINETIS.mbas
    @example Click_DC_Motor_MSP.mbas
    @example Click_DC_Motor_PIC.mbas
    @example Click_DC_Motor_PIC32.mbas
    @example Click_DC_Motor_DSPIC.mbas
    @example Click_DC_Motor_AVR.mbas
    @example Click_DC_Motor_FT90x.mbas
    @example Click_DC_Motor_STM.mpas
    @example Click_DC_Motor_TIVA.mpas
    @example Click_DC_Motor_CEC.mpas
    @example Click_DC_Motor_KINETIS.mpas
    @example Click_DC_Motor_MSP.mpas
    @example Click_DC_Motor_PIC.mpas
    @example Click_DC_Motor_PIC32.mpas
    @example Click_DC_Motor_DSPIC.mpas
    @example Click_DC_Motor_AVR.mpas
    @example Click_DC_Motor_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __dcmotor_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */