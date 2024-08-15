#ifndef I2C_H
#define I2C_H
void i2c_init();
void I2C1_byteRead(char saddr, char maddr, char* data);
void I2C1_BurstRead(char saddr, char maddr, int n, char* data);
void I2C1_burstWrite(char saddr, char maddr, int n, char* data);
#endif