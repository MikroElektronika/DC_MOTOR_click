#include "Click_DC_Motor_types.h"


uint32_t dcmotor_pwmInit( uint16_t freq )
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM_Init( freq );
	
	return pwmPeriod;
}

void dcmotor_pwmSetDuty( uint16_t duty )
{
    PWM_ConfigChannel( duty,  _PWM_INIT_STATE_1, _PWM_CHANNEL_0 );
}

void dcmotor_pwmStart()
{
    PWM_EnableOutput();
}

void dcmotor_pwmStop()
{
    PWM_DisableOutput();
}