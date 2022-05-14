/**
 ******************************************************************************
 * @file           : main.c
 * @author         : SHYAMKUMAR
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "MyStm32f407xx.h"
#include "Header.h"

#define Hz	10000000

int dum, dum1, dum2;
uint8_t key=1;

int main(void)
{
	Gpio.pGPIOx = GPIOD;
	Gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	Led_Pin_Init();
	Gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	Led_Pin_Init();
	Gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	Led_Pin_Init();
	Gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	Led_Pin_Init();
	Push_Button_Init();
	while(1)
	{

		//GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_0, DISABLE);
		if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))==ENABLE)
		{
		if(key==1)
		{
			delay(2);
			delay(2);
			delay(2);
			delay(2);
			car_starts();
				key++;

		}
		else if(key==2)
		{
			while(key==2){
			dum=wiper_led_On_Low();
			if(dum==ENABLE)
			{
				key++;
				break;
			}
			}
		}
		else if(key==3)
		{
			while(key==3){
				dum1=wiper_led_On_Mid();
				if(dum1==ENABLE)
				{
					key++;
					break;
				}
		}
		}
		else if(key == 4){
			while(key==4){
				dum2=wiper_led_On_High();
				if(dum2==ENABLE)
				{
					key++;
					break;
				}
			}
		}
		else if(key==5){
			wiper_led_Off();
			key++;
		}
		else if(key==6){
			//car_Off();
			if(car_Off() == ENABLE){
				delay(3);
				key = 1;
			}
		}
	}

	}
}

void delay(int sec){
	for(uint32_t i= 0; i < sec*Hz; i++);
}

 void Led_Pin_Init(void)
 {
	Gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpio.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&Gpio);
 }

 void Push_Button_Init(void)
 {
		Gpio.pGPIOx = GPIOA;
		Gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
		GPIO_Init(&Gpio);
 }

 void car_starts(void)
 {
	 GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);

}
int car_Off(void){

	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, DISABLE);
	if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))==ENABLE){
		 		//break;
		 		return 1;
		 	}
		 	else
		 		return 0;

}
int wiper_led_On_Low(void){
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay(9);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(9);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay(9);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(9);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))==ENABLE){
		//break;
		return 1 ;
	}
	else
		return 0;
 }
int wiper_led_On_Mid(void)
 {
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay(4);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(4);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay(4);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(4);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))==ENABLE){
		//break;
		return 1;
	}
	else
		return 0;
 }
 int wiper_led_On_High(void)
 {
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay(2);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(2);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay(2);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(2);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))==ENABLE){
		//break;
		return 1;
	}
	else
		return 0;
}
int wiper_led_Off(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay(8);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(8);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay(8);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);
	return 0;
}
