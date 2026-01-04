#ifndef __KEY_H
#define __KEY_H

#include "main.h"
#include "tim.h"
#include "gpio.h"

typedef enum{
	KEY_UP,
	KEY_DEBOUNCE,
	KEY_WAIT
}KEY_STATE;

void LED(void);
void KeyScan(void);

#endif
