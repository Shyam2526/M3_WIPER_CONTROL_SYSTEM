# 1_REQUIREMENTS
## Features
* Easy way of control the Wiper System.
* Power Consumption of Board is less.
* less complexity.
* user friendly.
## Research
* Referred projects, based on External Led Blinking using Switches.
* Research about STM32F4 Discovery Board technical manual, References manual and STM32 Communities.
## Structural Block Diagram
![block](https://user-images.githubusercontent.com/101013448/168084494-01d61f39-8bca-4092-96c6-b7409e987de5.jpg)

## Behavioural Block Diagram
![Untitled Diagram (3)](https://user-images.githubusercontent.com/101013448/168089335-1ce41f5c-acf3-414c-b5c6-de151ea8c815.jpg)

## 4W's and 1-H
### WHAT
* Car Wiper is controlled by the wireless Push Button that process will be indicated by LED's.
### WHY
* To know the Wiper Control System principle and to vary the speeds depends on the user input.
### WHO
* People having the four wheelers can use it.
### WHERE
* This system used in car, lorry, trucks, etc to clean the spread of water in front glass.
### How
* Using STM32F407 Discovery Board, the wiper system controll is done 
## SWOT ANALYSIS
### STRENGTHS:
* Automation with no Human interaction
* User Friendly
* Platform Independant
* Safe and Secure
* Less complexity
### WEAKNESS:
* Software Bug's
* Traditional File System
### OPPORTUNITIES:
* Error Solving
* Standardized Process
* Getting Knowledge
### THREATS:
* Hardware issue
* File trashing
## Detail Requirements

### High Level Requirements:

|  ID   | Description | Status (Implemented/In Future) |
| ----- | ----------- | ------------------------------ |
| HLR 1 |     Wiper Control System State  |  Implemented  |
| HLR 2 |    Push Button pressed 2 second, Iginited RED led   | Implemented |
| HLR 3 |    Iginiton to start car | Implemented |
| HLR 4 |    LED Blinking using delay  | Implemented |

### Low Level Requirements:

|  ID   | Description | Status (Implemented/ In Future) |
| ----- | ----------- | ------------------------------- |
| LLR 1 |    Startup Code, Object Code, Linker Script and Executable Code  |  Implemented  |
| LLR 2 |    controlling the Leds with Delay | Implemented |
