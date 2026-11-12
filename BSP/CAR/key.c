#include "./BSP/CAR/key.h"



void key0_init(void)
{
		GPIO_InitTypeDef gpio_init_struct;
	
   __HAL_RCC_GPIOE_CLK_ENABLE();
	
	gpio_init_struct.Pin =GPIO_PIN_4 ;
	gpio_init_struct.Mode=GPIO_MODE_INPUT;
	gpio_init_struct.Pull = GPIO_PULLUP ;	
	HAL_GPIO_Init(GPIOE,&gpio_init_struct);

}

uint8_t key0_scan_once(void)
{
	 static uint32_t last_change_tick = 0;   
   static uint8_t  last_raw   = 1;   
   static uint8_t  stable_level = 1;	
	 uint8_t raw = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4);
	
	 if(raw != last_raw)
	 {
		 	last_change_tick = HAL_GetTick();
		  last_raw = raw;
	 }
	 if(HAL_GetTick() - last_change_tick > 20)
	 {
		 if(raw != stable_level)
		 {
			 stable_level = raw;
			 if(stable_level == 1)
			 {
				 return 1;
			 }
		 }		 
	 }
	 return 0;
}


