#include <stm32f411xe.h>
#include "button.h"
#define     GPIOAEN      (1U<<0)
#define         PIN0            (1U<<0)
#define         BTN_PIN         PIN0

void button_init(){
   RCC->AHB1ENR |= GPIOAEN;
   /* Set PA0 as an input pin */
  GPIOA->MODER &= ~(1U<<0); 
  GPIOA->MODER &= ~(1U<<1); 
  /* set pull up resistor to button*/
  GPIOA->PUPDR |= (1U<<0);
  GPIOA->PUPDR &= ~(1U<<1);
}

int isbutton_clicked(){
    int isClicked = 0;
    for(int i = 100; i > 0; i++){
       if(isClicked == 1){
        return 1;
       }
       isClicked = (GPIOA->IDR & BTN_PIN);
    }
    return 0;
}
