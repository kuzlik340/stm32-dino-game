/*
 * SSD1306.h   v1.0
 *
 * contains functions to show pixels on display
 *
 * T.Kuz    8.2024
 */
#ifndef SSD1306__H
#define SSD1306__H
void SSD1306_clear(void);
void SSD1306_init(void);
void setPixel(int x, int y, int color);
void updateDisplay();
void drawBitMapBuffer(int x, int y, const char *bitMap, int height, int width);
void clear_buffer();

#endif