//most functions adapted from https://github.com/adafruit/TFTLCD-Library/blob/master/pin_magic.h
//

#ifndef _stm_pin_magic_
#define _stm_pin_magic_

#include "stm32l4xx_hal.h"



#define RD_PORT PORTB /*pin B0 */
#define WR_PORT PORTB /*pin B1 */
#define CD_PORT PORTB /*pin B2 */
#define CS_PORT PORTB /*pin B3 */
#define RD_MASK 0x01
#define WR_MASK 0x02
#define CD_MASK 0x04
#define CS_MASK 0x08

#define CS_Pin GPIO_PIN_0
#define CS_GPIO_Port GPIOB
#define CD_Pin GPIO_PIN_1
#define CD_GPIO_Port GPIOB
#define WR_Pin GPIO_PIN_2
#define WR_GPIO_Port GPIOB
#define RD_Pin GPIO_PIN_3
#define RD_GPIO_Port GPIOB                            

#define RD_ACTIVE RD_GPIO_Port->ODR &= ~RD_MASK
#define RD_IDLE RD_GPIO_Port->ODR |= RD_MASK
#define WR_ACTIVE WR_GPIO_Port->ODR &= ~WR_MASK
#define WR_IDLE WR_GPIO_Port->ODR |= WR_MASK
#define CD_COMMAND CD_GPIO_Port->ODR &= ~CD_MASK
#define CD_DATA CD_GPIO_Port->ODR |= CD_MASK
#define CS_ACTIVE CS_GPIO_Port->ODR &= ~CS_MASK
#define CS_IDLE CS_GPIO_Port->ODR |= CS_MASK

void WR_STROBE() {                        
    WR_ACTIVE;                                
    WR_IDLE;                 
}                            

void write8(uint8_t d) {                            
    GPIOA->ODR = (d & 0xFF)<<4;                          
    WR_STROBE();                        
}

void writeData16(uint16_t d) {
    uint8_t hi, lo;  
    hi = (d) >> 8;                              
    lo = (d);                                   
    CD_DATA;                                    
    write8(hi);                                 
    write8(lo);   
}

void write16(uint16_t d) { //used to speed up large color data writes, where CD should be set to data first which saves writing to the pin each time
    uint8_t hi, lo;  
    hi = (d) >> 8;                              
    lo = (d);                                                                      
    write8(hi);                                 
    write8(lo);   
}

void writeCommand8(uint16_t c) { //useful for setting the memory address without writing colour data                
    CD_COMMAND;                                    
    write8(c);
}

void writeRegister8(uint8_t a,uint8_t d) {                  
    CD_COMMAND;                                 
    write8(a);                                  
    CD_DATA;                                    
    write8(d);                                  
  }

// Set value of TFT register: 16-bit address, 16-bit value
// See notes at top about macro expansion, hence hi & lo temp vars
void writeRegister16(uint16_t a, uint16_t d) {
    uint8_t hi, lo;                             
    hi = (a) >> 8;                              
    lo = (a);                                   
    CD_COMMAND;                                 
    write8(hi);                                 
    write8(lo);                                 
    hi = (d) >> 8;                              
    lo = (d);                                   
    CD_DATA;                                    
    write8(hi);                                 
    write8(lo);                                 
  }

void writeRegister32(uint8_t r, uint32_t d) {
  CS_ACTIVE;
  CD_COMMAND;
  write8(r);
  CD_DATA;
  write8(d >> 24);
  write8(d >> 16);
  write8(d >> 8);
  write8(d);
  CS_IDLE;
}

#endif