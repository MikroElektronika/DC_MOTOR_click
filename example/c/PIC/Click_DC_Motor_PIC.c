/*
Example for DC_Motor Click

    Date          : Jan 2019.
    Author        : Nenad Filipovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO and LOG structures, sets AN, RST, CS, PWM pins as output
     and INT pin as input.
- Application Initialization - Initialization driver enable's - GPIO,
     PWM initialization, set PWM duty cycle and PWM frequency, enable the motor, start PWM and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of DC Motor Click board.
     DC Motor Click communicates with register via PWM interface.
     It shows moving in the left direction from slow to fast speed
     and moving in the right direction from fast to slow speed.
     Results are being sent to the Usart Terminal where you can track their changes.

Additional Functions :

- uint32_t dcmotor_pwmInit( uint16_t freq ) - Initializes the Timer module in PWM mode.
- void dcmotor_pwmSetDuty( uint16_t duty ) - The function changes PWM duty ratio.
- void dcmotor_pwmStart() - Starts appropriate PWM module.
- void dcmotor_pwmStop() - Stops appropriate PWM module.

*/

#include "Click_DC_Motor_types.h"
#include "Click_DC_Motor_config.h"
#include "Click_DC_Motor_pwm.h"


uint16_t dutyCycle = 100;
uint16_t frequency = 20000;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );

    mikrobus_logInit( _LOG_USBUART, 9600 );
    Delay_100ms();

    mikrobus_logWrite( "---------------------", _LOG_LINE );
    mikrobus_logWrite( "  DC Motor    Click  ", _LOG_LINE );
    mikrobus_logWrite( "---------------------", _LOG_LINE );
    mikrobus_logWrite( "Initialization System", _LOG_LINE );
    mikrobus_logWrite( "---------------------", _LOG_LINE );
}

void applicationInit()
{
    dcmotor_gpioDriverInit( (T_DCMOTOR_P)&_MIKROBUS1_GPIO );
    Delay_100ms();

    mikrobus_logWrite( " Initialization  PWM ", _LOG_LINE );
    dcmotor_pwmInit( frequency );
    dcmotor_pwmSetDuty( dutyCycle );
    dcmotor_enable();
    dcmotor_pwmStart();
    Delay_1sec();
    mikrobus_logWrite( "---------------------", _LOG_LINE );
}

void applicationTask()
{
    mikrobus_logWrite( "    Left Direction   ", _LOG_LINE );
    dcmotor_leftDirectionSlow();
    dcmotor_enable();
    Delay_1sec();

    for ( dutyCycle = 500; dutyCycle < 3000; dutyCycle += 250 )
    {
        dcmotor_pwmSetDuty( dutyCycle );
        mikrobus_logWrite( " <", _LOG_TEXT );
        Delay_1sec();
    }

    dcmotor_sleepMode();
    mikrobus_logWrite( "", _LOG_LINE );
    Delay_1sec();
    mikrobus_logWrite( "---------------------", _LOG_LINE );
    mikrobus_logWrite( "   Right Direction   ", _LOG_LINE );

    dcmotor_rightDirectionFast();
    dcmotor_enable();
    Delay_1sec();

    for ( dutyCycle = 500; dutyCycle < 3000; dutyCycle += 250 )
    {
        dcmotor_pwmSetDuty( dutyCycle );
        mikrobus_logWrite( " >", _LOG_TEXT );
        Delay_1sec();
    }

    mikrobus_logWrite( "", _LOG_LINE );
    mikrobus_logWrite( "---------------------", _LOG_LINE );
    dcmotor_sleepMode();
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}