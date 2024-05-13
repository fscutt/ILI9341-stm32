#include "sprites.h"

unsigned char font[96][5] = {
    {0x00,0x00,0x00,0x00,0x00}, // ' ' value 32, line 0
    {0x00,0x00,0xF2,0x00,0x00}, // !
    {0x00,0xE0,0x00,0xE0,0x00}, // "
    {0x28,0xFE,0x28,0xFE,0x28}, // #
    {0x24,0x54,0xFE,0x54,0x48}, // $
    {0xC4,0xC8,0x10,0x26,0x46}, // %
    {0x6C,0x92,0xAA,0x44,0x0A}, // &
    {0x00,0x00,0xC0,0x00,0x00}, // '
    {0x00,0x38,0x44,0x82,0x00}, // (
    {0x00,0x82,0x44,0x38,0x00}, // )
    {0x00,0x00,0x00,0x00,0x00}, // *
    {0x10,0x10,0x7C,0x10,0x10}, // +
    {0x00,0x00,0x00,0x00,0x00}, // ,
    {0x10,0x10,0x10,0x10,0x10}, // -
    {0x00,0x00,0x02,0x00,0x00}, // .
    {0xFF,0xFF,0xFF,0xFF,0xFF}, // / used as a test character
    {0x7C,0x82,0x82,0x82,0x7C}, // 0
    {0x00,0x42,0xFE,0x02,0x00}, // 1
    {0x42,0x86,0x8A,0x92,0x62}, // 2
    {0x84,0x82,0xA2,0xD2,0x8C}, // 3
    {0x18,0x28,0x48,0xFE,0x08}, // 4
    {0xE4,0xA2,0xA2,0xA2,0x9C}, // 5
    {0x3C,0x52,0x92,0x92,0x0C}, // 6
    {0xC0,0x80,0x8E,0xB0,0xC0}, // 7
    {0x6C,0x92,0x92,0x92,0x6C}, // 8
    {0x60,0x92,0x92,0x94,0x78}, // 9
    {0x00,0x00,0x24,0x00,0x00}, // :
    {0x00,0x00,0x00,0x00,0x00}, // ;
    {0x00,0x10,0x28,0x44,0x00}, // <
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x3E,0x48,0x88,0x48,0x3E}, // A
    {0xFE,0x92,0x92,0x92,0x6C}, // B
    {0x7C,0x82,0x82,0x82,0x44}, // C
    {0xFE,0x82,0x82,0x82,0x7C}, // D
    {0xFE,0x92,0x92,0x92,0x82}, // E
    {0xFE,0x90,0x90,0x90,0x80}, // F
    {0x7C,0x82,0x82,0x92,0x5E}, // G
    {0xFE,0x10,0x10,0x10,0xFE}, // H
    {0x00,0x82,0xFE,0x82,0x00}, // I
    {0x04,0x02,0x82,0xFC,0x80}, // J
    {0xFE,0x10,0x28,0x44,0x82}, // K
    {0xFE,0x02,0x02,0x02,0x02}, // L
    {0xFE,0x40,0x20,0x40,0xFE}, // M
    {0xFE,0x60,0x10,0x0C,0xFE}, // N
    {0x7C,0x82,0x82,0x82,0x7C}, // O
    {0xFE,0x90,0x90,0x90,0x60}, // P
    {0x7C,0x82,0x86,0x84,0x7A}, // Q
    {0xFE,0x90,0x98,0x94,0x62}, // R
    {0x64,0x92,0x92,0x92,0x4C}, // S
    {0x80,0x80,0xFE,0x80,0x80}, // T
    {0xFC,0x02,0x02,0x02,0xFC}, // U
    {0xF8,0x04,0x02,0x04,0xF8}, // V
    {0xFC,0x02,0x0C,0x02,0xFC}, // W
    {0xC6,0x28,0x10,0x28,0xC6}, // X
    {0xE0,0x10,0x0E,0x10,0xE0}, // Y
    {0x86,0x8A,0x92,0xA2,0xC2}, // Z
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x04,0x2A,0x2A,0x2A,0x1E}, // a
    {0xFE,0x12,0x22,0x22,0x1C}, // b
    {0x1C,0x22,0x22,0x22,0x04}, // c
    {0x1C,0x22,0x22,0x24,0xFE}, // d
    {0x1C,0x2A,0x2A,0x2A,0x18}, // e
    {0x08,0x3F,0x48,0x40,0x20}, // f
    {0x18,0x25,0x25,0x25,0x1E}, // g
    {0xFE,0x10,0x20,0x20,0x1E}, // h
    {0x00,0x12,0x5E,0x02,0x00}, // i
    {0x02,0x01,0x11,0x5E,0x00}, // j
    {0xFE,0x08,0x14,0x22,0x00}, // k
    {0x00,0x82,0xFE,0x02,0x00}, // l
    {0x3E,0x20,0x1E,0x20,0x1E}, // m
    {0x3E,0x10,0x20,0x20,0x1E}, // n
    {0x1C,0x22,0x22,0x22,0x1C}, // o
    {0x3F,0x24,0x24,0x24,0x18}, // p
    {0x18,0x24,0x24,0x14,0x3F}, // q
    {0x3E,0x10,0x20,0x20,0x10}, // r
    {0x12,0x2A,0x2A,0x2A,0x04}, // s
    {0x20,0xFC,0x22,0x02,0x04}, // t
    {0x3C,0x02,0x02,0x04,0x3E}, // u
    {0x38,0x04,0x02,0x04,0x38}, // v
    {0x3C,0x02,0x0C,0x02,0x3C}, // w
    {0x22,0x14,0x08,0x14,0x22}, // x
    {0x38,0x05,0x05,0x05,0x3E}, // y
    {0x22,0x26,0x2A,0x32,0x22}, // z
    {0x00,0x10,0x6C,0x82,0x00}, // {
    {0x00,0x00,0xFE,0x00,0x00}, // |
    {0x00,0x82,0x6C,0x10,0x00}, // }
    {0x08,0x10,0x10,0x08,0x10}, // ~  value 126 - line 94
    {0x00,0x00,0x00,0x00,0x00}, // DEL 
};


int16_t ableColors[70] = {
    0xFCB4,0xFD25,0xCCC4,0xF7AF,0xBFC0,0x1FE5,0x27F5,0x5FFD,0x8E3F,0x541C,0x953F,0xDB7C,0xE294,0xFFFF,
    0xF9A6,0xF360,0x9B89,0xFF86,0x87EC,0x3E00,0x05F5,0x1F5F,0x153D,0x03F8,0x8B7C,0x8B7C,0xF9DA,0xD69A,
    0xE32B,0xFD0E,0xD56E,0xEFF5,0xD733,0xBE8E,0x9E31,0xD7FC,0xCF9F,0xBE1C,0xCDDC,0xACDC,0xE6FC,0xAD55,
    0xC491,0xB40A,0x9C0D,0x04E1,0xA5E0,0x7D89,0x8E17,0x9D98,0x8538,0x8499,0xA4B6,0xBCF7,0xBB92,0x7BCF,
    0xA986,0xAA86,0x7268,0xDE00,0x84A3,0x54E6,0x0CF1,0x2310,0x1972,0x2A94,0x6255,0xA255,0xC96D,0x39E7
};

int dials[51][32] = {
    {// 0
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 2%
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 4%
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 6%
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 8%
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 10%
    0x00000000,0x00000000,0x00000000,0x00000C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 12%
    0x00000000,0x00000000,0x00001000,0x00001C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 14%
    0x00000000,0x00000000,0x00003000,0x00001C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 16%
    0x00000000,0x00000000,0x00007000,0x00001C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 18%
    0x00000000,0x00000000,0x0000F000,0x00001C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 20%
    0x00000000,0x00000000,0x0001F000,0x00001C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 22%
    0x00000000,0x00000000,0x0003F000,0x00001C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 24%
    0x00000000,0x00000000,0x0007F000,0x00001C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 26% 
    0x00000000,0x00000000,0x000FF000,0x00081C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 28%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00000700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 30%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x00000180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 32% 
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x000000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 34%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x00000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 36%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 38% 
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 40%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x08000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 42%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 44%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 46%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 48%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 50%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 52%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 54%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 56%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 58%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 60%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x10000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 62%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 64%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 66%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 68%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 70%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 72%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00000000,0x00000000,0x00000000,0x00000000},
    {// 74%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00300000,0x00000000,0x00000000,0x00000000},
    {// 76%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00380000,0x00080000,0x00000000,0x00000000},
    {// 78%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00380000,0x000C0000,0x00000000,0x00000000},
    {// 80%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00380000,0x000E0000,0x00000000,0x00000000},
    {// 82%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00380000,0x000F0000,0x00000000,0x00000000},
    {// 84%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00380000,0x000F8000,0x00000000,0x00000000},
    {// 86%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00380000,0x000FC000,0x00000000,0x00000000},
    {// 88%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00380000,0x000FE000,0x00000000,0x00000000},
    {// 90%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00381000,0x000FF000,0x00000000,0x00000000},
    {// 92%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00000,
    0x00381C00,0x000FF000,0x00000000,0x00000000},
    {// 94%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800000,0x00E00700,
    0x00381C00,0x000FF000,0x00000000,0x00000000},
    {// 96%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x03000000,0x01800180,0x00E00700,
    0x00381C00,0x000FF000,0x00000000,0x00000000},
    {// 98%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000000,0x030000C0,0x01800180,0x00E00700,
    0x00381C00,0x000FF000,0x00000000,0x00000000},
    {// 100%
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000060,0x030000C0,0x01800180,0x00E00700,
    0x00381C00,0x000FF000,0x00000000,0x00000000}
};

/*  Full Circle
    0x00000000,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000030,0x08000010,0x18000018,0x10000008,
    0x3000000C,0x20000004,0x20000004,0x20000004,
    0x20000004,0x20000004,0x20000004,0x3000000C,
    0x10000008,0x18000018,0x08000010,0x0C000030,
    0x06000060,0x030000C0,0x01800180,0x00E00700,
    0x00381C00,0x000FF000,0x00000000,0x00000000

    Decided Arc
    0x80000001,0x00000000,0x000FF000,0x00381C00,
    0x00E00700,0x01800180,0x030000C0,0x06000060,
    0x0C000000,0x08000000,0x18000000,0x10000000,
    0x30000000,0x20000000,0x20000000,0x20000000,
    0x20000000,0x20000000,0x20000000,0x30000000,
    0x10000000,0x18000000,0x08000000,0x0C000000,
    0x06000060,0x030000C0,0x01800180,0x00E00700,
    0x00381C00,0x000FF000,0x00000000,0x80000001
*/
