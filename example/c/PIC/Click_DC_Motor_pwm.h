#include "Click_DC_Motor_types.h"


uint32_t dcmotor_pwmInit( uint16_t freq )
{
    uint32_t pwmPeriod;
	
	PWM2_Init( 5000 );
	
	return 0;
}

void dcmotor_pwmSetDuty( uint16_t duty )
{
    PWM2_Set_Duty( duty );
}

void dcmotor_pwmStart()
{
    PWM2_Start();
}

void dcmotor_pwmStop()
{
    PWM2_Stop();
}