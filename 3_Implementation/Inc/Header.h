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
GPIO_Handle_t Gpio;
void delay(int sec);
void Led_Pin_Init(void);
void Push_Button_Init(void);
int wiper_led_On_Low(void);
int wiper_led_On_Mid(void);
int wiper_led_On_High(void);
void car_starts(void);
int wiper_led_Off(void);
int car_Off(void);
