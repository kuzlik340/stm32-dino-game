#include        <stm32f411xe.h>
#include        "adc.h"
#define     ADC1EN          (1U<<8)
#define     GPIOAEN         (1U<<0)
#define     ADC_SEQ_LEN_1       0x00
#define     CR2_ADON        (1U<<0)
#define     CR2_SWSTART     (1U<<30)
#define     SR_EOC          (1U<<1)

//configure pa1 as our adc pin


void pa1_adc_init(){
    /***Configure the ADC GPIO pin ***/
    /*enable clock access to GPIOA*/
    RCC->AHB1ENR |= GPIOAEN;
    /*set the mode of pa1 to analog mode*/
    GPIOA->MODER |= (1U<<3);
    GPIOA->MODER |= (1U<<2);

    /***configure the ADC module***/
    /*enable clock access to adc module*/
    RCC->APB2ENR |= ADC1EN;
    /*conversion sequence start*/
    ADC1->SQR3 = (1U<<0);
    /*conversion sequence lenght*/
    ADC1->SQR1 = ADC_SEQ_LEN_1;
    /*enable ADC module*/
    ADC1->CR2 |= CR2_ADON;

}

void start_conversion(){
    /*start the adc conversion*/
    ADC1->CR2 |=CR2_SWSTART;

}

char adc_read(){
    /*wait for conversion to read*/
    while(!(ADC1->SR & SR_EOC));
    /*read coverted results*/
    return (ADC1->DR);
}