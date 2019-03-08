#include "Click_DC_Motor_types.h"


uint32_t dcmotor_pwmInit( uint16_t freq )
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM_Init( freq, 1, 1, 3 );
	
	return pwmPeriod;
}

void dcmotor_pwmSetDuty(uint16_t duty)
{
    PWM_Set_Duty( duty, 1 );
}

void dcmotor_pwmStart()
{
    PWM_Start( 1 );
}

void dcmotor_pwmStop()
{
    PWM_Stop( 1 );
}