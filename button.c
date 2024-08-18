/*
 * button.c  v1.0
 *
 * module for checking button state
 *
 * T.Kuz    8.2024
 */
#include    <stm32f411xe.h>
#include    "button.h"
#define     GPIOAEN     (1U << 0)
#define     PIN0        (1U << 0)
#define     BTN_PIN     PIN0

void button_init()
{
    /* Enable clock access to GPIO A*/
    RCC->AHB1ENR |= GPIOAEN;
    /* Set PA0 as an input pin */
    GPIOA->MODER &= ~(1U << 0);
    GPIOA->MODER &= ~(1U << 1);
    /* Set pull up resistor to button*/
    GPIOA->PUPDR |= (1U << 0);
    GPIOA->PUPDR &= ~(1U << 1);
}

int isbutton_clicked()
{
    int isClicked = 0;
    /* Check state of button on the port by comparing bit mask*/
    isClicked = !(GPIOA->IDR & BTN_PIN);
    return isClicked;
}
