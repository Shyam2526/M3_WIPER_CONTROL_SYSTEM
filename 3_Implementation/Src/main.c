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

int dum, dum1, dum2;										// Variable Init
uint8_t key=1;

int main(void)
{
	Gpio.pGPIOx = GPIOD;									//Set Port D Pin
	Gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;					//Selecting Pins
	Led_Pin_Init();
	Gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	Led_Pin_Init();
	Gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	Led_Pin_Init();
	Gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	Led_Pin_Init();
	Push_Button_Init();									//Init Push Button
	while(1)
	{

		//GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_0, DISABLE);
		if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))==ENABLE)			//Push Button Counts
		{
		if(key==1)
		{
			delay(2);
			delay(2);
			delay(2);
			delay(2);
			car_starts();								//Ignition starts: Push Button Press and Held for 2 seconds
				key++;

		}
		else if(key==2)
		{
			while(key==2){
			dum=wiper_led_On_Low();							//For Low Speed: Push Button Pressed Once
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
				dum1=wiper_led_On_Mid();					//For Medium Speed: Push Button Pressed Twice
				if(dum1==ENABLE)
				{
					key++;
					break;
				}
		}
		}
		else if(key == 4){
			while(key==4){
				dum2=wiper_led_On_High();					//For High Speed: Push Button Pressed Thrice
				if(dum2==ENABLE)
				{
					key++;
					break;
				}
			}
		}
		else if(key==5){
			wiper_led_Off();							//LED's OFF: Push Button Pressed for Fourth Time
			key++;
		}
		else if(key==6){
			//car_Off();
			if(car_Off() == ENABLE){						//Ignition OFF: Push Button Press and Held for 2 seconds
				delay(3);
				key = 1;
			}
		}
	}

	}
}

void delay(int sec){
	for(uint32_t i= 0; i < sec*Hz; i++);								// Set Delay
}

 void Led_Pin_Init(void)										//Init LED's
 {							
	Gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;						//Change LED pin as Output
	Gpio.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;						//Set Pull Up Mode
	GPIO_PeriClockControl(GPIOD, ENABLE);								//Enable Clock 
	GPIO_Init(&Gpio);										//Init Port 
 }

 void Push_Button_Init(void)
 {
		Gpio.pGPIOx = GPIOA;									//Select Port A
		Gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;					//Make Port A as Input
		GPIO_Init(&Gpio);									//Init Port A
 }

 void car_starts(void)
 {
	 GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);							//Red LED ON

}
int car_Off(void){

	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, DISABLE);						//Red LED OFF
	if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))==ENABLE){					
		 		//break;
		 		return 1;
		 	}
		 	else
		 		return 0;

}
int wiper_led_On_Low(void){										//LED's ON FOR LOW CONDITION
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);							//Blue LED ON
	delay(9);											//Low Delay 
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);						//Blue LED OFF
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);							//Green LED ON
	delay(9);											//Low Delay
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);						//Green LED OFF
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);							//Orange LED ON
	delay(9);											//Low Delay
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);						//Orange LED OFF
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);							//Green LED ON
	delay(9);											//Low Delay
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);						//Green LED OFF
	if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))==ENABLE){
		//break;
		return 1 ;
	}
	else
		return 0;
 }
int wiper_led_On_Mid(void)										//For Medium Speed
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
 int wiper_led_On_High(void)										//For High Speed
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
int wiper_led_Off(void)											//Turning OFF all LED's
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
