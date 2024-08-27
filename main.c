/*
 * main.c  v1.0
 *
 * main part of code
 *
 * T.Kuz    8.2024
 */
#include "i2c.h"
#include "SSD1306.h"
#include "button.h"
#include "systick.h"
#include "bitmaps.h"
#include "adc.h"


#define GPIOAEN (1U << 0)
#define GPIOCEN (1U << 2)


void draw_horizon();
char random();
void drawStars();
void dead_dino(int gg, int y);
int max(int x1, int x2);
int min(int x1, int x2);
int rectangles_overlap(int x1, int y1, int width1, int height1,
                       int x2, int y2, int width2, int height2);
void jump_dino(int *gg);
void restart_game();
void draw_dino();
void game();
void setup();

int alive = 1;

void draw_horizon()
{
    for (int x = 0; x < 128; x++)
    {
        setPixel(x, 55, 1);
    }
}

char random (){
    start_conversion();
    return adc_read()+1;
    
}

void drawStars()
{
    setPixel(6, 15, 1);
    setPixel(124, 28, 1);
    setPixel(64, 10, 1);
    setPixel(30, 10, 1);
    setPixel(87, 20, 1);
    setPixel(56, 27, 1);
    setPixel(100, 10, 1);
}

void dead_dino(int gg, int y){
    drawStars();
    draw_horizon();
    drawBitMapBuffer(gg, 32, tree1_bitMap, 23, 11);
    drawBitMapBuffer(10, y, dead_dino_bitMap, 26, 25);
    updateDisplay();
    clear_buffer();
    alive = 0;
    restart_game();
}


int max(int x1, int x2){
    return (x1 > x2 ? x1 : x2);
}

int min(int x1, int x2){
    return (x1 < x2 ? x1 : x2);
}

int rectangles_overlap(int x1, int y1, int width1, int height1, 
                       int x2, int y2, int width2, int height2) {
    return !(x1 + width1 < x2 || 
             x2 + width2 < x1 || 
             y1 + height1 < y2 || 
             y2 + height2 < y1);
}


void jump_dino(int *gg)
{
    int y = 32;
    
    for (y; y > 3; y-=3)
    {
        drawBitMapBuffer(10, y, dino1_bitMap, 26, 25);
        drawStars();
        draw_horizon();
        drawBitMapBuffer(*gg, 32, tree1_bitMap, 23, 11);
        *gg -= 3;
        updateDisplay();
        clear_buffer();
        if(rectangles_overlap(12, y, 15, 15, *gg, 32, 11, 23)){
           dead_dino(*gg, y);
           break;
        }
       
    }
    if(!alive){
        return;
    }
    
    for(int x = 0; x < 8; x++){
        drawBitMapBuffer(10, y, dino1_bitMap, 26, 25);
        drawStars();
        draw_horizon();
        drawBitMapBuffer(*gg, 32, tree1_bitMap, 23, 11);
        *gg -= 3;
        updateDisplay();
        clear_buffer();
        
    }
   


    for (y; y < 33; y+=3)
    {
        drawBitMapBuffer(10, y, dino1_bitMap, 26, 25);
        drawStars();
        draw_horizon();
        drawBitMapBuffer(*gg, 32, tree1_bitMap, 23, 11);
        *gg -= 3;
        updateDisplay();
        clear_buffer();
        if(rectangles_overlap(12, y, 15, 15, *gg, 32, 11, 23)){
            dead_dino(*gg, y);
           break;
        }
        
    }
     
}

void draw_dino(){
    static int dd = 0;
    if(dd >= 0 && dd < 4){
        drawBitMapBuffer(10, 32, dino2_bitMap, 26, 25);
    }
    else if(dd >= 4 && dd <= 8){
        drawBitMapBuffer(10, 32, dino3_bitMap, 26, 25);
        if(dd == 8){
            dd = 0;
        }
    }
    dd++;
}


void game(){
    int gg = 160;
    while (alive)
    {   
        
        if ((isbutton_clicked()))
        {   
            jump_dino(&gg);
            systickDelayMs(10);
        }
        else
        {
            drawBitMapBuffer(gg, 32, tree1_bitMap, 23, 11);
            gg -= 3;
            drawStars();
            draw_horizon();
            draw_dino();
            updateDisplay();
            clear_buffer();
            if(gg <= 34 && gg>=10){
                dead_dino(gg, 32);
                break;
            }
            int x = random();
            if (gg < 10)
            {
                if (x>30){
                    gg = 2*(30 + x);
                }
                else{
                    gg = 2*(60 + x);
                } 
            }
        }
    }
}


void restart_game(){
    systickDelayMs(1500);
    while(!isbutton_clicked());
    alive = 1;
    systickDelayMs(100);
    game();
}

void setup(){
    i2c_init();
    systickDelayMs(10);
    SSD1306_init(); // Initialize the OLED display
    systickDelayMs(10);
    SSD1306_clear();
    systickDelayMs(10);
    button_init();
    systickDelayMs(10);
    pa1_adc_init();
    systickDelayMs(10);
}

int main()
{
    setup();
    game();
}