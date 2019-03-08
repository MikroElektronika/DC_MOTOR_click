#include "Click_DC_Motor_types.h"


uint32_t dcmotor_pwmInit( uint16_t freq )
{
	return 0;
}

void dcmotor_pwmSetDuty( uint16_t duty )
{
    PWM16bit_Init( _PWM16_PHASE_CORRECT_MODE_8BIT, 
	               _PWM16_PRESCALER_16bit_8, 
				   _PWM16_NON_INVERTED, duty, 1 );
}

void dcmotor_pwmStart()
{
    PWM16bit_Start( 1 );
}

void dcmotor_pwmStop()
{
    PWM16bit_Stop( 1 );
}