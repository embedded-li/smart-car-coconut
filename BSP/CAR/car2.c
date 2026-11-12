#include "./BSP/CAR/car2.h"
#include "./BSP/CAR/car1.h"
#include "./BSP/LED/led.h"
#include "./SYSTEM/delay/delay.h"
#include <stdlib.h>

extern TIM_HandleTypeDef g_timx_pwmx_chy_handle;
void gpiocar_init()
{
	  GPIO_InitTypeDef gpio_init_struct;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    gpio_init_struct.Pin   = GPIO_PIN_1 | GPIO_PIN_4| GPIO_PIN_5| GPIO_PIN_8;
    gpio_init_struct.Mode  = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Pull  = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &gpio_init_struct);
	  __HAL_RCC_GPIOB_CLK_ENABLE();
	  gpio_init_struct.Pin = GPIO_PIN_13;
    HAL_GPIO_Init(GPIOB, &gpio_init_struct);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
}
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
	 if (left == 0 && right == 0)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
    }
}


