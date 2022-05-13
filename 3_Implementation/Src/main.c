#include "MyStm32f407xx.h"
#include "Header.h"
#include "MyStm32f407xx_gpio_driver.h"
uint8_t switching=0;
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
	while(1)
	{
		Push_Button_Init();
		//GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_0, DISABLE);
		if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)))
		{
		if(key==1)
		{
			car_starts();
			if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))){
				key++;
			}
		}
		else if(key==2)
		{
			while(key==2){
			wiper_led_On_Low();
			if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))){
				key++;
				break;
			}
			}
		}
		else if(key==3)
		{
			while(key==3){
				wiper_led_On_Mid();
			if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))){
				key++;
				break;
			}
		}
		}
		else if(key == 4){
			while(key==4){
				wiper_led_On_High();
			if((GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))){
				key++;
				break;
			}
			}
		}
		else if(key==5){
			wiper_led_Off();
		}
	}
		else
			car_off();
	}
}
void delay(uint32_t sec)
 {
	 for (uint32_t i = 0; i < sec*900000; i++);
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
void car_off(void){
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, DISABLE);
}
 void wiper_led_On_Low(void){
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay(150);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(150);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay(150);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(150);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
 }
 void wiper_led_On_Mid(void)
 {
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay(50);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(50);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay(50);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(50);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
 }
 void wiper_led_On_High(void)
 {
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay(5);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(5);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay(5);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(5);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
}
void wiper_led_Off(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay(50);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay(50);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, DISABLE);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay(50);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, DISABLE);
}
