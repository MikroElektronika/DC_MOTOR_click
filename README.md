![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# DC_Motor Click

---

- **CIC Prefix**  : DCMOTOR
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Jan 2019.

---

### Software Support

We provide a library for the DC_Motor Click on our [LibStock](https://libstock.mikroe.com/projects/view/922/dc-motor-click-board) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control DC Motor Click board.
DC Motor Click communicates with the target board via PWM module.
This library contains drivers for moving in the left or right direction 
and from slow to the fast speed of rotation, enable the motor and set sleep mode function, 
for diagnostics and PWM function: initialization, for sets duty ratio, starts and stops PWM module.

Key functions :

- ``` void dcmotor_enable() ``` - Enable the motor function
- ``` void dcmotor_leftDirectionFast() ``` - Select left direction, fast decay function
- ``` void dcmotor_rightDirectionSlow() ``` - Select right direction, slow decay function

**Examples Description**

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


```.c

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

```

Additional Functions :

- uint32_t dcmotor_pwmInit( uint16_t freq ) - Initializes the Timer module in PWM mode.
- void dcmotor_pwmSetDuty( uint16_t duty ) - The function changes PWM duty ratio.
- void dcmotor_pwmStart() - Starts appropriate PWM module.
- void dcmotor_pwmStop() - Stops appropriate PWM module.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/922/dc-motor-click-board) page.

Other mikroE Libraries used in the example:

- PWM


**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
