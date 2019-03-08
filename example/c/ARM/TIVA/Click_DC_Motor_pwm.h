#include "Click_DC_Motor_types.h"


uint32_t dcmotor_pwmInit( uint16_t freq )
{
    uint32_t pwmPeriod;
	
	pwmPeriod = PWM_T0CCP0_Init( freq, &_GPIO_MODULE_T0CCP0_D0_AHB );
	
	return pwmPeriod;
}

void dcmotor_pwmSetDuty( uint16_t duty )
{
    PWM_T0CCP0_Set_Duty( duty, _PWM_INVERTED_DISABLE );
}

void dcmotor_pwmStart()
{
    PWM_T0CCP0_Start();
}

void dcmotor_pwmStop()
{
    PWM_T0CCP0_Stop();
}