#include "Click_DC_Motor_types.h"


uint32_t dcmotor_pwmInit( uint16_t freq )
{
    uint32_t pwmPeriod;
        
        pwmPeriod = PWM_TIM5_Init( freq );
        
        return pwmPeriod;
}

void dcmotor_pwmSetDuty( uint16_t duty )
{
    PWM_TIM5_Set_Duty( duty, _PWM_NON_INVERTED, _PWM_CHANNEL1 );
}

void dcmotor_pwmStart()
{
    PWM_TIM5_Start( _PWM_CHANNEL1, &_GPIO_MODULE_TIM5_CH1_PA0 );
}

void dcmotor_pwmStop()
{
    PWM_TIM5_Stop( _PWM_CHANNEL1 );
}