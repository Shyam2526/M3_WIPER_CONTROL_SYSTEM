/**
 ******************************************************************************
 * @file           : main.c
 * @author         : SHYAMKUMAR
 * @brief          : Header program
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
GPIO_Handle_t Gpio;                                                   //Pointer for Structure
void delay(int sec);                                                  //Delay Function
void Led_Pin_Init(void);                                              //LED Configuration Function
void Push_Button_Init(void);                                          //Push Button Initializing
int wiper_led_On_Low(void);                                           //For Low Speed
int wiper_led_On_Mid(void);                                           //For Medium Speed
int wiper_led_On_High(void);                                          //For High Speed
void car_starts(void);                                                //Ignition ON
int wiper_led_Off(void);                                              //Turning OFF LED's
int car_Off(void);                                                    //Ignition OFF
