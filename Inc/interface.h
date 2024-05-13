#ifndef INTERFACE_H
#define INTERFACE_H

#include "main.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

extern int16_t screen[10][10];

extern char *settingNames[8];
extern double settingValues[8];
extern double settingPercs[8];
//extern char *settingMulti[4];

enum valueType{INT,FREQ,TIME,PERC,DB,MULTI};
extern enum valueType settingTypes[8];
enum pass{HIGH = -1,LOW = 1};

//rendering bars
extern int8_t settingNameBar[640];
extern int16_t settingValueBar[640];
extern int32_t settingIconBar[640];
extern int64_t waveBar[160];


void setSettingName(char *name,int pos);
void setSettingType(enum valueType type,int pos);
void setSettingValue(float value,int pos);
void setSettingPerc(float value,int pos);
void setSetting(int pos,char *name,enum valueType type,int value);
//void setSettingMulti(char *multi,int pos);

void renderSettingNames(void);
void renderSettingValues(void);
void renderSettingPercs(void);
int renderSettingDouble(int n,int precision);
void renderWave(float cutoff,enum pass hilo);



#endif