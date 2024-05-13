#include "ILI9341.h"
#include "stm_pin_magic.h"
#include "main.h"
#include "sprites.h"
#include <string.h>
#include <stdio.h>

#define WIDTH 320
#define HEIGHT 240


//ILI9341 datasheet level 1 codes
#define SWRESET 0x01
#define SLPIN 0x10
#define SLPOUT 0x11
#define PTLON 0x12
#define NORON 0x13
#define DINVOFF 0x20
#define DINVON 0x21
#define GAMSET 0x26
#define DISPOFF 0x28
#define DISPON 0x29
#define CLADDRSET 0x2A
#define PGADDRSET 0x2B
#define MEMWRITE 0x2C
#define PIXSET 0x3A
#define RGBSET 0x2D

//ILI9341 datasheet level 2 codes
#define FRAMERATE 0xB1
#define DISPINV 0xB4
#define DISPFUNC 0xB6
#define ENTRYMODE 0xB7
#define POWERCONTROL1 0xC0
#define POWERCONTROL2 0xC1
#define VCOMCONTROL1 0xC5
#define VCOMCONTROL2 0xC7
#define MEMCONTROL 0x36




void ILIreset(void) {
    CS_IDLE;
    WR_IDLE;
    RD_IDLE;
    // Data transfer sync
  CS_ACTIVE;
  CD_COMMAND;
  write8(0x00);
  for (uint8_t i = 0; i < 3; i++)
    WR_STROBE(); // Three extra 0x00s
  CS_IDLE;
}

/**
  * @brief LCD initialisation function
  * @param None
  * @retval None
  */
void ILIinit(void) {
    ILIreset();

    HAL_Delay(200);

    CS_ACTIVE;
    writeRegister8(SWRESET, 0);
    HAL_Delay(50);
    writeRegister8(SLPIN,0);
    HAL_Delay(10);
    writeRegister8(DISPOFF, 0);
    writeRegister16(FRAMERATE, 0x001F);
    writeRegister8(POWERCONTROL1, 0x2B);//5V
    writeRegister8(POWERCONTROL2, 0x10);
    writeRegister8(MEMCONTROL, 0x88); //0b10001000 MY=1, MX=0, MV=0, ML=0, BGR=1, MH=0
    writeRegister8(PIXSET, 0x55);
    

    writeRegister8(ENTRYMODE, 0x07);

    writeRegister8(SLPOUT, 0); //wait 5ms
    HAL_Delay(5);
    writeRegister8(DISPON, 0);
    HAL_Delay(500);
    setAddrWindow(0, 0, WIDTH - 1, HEIGHT - 1);
}

/**
  * @brief Sets the address memory registers
  * @param x1 bottom left
  * @param y1 top right
  * @param x2 width
  * @param y2 height
  * @retval None
  */
void setAddrWindow(int x1, int y1, int x2, int y2) {//ILI9341 datasheet pg110-113 NEEDS OPTIMISING
  CS_ACTIVE;
  
    uint32_t t;

    t = x1 << 16;
    t |= x2;
    writeRegister32(PGADDRSET, t); 
    t = y1 << 16 | y2;
    writeRegister32(CLADDRSET, t); 
  CS_IDLE;
}

/**
  * @brief Draws an individual pixel
  * @param x x position
  * @param y y position
  * @param color 16bit color
  * @retval None
  * @note uses the adafruit tft lcd library approach
  */
void drawPixel(int16_t x, int16_t y, uint16_t color) {

  // Clip
  if (x < 0||y < 0||x >= WIDTH||y >= HEIGHT) {return;}

  CS_ACTIVE;

  setAddrWindow(x,y,WIDTH-1,HEIGHT-1);
  CS_ACTIVE;
  CD_COMMAND;
  write8(MEMWRITE);
  CD_DATA;
  write8(color>>8);
  write8(color);
  CS_IDLE;
}



/**
  * @brief Draws a filled rectangle
  * @param x x position
  * @param y y position
  * @param w width
  * @param h height
  * @param color 16bit color
  * @retval None
  */
void fillRect(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t color) {
  setAddrWindow(x,y,x+w-1,y+h-1);
  flood(color,w*h);
}

/**
  * @brief Fills the screen with a color
  * @param color 16bit color
  * @retval None
  */
void fillScreen(uint16_t color) {
  setAddrWindow(0, 0, WIDTH - 1, HEIGHT - 1);
  flood(color,WIDTH*HEIGHT);
}

//Taken directly from adafruit TFTLCD library https://github.com/adafruit/TFTLCD-Library/blob/master/Adafruit_TFTLCD.cpp
void flood(uint16_t color, uint32_t len) {
  uint16_t blocks;
  uint8_t i, hi = color >> 8, lo = color; //

  CS_ACTIVE;
  CD_COMMAND;
  write8(0x2C);
  // OCWrite first pixel normally, decrement counter by 1
  CD_DATA;
  write8(hi);
  write8(lo);
  len--;

  blocks = (uint16_t)(len / 64); // OC64 pixels/block
  if (hi == lo) {
    // OCHigh and low bytes are identical.  Leave prior data
    // on the port(s) and just toggle the write strobe.
    while (blocks--) {
      i = 16; // 64 pixels/block / 4 pixels/pass
      do {
        WR_STROBE();
        WR_STROBE();
        WR_STROBE();
        WR_STROBE(); // 2 bytes/pixel
        WR_STROBE();
        WR_STROBE();
        WR_STROBE();
        WR_STROBE(); // x 4 pixels
      } while (--i);
    }
    // Fill any remaining pixels (1 to 64)
    for (i = (uint8_t)len & 63; i--;) {
      WR_STROBE();
      WR_STROBE();
    }
  } else {
    while (blocks--) {
      i = 16; // 64 pixels/block / 4 pixels/pass
      do {
        write8(hi);
        write8(lo);
        write8(hi);
        write8(lo);
        write8(hi);
        write8(lo);
        write8(hi);
        write8(lo);
      } while (--i);
    }
    for (i = (uint8_t)len & 63; i--;) {
      write8(hi);
      write8(lo);
    }
  }
  CS_IDLE;
}

void drawBMP(void) {
  //int BMP[240][240] = "flower_240x240.bmp"

}



void drawChar(int16_t x,int16_t y, unsigned char c,uint16_t color,uint16_t background,uint8_t size) {
  //5x8 font

  //add clipping
  //17,18
  setAddrWindow(x,y,x+(size*5)-1,y+(size*8)-1);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  uint16_t pixColor;
  
  for (x=0;x<5;x++) {
    uint8_t line = font[c - 32][x];
    for(int8_t sx=0;sx<size;sx++) {
      for(int8_t i = 0;i<8;i++) {
        for (int8_t sy = 0;sy<size;sy++){
          pixColor = (line & (0x01 << i)) ? color:background;//conditional if bit is 1, use color, else use background
          writeData16(pixColor);
        }
      }
    }
  }
  

  CS_IDLE;

}

// own approach
void drawString(uint16_t x, uint16_t y, const char *string,uint16_t color,uint16_t background,uint8_t size) {
  uint8_t length = strlen(string);
  setAddrWindow(x,y,((x+(size*5)*length)-1)+(size*length),y+(size*8)-1);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  uint16_t pixColor;

  for(int c = 0;c<length;c++) {
    for (x=0;x<5;x++) { // currently monospace, I have a way of changing it but it will slow down printing, will add after creating seperate UI buffers for each section of the LCD
      uint8_t line = font[string[c] - 32][x];
      for(int8_t sx=0;sx<size;sx++) {
        for(int i = 0;i<8;i++) {
          
          for (int sy = 0;sy<size;sy++){
            pixColor = (line & (0x01 << i)) ? color:background;//conditional if bit is 1, use color, else use background
            writeData16(pixColor);
          }
        }
      }
    }

    for(int g = 0;g<size;g++) {// this has been tested, the spacing between characters sometimes looks thinner than it actually is
      for(int s = 0;s<size*8;s++) {
        writeData16(background); // draws gaps between characters
      }
    }

  }
  CS_IDLE;
}

/**
  * @brief Draws an integer 0-100, followed by a percentage sign, right alligned
  * @param color 16bit color
  * @param color 16bit background color
  * @param size text size
  * @retval None
  */
void drawPerc(uint16_t x, uint16_t y, int perc,uint16_t color,uint16_t background,uint8_t size) {
  char s[5] = {' '}; 
  sprintf(s, "%i%%", perc);
  int end = 0;
  while(strlen(s) < 5) {s[5-end] = ' ';end++;}
  drawString(x,y,s,color,background,size);
}  //following this with a drawDial will stop the dial printing, removing this line allows the two to work
   //fixed above - issue with overwriting the character array once I added the null character, size increased 4>5
  /* old right alligned 
  char s[5] = {' '}; 
  sprintf(s, "%i", i);
  while(strlen(s) < 3) {s[2]=s[1];s[1]=s[0];s[0] = ' ';}
  s[3] = '%';s[4] = '\0';//append with percent sign and a null sign
  drawString(x,y,s,color,background,size);  */

/**
  * @brief Draws an integer 0-100, followed by a percentage sign, right alligned
  * @param color 16bit color
  * @param color 16bit background color
  * @param size text size
  * @retval None
  */
void drawFreq(uint16_t x, uint16_t y, int freq,uint16_t color,uint16_t background) {
  char s[7] = {' '}; 
  sprintf(s, "%i", freq);
  drawString(x,y,s,color,background,2);
  drawString(x+(strlen(s)*12),y+1,"Hz",color,background,1);
}

/**
  * @brief Draws a dial when sent the percentage to fill (0-100)
  * @param color 16bit color
  * @retval None
  */
void drawDial(uint16_t x,uint16_t y,int p,uint16_t color,uint16_t empty,uint16_t background) {
  if(p<0||p>100){return;}
  setAddrWindow(x,y,x+31,y+31);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  uint16_t pixColor;
  CD_DATA;
  int addr = p/2; //51 dial sprites (0-50), not 49 as you'd expect
  for(int i=0;i<32;i++) {
    uint32_t line = dials[addr][i];
    for(int b=0;b<32;b++){
      pixColor = (line & (0x01 << b)) ? color:background;
      write16(pixColor);
    }
  }
  CS_IDLE;
}


void drawLineH(uint16_t x,uint16_t y,uint16_t l,uint16_t color) {
  setAddrWindow(x,y,l,y);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  for(int i=0;i<l;i++){
    writeData16(color);
  }
  CS_IDLE;
}

void drawLineV(uint16_t x,uint16_t y,uint16_t l,uint16_t color) {
  setAddrWindow(x,y,x,y+l);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  for(int i=0;i<l;i++){
    writeData16(color);
  }
  CS_IDLE;
}

void printSettingNames(uint16_t y) {
    uint16_t pixColor;
  setAddrWindow(0,y,WIDTH-1,(y+8)-1);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  for(int x = 0;x<320;x++) {
    for(int i = 0;i<8;i++) {
      pixColor = (settingNameBar[x] & (0x01 << i)) ? WHITE:BLACK;
      writeData16(pixColor);
    }
  }
  setAddrWindow(0,y-100,WIDTH-1,(y-100+8)-1);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  for(int x = 320;x<640;x++) {
    for(int i = 0;i<8;i++) {
      pixColor = (settingNameBar[x] & (0x01 << i)) ? WHITE:BLACK;
      writeData16(pixColor);
    }
  }
}

void printSettingValues(uint16_t y, uint16_t color) {
  uint16_t pixColor;
  setAddrWindow(0,y,WIDTH-1,(y+16)-1);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  for(int x = 0;x<320;x++) {
    for(int i = 0;i<16;i++) {
      pixColor = (settingValueBar[x] & (0x01 << i)) ? color:BLACK;
      writeData16(pixColor);

    }
  }
}


/**
  * @brief Prints out the rendered setting values and icons
  * @param y position from bottom of screen (default 160)
  * @param color 16bit color
  * @retval None
  */
void printSettingBar(uint16_t y, uint16_t color) {
  uint16_t pixColor;
  setAddrWindow(0,y,WIDTH-1,(y+50)-1);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  for(int x = 0;x<320;x++) {
    for(int i = 0;i<32;i++){
      pixColor = (settingIconBar[x] & (0x1 << i)) ? color:BLACK;
      writeData16(pixColor);
    }
    for(int i = 0;i<2;i++){writeData16(0x0000);}
    for(int i = 0;i<16;i++) {
      pixColor = (settingValueBar[x] & (0x1 << i)) ? color:BLACK;
      writeData16(pixColor);
    }
    
    
  }
  setAddrWindow(0,y-100,WIDTH-1,(y-100+50)-1);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  for(int x = 320;x<640;x++) {
    for(int i = 0;i<32;i++){
      pixColor = (settingIconBar[x] & (0x1 << i)) ? color:BLACK;
      writeData16(pixColor);
    }
    for(int i = 0;i<2;i++){writeData16(0x0000);}
    for(int i = 0;i<16;i++) {
      pixColor = (settingValueBar[x] & (0x1 << i)) ? color:BLACK;
      writeData16(pixColor);
    }
    
    
  }
}

void printWave(uint16_t y, uint16_t color) {
  setAddrWindow(0,y,WIDTH-1,(y+64)-1);
  CS_ACTIVE;
  writeCommand8(MEMWRITE);
  uint16_t pixColor;
  for(int x = 0;x<160;x++) {
    for(int i = 0;i<64;i++){
      pixColor = (waveBar[x] & (0x1 << i)) ? color:BLACK;
      writeData16(pixColor);
    }
  }
}





