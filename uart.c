#include        "uart.h"
#define         GPIOAEN             (1U<<0)
#define         UART2EN             (1U<<17)  
#define         CR1_TE              (1U<<3)
#define         CR1_UE              (1U<<13)
#define         SR_TXE              (1U<<7)

#ifndef         SYS_FREQ
#define         SYS_FREQ            16000000
#endif

#ifndef         APB1_CLK
#define         APB1_CLK            SYS_FREQ
#endif

#ifndef         UART_BAUDRATE 
#define         UART_BAUDRATE       115200
#endif   

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

void uart2_write(int ch);

int _write(int file, char *ptr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        uart2_write(ptr[i]);
    }
    return len;
}

void uar2_tx_init(){
    /* configure uart gpio pin*/
    /*enable clock access to GPIOA*/
    RCC->AHB1ENR |= GPIOAEN;
    /*set PA2 to an alternate function mode*/
    GPIOA->MODER &= ~(1U<<4);
    GPIOA->MODER |= (1U<<5);
    /* set PA2 alternate function mode to UART TX (AF07)*/
    GPIOA->AFR[0] |= (1U<<8);
    GPIOA->AFR[0] |= (1U<<9);
    GPIOA->AFR[0] |= (1U<<10);
    GPIOA->AFR[0] &= ~(1U<<11);

    /*configure UART module*/
    /* enable clock access to UART2*/
    RCC->APB1ENR |= UART2EN;
    /*configure baudrate*/
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
    /*configure the transfer direction*/
    USART2->CR1 = CR1_TE; //we are not using the |= cause we want to clean the register so we will have the default parameters
    /*Enable uart module*/
    USART2->CR1 |= CR1_UE; 
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate){
    USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate){
    return ((PeriphClk)/BaudRate);
}

void uart2_write(int ch){
    /*Make sure the transmit data register is empty*/
    while(!(USART2->SR & SR_TXE)){  //waiting when the data register will be empty so we can write our information. Just a loop wor waiting
        
    }
    /*Write to transmit data register*/
    USART2->DR = (ch & 0xFF);
   
}