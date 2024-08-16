#include "SSD1306.h"
#include <i2c.h>
#define SSD1306_I2C_ADDR 0x3C /*I2C addres of the device on bus*/
#define SSD1306_COMMAND 0x00  /*Memory base for commands for OLED display*/
#define SSD1306_DATA 0x40     /*Memory base for data(GPDDR) for OLED display*/

#define SSD1306_WIDTH 128 /*width in pixels*/
#define SSD1306_HEIGHT 64 /*height in pixels*/

/*buffer that will have all bits set as the pixels on the display*/
static char buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];
void clear_buffer(){
    for(int i = 0; i < SSD1306_WIDTH * SSD1306_HEIGHT / 8; i++){
       buffer[i] = 0;
    }
   
}

/*Clear function for display, just replace all bits in the GPDDR of display to zero`s*/
void SSD1306_clear(void)
{
    char clearData[128] = {0}; /*array with zero`s*/
    for (char page = 0; page < 8; page++)
    {
        char commands[3];
        /* Set page address*/
        commands[0] = (char)(0xB0 + page);
        /* Set collumns as zero`s*/
        commands[1] = (char)(0x00);
        commands[2] = (char)(0x10);

        /*send the commands to display controller*/
        I2C1_burstWrite(SSD1306_I2C_ADDR, SSD1306_COMMAND, 3, commands);

        /*send data to display controller*/
        I2C1_burstWrite(SSD1306_I2C_ADDR, SSD1306_DATA, 128, clearData);
    }
}

/*Initialization function for the display controller*/
void SSD1306_init()
{

    char initCommands[] = {
        0xAE,       // Display off
        0x20, 0x02, // Set Memory Addressing Mode to Page Addressing Mode (0x10)
        0xC8,       // COM Output Scan Direction
        0x00,       // ---set low column address
        0x10,       // ---set high column address
        0x40,       // ---set start line address
        0x81, 0xFF, // Set contrast control register
        0xA1,       // Set Segment Re-map. A0=address mapped; A1=address 127 mapped.
        0xA6,       // Set Normal/Inverse Display. A6=Normal; A7=Inverse
        0xA8, 0x3F, // Set Multiplex Ratio
        0xA4,       // Output RAM to Display
        0xD3, 0x00, // Set Display Offset
        0xD5, 0xF0, // Set Display Clock Divide Ratio/Oscillator Frequency
        0xD9, 0x22, // Set Pre-charge Period
        0xDA, 0x12, // Set COM Pins Hardware Configuration
        0xDB, 0x20, // Set VCOMH Deselect Level
        0x8D, 0x14, // Enable charge pump regulator
        0xAF        // Display ON
    };
    /*send the commands to display controller*/
    I2C1_burstWrite(SSD1306_I2C_ADDR, SSD1306_COMMAND, 27, initCommands);
}

void setPixel(int x, int y, int color)
{
    if (x < 0 || x >= SSD1306_WIDTH || y < 0 || y >= SSD1306_HEIGHT)
    {
        /*Pixel is outside the display area*/
        return;
    }

    int byteIndex = x + (y / 8) * SSD1306_WIDTH; // index of byte in the buffer
    int bitIndex = y % 8;                        // index of bit in vyte

    if (color)
    {
        buffer[byteIndex] |= (1 << bitIndex); // Setting bit
    }
    else
    {
        buffer[byteIndex] &= ~(1 << bitIndex); // Clearing bit
    }
}

void updateDisplay()
{
    // Sending data from buffer to display

    for (int page = 0; page < (SSD1306_HEIGHT / 8); page++)
    {
        char commands[3] = {
            /* Set page address*/
            0xB0 + page,
            /* Set collumns as zero`s*/ // вот с этой хуйней разберись 0x00,
            0x00,
            0x10
            };
        /*send the commands to display controller*/
        I2C1_burstWrite(SSD1306_I2C_ADDR, SSD1306_COMMAND, 3, commands);
        /*send data to display controller*/
        I2C1_burstWrite(SSD1306_I2C_ADDR, SSD1306_DATA, SSD1306_WIDTH, &buffer[SSD1306_WIDTH * page]);
    }
}


/*Function to draw bitMaps in buffer*/
void drawBitMapBuffer(int x, int y, const char *bitMap, int height, int width)
{
    int bytesPerRow = (width + 7) / 8; 

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            /*Calculating index of byte and an index of bit in byte*/
            int byteIndex = (col / 8) + row * bytesPerRow;
            int bitOffset = col % 8;

            /*getting the bit from bitmap*/
            char bit = (bitMap[byteIndex] >> (7 - bitOffset)) & 1;

            /*Calculating the coordinates*/
            int pixelX = x + col;
            int pixelY = y + row;

            /*Setting pixel in the buffer*/
            if (bit)
            {
                setPixel(pixelX, pixelY, 1);
            }
        }
    }
}