/*
 * adc.h   v1.0
 *
 * Contains functions to work with onboard adc
 * 
 * In this project adc is used to create random number
 *
 * T.Kuz    8.2024
 */
#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
void pa1_adc_init();
char adc_read();
void start_conversion();
#endif
