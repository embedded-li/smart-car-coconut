#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/usart/usart.h"
#include "./BSP/LED/led.h"

#include <stdlib.h>
#include "./BSP/CAR/car1.h"
#include "./BSP/CAR/car2.h"
#include "./BSP/CAR/key.h"
#include "./BSP/CAR/li.h"

extern TIM_HandleTypeDef g_timx_pwmx_chy_handle;
typedef enum
{
	WAIT_KEY,    
  ACTION_RUN    	
}action_state_t;
int main(void)
{
    
	  action_state_t action_state  = WAIT_KEY;
	  uint8_t action_num = 0;
	  uint32_t action_start_tick = 0;
	  HAL_Init();                                 
    sys_stm32_clock_init(RCC_PLL_MUL9);        
    delay_init(72);                             
    led_init(); 
	  key0_init();
    usart_init(115200);
    gpiocar_init();
	  gtim_timx_pwmx_chy_init(72-1,1000-1);
    motor_set(0, 0);    
    while(1)
    {
       switch(action_state)
			 {
				 case WAIT_KEY:
				 {
					 if(key0_scan_once())
					 {
						 action_num++;
						 if(action_num > 4)
						 {
							 action_num = 1;
						 }
						 switch(action_num)
						 {
							 case 1:
							 {
								 motor_set(30,30);
								 break;
							 }
							 case 2:
							 {
								 motor_set(-30,-30);
								  break;
							 }
							 case 3:
							 {
								 motor_set(-30,30);//left			
                 break;								 
							 }
							 case 4:
							 {
								 motor_set(30,-30);//right
								 break;
							 }
						 }
						 action_start_tick = HAL_GetTick();
						 action_state = ACTION_RUN;
					 }
					 break;
				 }
				 case ACTION_RUN:
				 {
					 if(HAL_GetTick() - action_start_tick >= 2000)
					 {
						 motor_set(0,0);
						 action_state = WAIT_KEY;
					 }
					 break;
				 }				 
			 }								 
		}
}

