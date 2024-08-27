# Chrome Dino game based on STM32F411

## Introduction

**STM32 Dino Game** is a minimalist and fully functional recreation of the Chrome dinosaur game, implemented entirely in C for STM32F411 microcontroller. The main idea of this project was to write this code without even standard libraries. So, only stm32f411xe was used(this library conatins only predefined structures of registers in the stm32f411). 


## Wiring
On the blackpill v2.0 board we have the button that is connected to the PA0, so we will use this button with pull up resistors enabled on microcontroller. As I2C interface for the display we will use PB6 as SCL and PB7 as SDA.

## Project
All project is done by modules. I2c.h is used for transmitting data and commands to display by i2c bus. SSD1306.h has all the functions for showing bitmaps and pixels on display. Button.h contains function that is returning button state. Systick.h is used for the delay by microcontroller clock. Bitmaps.h have all the bitmaps that are used in this project

## How to run code
1. Download the code from this repository and open it in stm32CubeIDE
2. Check all wiring!
3. If you are using platfromio and as the board blackpill v.2.0 put in platformio.ini file this:
```
[env:blackpill_f411ce]
platform = ststm32
board = blackpill_f411ce
framework = stm32cube
upload_protocol = dfu
```
4. Run the code on your microcontroller :)

## Gameplay
After burning the board with code please reset it. Than there will be an intro for 1.2 seconds, and after you can play the dino game :) After death you should wait for 1.5 seconds and then you can respawn by clicking user button(button that is used for jumping).

## Screens
![IMG_3260 (1)](https://github.com/user-attachments/assets/18e70cb2-4bcf-48c3-ac7d-1bf50a464982)![IMG_3260 (2)](https://github.com/user-attachments/assets/8246c523-676a-4e4e-b7c4-e23afcda3287)
