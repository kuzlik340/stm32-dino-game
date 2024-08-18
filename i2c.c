/*
 * i2c.c  v1.0
 *
 * module for I2C transmission
 *
 * T.Kuz    8.2024
 */

#include <stm32f411xe.h>
#define GPIOBEN (1U << 1)
#define I2C1EN (1U << 21)
#define I2C_100KHZ 80
#define I2C_400KHZ 13
#define SD_MODE_MAX_RISE_TIME 9
#define SR2_BUSY (1U << 1)
#define CR1_START (1U << 8)
#define SR1_SB (1U << 0)
#define SR1_ADDR (1U << 1)
#define SR1_TXE (1U << 7)
#define CR1_ACK (1U << 10)
#define CR1_STOP (1U << 9)
#define SR1_RXNE (1U << 6)
#define SR1_BTF (1U << 2)

/*
 * PB6 --- SCL
 * PB7 --- SDA
 */

void i2c_init()
{
    /*enable clock acces to GPIOB*/
    RCC->AHB1ENR = GPIOBEN;
    /*set PB6 and PB7 mode to alternate function*/
    GPIOB->MODER &= ~(1U << 12);
    GPIOB->MODER |= (1U << 13);

    GPIOB->MODER &= ~(1U << 14);
    GPIOB->MODER |= (1U << 15);
    /*set PB6 and PB7 output to open drain*/
    GPIOB->OTYPER |= (1U << 6);
    GPIOB->OTYPER |= (1U << 7);
    /*enable pull up for PB6 and PB7*/
    GPIOB->PUPDR |= (1U << 12);
    GPIOB->PUPDR &= ~(1U < 13);

    GPIOB->PUPDR |= (1U << 14);
    GPIOB->PUPDR &= ~(1U << 15);
    /*set Alternative Function 4 for the PB6 and PB7*/
    GPIOB->AFR[0] |= (4 << (6 * 4)) | (4 << (7 * 4));

    /*enable clock access to I2C1*/
    RCC->APB1ENR |= I2C1EN;
    /*enter reset mode*/
    I2C1->CR1 |= (1U << 15);
    /*come out of reset mode*/
    I2C1->CR1 &= ~(1U << 15);
    /*Set peripheral clock frequency*/
    I2C1->CR2 = (1U << 4); // 16 mhz
    /*set I2C to fast mode , 400 kHz clock*/
    I2C1->CCR = I2C_400KHZ;
    /*set rise time*/
    I2C1->TRISE = SD_MODE_MAX_RISE_TIME;
    /*enable i2c*/
    I2C1->CR1 = (1U << 0);
}

void I2C1_byteRead(char saddr, char maddr, char *data)
{
    volatile int tmp;
    /*wait until bus will be not busy*/
    while (I2C1->SR2 & (SR2_BUSY))
        ;
    /*generate start*/
    I2C1->CR1 |= CR1_START;
    /*wait for start condition*/
    while (!(I2C1->SR1 & SR1_SB))
        ;
    /*Transmit slave address + Write*/
    I2C1->DR = saddr << 1; // left allign of slave address cause the 0 bit will be used to write/read operation
    /*Wait until addr flag is set*/
    while (!(I2C1->SR1 & SR1_ADDR))
        ;
    /*clear addr flag*/
    tmp = I2C1->SR2; // by reading this register the flag is going back to 0, just know that
    /*send memory address*/
    I2C1->DR = maddr; /*that is the address from where in the device we will check data*/
    /*wait until transmitter is empty*/
    while (!(I2C1->SR1 & SR1_TXE))
        ;
    /*generate start*/
    I2C1->CR1 |= CR1_START;
    /*wait for start condition*/
    while (!(I2C1->SR1 & SR1_SB))
        ;
    /*Transmit slave address + read*/
    I2C1->DR = saddr << 1 | 1;
    /*Wait until addr flag is set*/
    while (!(I2C1->SR1 & SR1_ADDR))
        ;
    /*Disable aknowledge*/
    I2C1->CR1 &= ~CR1_ACK;
    /*clear addr flag*/
    tmp = I2C1->SR2;
    /*generate stop condition*/
    I2C1->CR1 |= CR1_STOP;
    /*Read data drom DR*/
    *data++ = I2C1->DR;
}

void I2C1_BurstRead(char saddr, char maddr, int n, char *data)
{
    volatile int tmp;
    /*wait until bus will be not busy*/
    while (I2C1->SR2 & (SR2_BUSY))
        ;
    /*generate start*/
    I2C1->CR1 |= CR1_START;
    /*wait for start condition*/
    while (!(I2C1->SR1 & SR1_SB))
        ;
    /*Transmit slave address + Write*/
    I2C1->DR = saddr << 1; // left allign of slave address cause the 0 bit will be used to write/read operation
    /*Wait until addr flag is set*/
    while (!(I2C1->SR1 & SR1_ADDR))
        ;
    /*clear addr flag*/
    tmp = I2C1->SR2; // by reading this register the flag is going back to 0, just know that
    /*send memory address*/
    I2C1->DR = maddr; /*that is the address from where in the device we will check data*/
    /*wait until transmitter is empty*/
    while (!(I2C1->SR1 & SR1_TXE))
        ;
    /*generate start*/
    I2C1->CR1 |= CR1_START;
    /*wait for start condition*/
    while (!(I2C1->SR1 & SR1_SB))
        ;
    /*Transmit slave address + read*/
    I2C1->DR = saddr << 1 | 1;
    /*Wait until addr flag is set*/
    while (!(I2C1->SR1 & SR1_ADDR))
        ;
    /*clear addr flag*/
    tmp = I2C1->SR2;
    /*Enable aknowledge*/
    I2C1->CR1 |= CR1_ACK;
    while (n > 0)
    {
        /*if one byte*/
        if (n == 1U)
        {
            I2C1->CR1 &= ~CR1_ACK;
            I2C1->CR1 |= CR1_STOP;
            while (!(I2C1->SR1 & SR1_RXNE))
                ;
            *data++ = I2C1->DR;
            break;
        }
        else
        {
            while (!(I2C1->SR1 & SR1_RXNE))
                ;
            (*data++) = I2C1->DR;
            n--;
        }
    }
}


void I2C1_burstWrite(char saddr, char maddr, int n, char *data)
{
    volatile int tmp;
    /* Wait until bus not busy */
    while (I2C1->SR2 & (SR2_BUSY)){}
    /* Generate start */
    I2C1->CR1 |= CR1_START;
    /* Wait until start flag is set */
    while (!(I2C1->SR1 & (SR1_SB))){}
    /* Transmit slave address */
    I2C1->DR = saddr << 1;
    /* Wait until addr flag is set */
    while (!(I2C1->SR1 & (SR1_ADDR))){}
    /* Clear addr flag */
    tmp = I2C1->SR2;
    /* Wait until data register empty */
    while (!(I2C1->SR1 & (SR1_TXE))){}
    /* Send memory address */
    I2C1->DR = maddr;
    for (int i = 0; i < n; i++)
    {
        /* Wait until data register empty */
        while (!(I2C1->SR1 & (SR1_TXE))){}
        /* Transmit memory address */
        I2C1->DR = *data++;
    }
    /* Wait until transfer finished */
    while (!(I2C1->SR1 & (SR1_BTF))){}
    /* Generate stop */
    I2C1->CR1 |= CR1_STOP;
}