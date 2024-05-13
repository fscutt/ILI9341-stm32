#include "interface.h"

int16_t screen[10][10];

int8_t settingNameBar[640];
int16_t settingValueBar[640];
int32_t settingIconBar[640];
int64_t waveBar[160];

char *settingNames[8];
double settingValues[8];
double settingPercs[8];
enum valueType settingTypes[8];
char *settingMulti[4][2];


void setSettingName(char *name,int pos) {
    settingNames[pos] = name;
}

void setSettingValue(float value,int pos) {
    settingValues[pos] = value;
}

void setSettingPerc(float value,int pos) {
    settingPercs[pos] = value;
}

void setSettingType(enum valueType type,int pos) {
    settingTypes[pos] = type;
}


void setSettingMulti(char *multi,int pos) {
    *settingMulti[pos] = multi;
}


void setSetting(int pos,char *name,enum valueType type,int value) {
    settingNames[pos] = name;
    settingValues[pos] = value;
    settingTypes[pos] = type;
}

void renderSettingNames(void) {
    for(int n = 0;n<8;n++) {
        uint8_t len = strlen(settingNames[n]);
        for(int c = 0;c<len;c++) {
            for(int x = 0;x<5;x++) {
                settingNameBar[(n*80)+(c*6)+x+8] = font[settingNames[n][c] - 32][x];
            }// I'll try to explain ^^^^^^^^ this, the spacing between value titles is 80pixels
        }    // each character is 5 pixels wide, plus a single pixel gap
    }        // and each title is indented by 8 pixels, reading from the font array gets a vertical line of 8 pixels
}            // this is then written to settingNameBar at the calculated position, resulting in a bar of the screen being rendered

void renderSettingValues(void) {
    memset(settingValueBar,0x0000,sizeof(settingValueBar));
    for(int n = 0;n<8;n++) {
        int len;
        int freqSuffNum = 0;
        char *suffixes[3] = {"Hz","kHz","MHz"};
        int timeSuffix = 0;
        switch(settingTypes[n]) {
            case INT:
                if(settingValues[n] > 99999) {break;} //outside of printing range
                renderSettingDouble(n,5);
                break;
            case FREQ:
                if(settingValues[n] >= 1000000) {break;} //outside of printing range
                while(settingValues[n]>=1000) {
                    freqSuffNum += 1;
                    settingValues[n]/=1000;
                }
                len = renderSettingDouble(n,3);
                for(int c = 0;c<strlen(suffixes[freqSuffNum]);c++) {
                    for(int x = 0;x<5;x++) {
                        settingValueBar[(n*80)+(len*12)+(c*6)+x+8] = font[suffixes[freqSuffNum][c]-32][x]<<1;
                    }
                }
                break;
            case TIME:
                if(settingValues[n] >= 1000000) {break;} //outside of printing range
                if(settingValues[n]<=1) {
                    settingValues[n] *=1000;
                    timeSuffix = 1;
                }
                len = renderSettingDouble(n,4);
                if(timeSuffix == 1) {
                    for(int x = 0;x<5;x++) {
                        settingValueBar[(n*80)+(len*12)+x+8] = font[77][x]<<1;
                    }
                }
                for(int x = 0;x<5;x++) {
                    settingValueBar[(n*80)+(len*12)+x+8+6*timeSuffix] = font[83][x]<<1;
                }
                
                break;
            case PERC://ranges from 0% to 200%
                if(settingValues[n] > 99999) {break;} //outside of printing range
                len = renderSettingDouble(n,3);
                for(int x = 0;x<5;x++) {
                    settingValueBar[(n*80)+(len*12)+x+8] = font[5][x]<<1;
                }
                break;
            case DB://ranges from 0dB to 120dB
                if(settingValues[n] > 99999) {break;} //outside of printing range
                len = renderSettingDouble(n,4);
                for(int x = 0;x<5;x++) {//dB characters suffix
                    settingValueBar[(n*80)+(len*12)+x+8] = font[36][x]<<1;
                    settingValueBar[(n*80)+(len*12)+6+x+8] = font[66][x]<<1;
                }
                break;
            case MULTI:

                break;
        }
    }
}
int renderSettingDouble(int n,int precision) {//used to render the setting values array into a 640x8 bar
    char s[50] = {' '};
    gcvt(settingValues[n],precision,s); //false error, definded in <stdio>
    //sprintf(s, "%d",(int)settingValues[0]);//
    uint8_t len = strlen(s);
    for(int c = 0;c<len;c++) {
        for(int x = 0;x<5;x++) {
            int16_t eightBit = font[s[c] - 32][x];
            int16_t out = eightBit;
            out ^= (out & 0x00F0) << 4;
            out &= ~0x00F0;
            out ^= (out & 0x0C0C) << 2;
            out &= ~0x0C0C;
            out ^= (out & 0x2222) << 1;
            out &= ~0x2222;
            out ^= out << 1;
            int pos = (n*80)+(c*12)+(x*2)+8;
            for(int w = 0;w<2;w++){
                settingValueBar[pos+w] = out;
            }
        }
    }
    return len;
}

void renderSettingPercs(void) {//used to render dials bar
    for(int n = 0;n<8;n++) {
        int pos;
        pos = (n*80)+8;
        for(int i=0;i<32;i++) {
            settingIconBar[pos+i] = dials[((int)settingPercs[n])/2][i];
        }
    }
}


void renderWave(float cutoff,enum pass hilo) {//filter curve rendering based off https://www.desmos.com/calculator/nknvpcqfcm
    float order = 40;
    for(int i = 0;i<80;i++) {
        float response = 31.9f/(1.0f+pow(((i)/cutoff),((float)hilo*order/3.0f)));
        waveBar[i] = (0x1 << (int) (response));
    }
    
    drawString(180,10,settingMulti[0][(hilo+1)/2],WHITE,BLACK,2);
}


