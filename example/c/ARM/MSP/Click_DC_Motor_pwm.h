#include "Click_DC_Motor_types.h"


uint32_t dcmotor_pwmInit( uint16_t freq )
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM0_Init( freq, _PWM_CFG_CLOCK_SRC_SMCLK | 
	                             _PWM_CFG_OUTPUTMODE_SET | 
								 _PWM_CFG_CHANNEL_4, 
								 &_GPIO_MODULE_PWM_TA0_4_A15 );
	
	return pwmPeriod;
}

void dcmotor_pwmSetDuty( uint16_t duty )
{
    PWM0_SetDuty( duty, _PWM_CFG_CHANNEL_4 );
}

void dcmotor_pwmStart()
{
    PWM0_Start();
}

void dcmotor_pwmStop()
{
    PWM0_Stop();
}