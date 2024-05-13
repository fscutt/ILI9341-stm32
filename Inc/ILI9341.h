#ifndef ILI9341_H
#define ILI9341_H

#include "stm32l4xx_hal.h"



void ILIinit(void);
void ILIreset(void);

void setAddrWindow(int x1, int y1, int x2, int y2);
void flood(uint16_t color, uint32_t len);

void fillRect(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t color);
void fillScreen(uint16_t color);

void drawPixel(int16_t x, int16_t y, uint16_t color);
void drawChar(int16_t x,int16_t y, unsigned char c,uint16_t color,uint16_t background,uint8_t size);
void drawString(uint16_t x, uint16_t y, const char *str,uint16_t color,uint16_t background,uint8_t size);
void drawPerc(uint16_t x, uint16_t y, int perc,uint16_t color,uint16_t background,uint8_t size);
void drawFreq(uint16_t x, uint16_t y, int freq,uint16_t color,uint16_t background);
void drawDial(uint16_t x,uint16_t y,int p,uint16_t color,uint16_t empty,uint16_t background);

void drawLineH(uint16_t x,uint16_t y,uint16_t l,uint16_t color);
void drawLineV(uint16_t x,uint16_t y,uint16_t l,uint16_t color);

void printSettingNames(uint16_t y);
void printSettingValues(uint16_t y,uint16_t color);
void printSettingBar(uint16_t y, uint16_t color);
void printWave(uint16_t y, uint16_t color);

#define	BLACK   0x0000 //for some reason 0x0000 wasnt writing
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0xAAAA

/*
char font[2][5] = {
    {0x00,0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0x00,0x00}
};
*/



#endif
