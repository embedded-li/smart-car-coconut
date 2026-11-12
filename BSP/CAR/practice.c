#include <stdlib.h>
void motor_set(int left, int right)
{
    if(left > 100)
		{
			left = 100;
		}
		else if(left < -100)
		{
			left = -100;
		}
		if(right > 100)
		{
			right = 100;
		}
		else if(right < -100)
		{
			right = -100;
		}
				    
    if (left > 0) 
		{
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    } 
		else if (left < 0) 
		{
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    } 
		else 
		{  
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    }
    
    if (right > 0) 
		{
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    } 
		else if (right < 0) 
		{
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
    } 
		else 
		{
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    }
		int ccr_l = abs(left) * 10;  
    int ccr_r = abs(right) * 10;

    __HAL_TIM_SET_COMPARE(&g_timx_pwmx_chy_handle, TIM_CHANNEL_1, ccr_l);
    __HAL_TIM_SET_COMPARE(&g_timx_pwmx_chy_handle, TIM_CHANNEL_2, ccr_r);
	 
}
int8_t out = 0;
	  int8_t err = 0;
	  uint32_t last_led_tick = 0;
	  uint32_t led_interval = 500;