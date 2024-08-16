# Chrome Dino game based on STM32F411

## Introduction

**STM32 Dino Game** is a minimalist and fully functional recreation of the iconic Chrome dinosaur game, implemented entirely in C for STM32F411 microcontroller. The main idea of this project was to write this code without even standard libraries. So, only stm32f411xe was used. In this library are only predefined memory and nothing more.


## Functionality

The forecast-rp2040-station offers the following features:

- **Bitmap collision**: everytime the user jumps there will be call of function that will check if bitmaps were intersected or not
- **Updating display and dino bitmap**: I2C bus works on 400 kHz to provide smooth updating of all display. The update is done by sending the buffer array directly to display.

## Wiring


## How to run code
1. Download the code from this repository and open it in stm32CubeIDE
2. Check all wiring!
3. Run the code on your microcontroller :)

## Screens