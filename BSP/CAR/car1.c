#include "./BSP/LED/led.h"
#include "./BSP/CAR/car1.h"


TIM_HandleTypeDef g_timx_pwmx_chy_handle;

void gtim_timx_pwmx_chy_init(uint16_t psc, uint16_t arr)
{
    g_timx_pwmx_chy_handle.Instance = TIM3;
    g_timx_pwmx_chy_handle.Init.Prescaler = psc;
    g_timx_pwmx_chy_handle.Init.Period = arr;
    g_timx_pwmx_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
    HAL_TIM_PWM_Init(&g_timx_pwmx_chy_handle);

    TIM_OC_InitTypeDef timx_oc_pwmx_chy;
    timx_oc_pwmx_chy.OCMode     = TIM_OCMODE_PWM1;
    timx_oc_pwmx_chy.Pulse      = 0;
    timx_oc_pwmx_chy.OCPolarity = TIM_OCPOLARITY_HIGH;

    HAL_TIM_PWM_ConfigChannel(&g_timx_pwmx_chy_handle, &timx_oc_pwmx_chy, TIM_CHANNEL_1);
    HAL_TIM_PWM_ConfigChannel(&g_timx_pwmx_chy_handle, &timx_oc_pwmx_chy, TIM_CHANNEL_2);

    HAL_TIM_PWM_Start(&g_timx_pwmx_chy_handle, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&g_timx_pwmx_chy_handle, TIM_CHANNEL_2);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    GPIO_InitTypeDef gpio_init_struct;

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_TIM3_CLK_ENABLE();
    gpio_init_struct.Pin   = GPIO_PIN_6 | GPIO_PIN_7;
    gpio_init_struct.Mode  = GPIO_MODE_AF_PP;
    gpio_init_struct.Pull  = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &gpio_init_struct);
}


