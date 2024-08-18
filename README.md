# Chrome Dino game based on STM32F411

## Introduction

**STM32 Dino Game** is a minimalist and fully functional recreation of the Chrome dinosaur game, implemented entirely in C for STM32F411 microcontroller. The main idea of this project was to write this code without even standard libraries. So, only stm32f411xe was used(this library conatins only predefined structures of registers in the stm32f411). 


## Wiring
On the blackpill v2.0 board we have the button that is connected to the PA0, so we will use this button with pull up resistors enabled on microcontroller. As I2C interface for the display we will use PB6 as SCL and PB7 as SDA.

## Project
All project is done by modules. i2c.h is used for transmitting data and commands to display by i2c bus. SSD1306.h has all the functions for showing bitmaps and pixels on display. button.h contains function that is returning button state. systick.h is used for the delay by microcontroller clock generator. bitmaps.h have all the bitmaps that are used in this project

## How to run code
1. Download the code from this repository and open it in stm32CubeIDE
2. Check all wiring!
3. Run the code on your microcontroller :)

## Screens