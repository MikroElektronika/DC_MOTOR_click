/*
    __dcmotor_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__dcmotor_driver.h"
#include "__dcmotor_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __DCMOTOR_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __DCMOTOR_DRV_SPI__

void dcmotor_spiDriverInit(T_DCMOTOR_P gpioObj, T_DCMOTOR_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __DCMOTOR_DRV_I2C__

void dcmotor_i2cDriverInit(T_DCMOTOR_P gpioObj, T_DCMOTOR_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __DCMOTOR_DRV_UART__

void dcmotor_uartDriverInit(T_DCMOTOR_P gpioObj, T_DCMOTOR_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void dcmotor_gpioDriverInit(T_DCMOTOR_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_anSet( 1 );
}

/* ----------------------------------------------------------- IMPLEMENTATION */


/* Enable the motor function */
void dcmotor_enable()
{
    hal_gpio_anSet( 1 );
}

/* Set sleep mode function */
void dcmotor_sleepMode()
{
    hal_gpio_anSet( 0 );
}

/* Select left direction, fast decay function */
void dcmotor_leftDirectionFast()
{
    hal_gpio_rstSet( 0 );
    hal_gpio_csSet( 0 );
}

/* Select right direction, fast decay function */
void dcmotor_rightDirectionFast()
{
    hal_gpio_rstSet( 0 );
    hal_gpio_csSet( 1 );
}

/* Select left direction, slow deca function */
void dcmotor_leftDirectionSlow()
{
    hal_gpio_rstSet( 1 );
    hal_gpio_csSet( 1 );
}

/* Select right direction, slow decay function */
void dcmotor_rightDirectionSlow()
{
    hal_gpio_rstSet( 1 );
    hal_gpio_csSet( 0 );
}

/* Get diagnostic function */
uint8_t dcmotor_getDiagnostic()
{
    return hal_gpio_intGet();
}




/* -------------------------------------------------------------------------- */
/*
  __dcmotor_driver.c

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