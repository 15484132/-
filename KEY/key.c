#include "key.h"

KEY_STATE KeyState = KEY_UP;
uint8_t KeyFlag = 0;

void KeyScan(void)
{
	switch(KeyState)
	{
		case KEY_UP:
		{
			if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin)==GPIO_PIN_RESET)
			{
				KeyState = KEY_DEBOUNCE;
			}			
			break;
		}
		case KEY_DEBOUNCE:
		{
			if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin)==GPIO_PIN_RESET)
			{
				KeyState = KEY_WAIT;	
				KeyFlag = 1;				
			}			
			else
			{
				KeyState = KEY_UP;
			}
			break;			
		}
		case KEY_WAIT:
		{
			if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin)==GPIO_PIN_SET)
			{
				KeyState = KEY_UP;
			}			
			break;
		}
		default:break;
	}
}

void LED(void)
{
	if(KeyFlag)
	{
		KeyFlag = 0;
		HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
	}
}


