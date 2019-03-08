#include "Click_DC_Motor_types.h"


uint32_t dcmotor_pwmInit( uint16_t freq )
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM0_Init( freq );
	
	return pwmPeriod;
}

void dcmotor_pwmSetDuty( uint16_t duty )
{
    PWM0_Set_Duty( duty, _PWM_NON_INVERTED );
}

void dcmotor_pwmStart()
{
    PWM0_Start();
}

void dcmotor_pwmStop()
{
    PWM0_Stop();
}