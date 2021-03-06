/*
 * global.h
 *
 *  Created on: 16 Sep 2019
 *      Author: droggen
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <stdio.h>
#include "command.h"


extern FILE *file_usb,*file_pri,*file_bt,*file_itm,*file_dbg;
extern unsigned char system_devname[];
extern unsigned char sharedbuffer[];
extern unsigned char system_mode;

extern unsigned char __mode_sleep;

#define CONFIG_ADDR_ENABLE_ID 0
#define CONFIG_ADDR_ENABLE_TIMESTAMP 1
#define CONFIG_ADDR_ENABLE_BATTERY 2
#define CONFIG_ADDR_ENABLE_ACCELERATION 3
#define CONFIG_ADDR_ENABLE_GYROSCOPE 4
#define CONFIG_ADDR_ENABLE_CHECKSUM 5
#define CONFIG_ADDR_DATA_FORMAT 6
//#define CONFIG_ADDR_SENSORSR 10
#define CONFIG_ADDR_STREAM_FORMAT 11
#define CONFIG_ADDR_ENABLE_TEMPERATURE 12
#define CONFIG_ADDR_STREAM_BINARY 13
//#define CONFIG_ADDR_ADC_MASK 14
//#define CONFIG_ADDR_ADC_PERIOD0 15
//#define CONFIG_ADDR_ADC_PERIOD1 16
//#define CONFIG_ADDR_ADC_PERIOD2 17
//#define CONFIG_ADDR_ADC_PERIOD3 18
#define CONFIG_ADDR_ENABLE_LCD 19
#define CONFIG_ADDR_TS_PERIOD0 20
#define CONFIG_ADDR_TS_PERIOD1 21
#define CONFIG_ADDR_TS_PERIOD2 22
#define CONFIG_ADDR_TS_PERIOD3 23
#define CONFIG_ADDR_STREAM_LABEL 24
#define CONFIG_ADDR_STREAM_PKTCTR 25
#define CONFIG_ADDR_ENABLE_INFO 26



// Boot script - reserve 100 bytes
#define CONFIG_ADDR_SCRIPTSTART 100
#define CONFIG_ADDR_SCRIPTLEN COMMANDMAXSIZE
#define CONFIG_ADDR_SCRIPTEND (CONFIG_ADDR_SCRIPTSTART+CONFIG_ADDR_SCRIPTLEN-1)

// Storing number of boots
#define STATUS_ADDR_NUMBOOT0	300
#define STATUS_ADDR_NUMBOOT1	301
#define STATUS_ADDR_NUMBOOT2	302
#define STATUS_ADDR_NUMBOOT3	303

// Storing charge status upon soft or hard off
// Address is aligned on a page (32 bytes) to allow contiguous writes)
#define STATUS_ADDR_OFFCURRENT_VALID 512
#define STATUS_ADDR_OFFCURRENT_CHARGE0 (STATUS_ADDR_OFFCURRENT_VALID+1)
#define STATUS_ADDR_OFFCURRENT_CHARGE1 (STATUS_ADDR_OFFCURRENT_VALID+2)
#define STATUS_ADDR_OFFCURRENT_CHARGE2 (STATUS_ADDR_OFFCURRENT_VALID+3)
#define STATUS_ADDR_OFFCURRENT_CHARGE3 (STATUS_ADDR_OFFCURRENT_VALID+4)
#define STATUS_ADDR_OFFCURRENT_VOLTAGE0 (STATUS_ADDR_OFFCURRENT_VALID+5)
#define STATUS_ADDR_OFFCURRENT_VOLTAGE1 (STATUS_ADDR_OFFCURRENT_VALID+6)
#define STATUS_ADDR_OFFCURRENT_TIME (STATUS_ADDR_OFFCURRENT_VALID+7)
#define STATUS_ADDR_OFFCURRENT_TIME_1 (STATUS_ADDR_OFFCURRENT_VALID+8)
#define STATUS_ADDR_OFFCURRENT_TIME_2 (STATUS_ADDR_OFFCURRENT_VALID+9)
#define STATUS_ADDR_OFFCURRENT_TIME_3 (STATUS_ADDR_OFFCURRENT_VALID+10)
/*#define STATUS_ADDR_OFFCURRENT_H (STATUS_ADDR_OFFCURRENT_VALID+10)
#define STATUS_ADDR_OFFCURRENT_M (STATUS_ADDR_OFFCURRENT_VALID+11)
#define STATUS_ADDR_OFFCURRENT_S (STATUS_ADDR_OFFCURRENT_VALID+12)
#define STATUS_ADDR_OFFCURRENT_DAY (STATUS_ADDR_OFFCURRENT_VALID+13)
#define STATUS_ADDR_OFFCURRENT_MONTH (STATUS_ADDR_OFFCURRENT_VALID+14)
#define STATUS_ADDR_OFFCURRENT_YEAR (STATUS_ADDR_OFFCURRENT_VALID+15)*/


// Storing charge status upon power-on
/*#define STATUS_ADDR_ONCURRENT_VALID 530
#define STATUS_ADDR_ONCURRENT_CHARGE0 (STATUS_ADDR_ONCURRENT_VALID+1)
#define STATUS_ADDR_ONCURRENT_CHARGE1 (STATUS_ADDR_ONCURRENT_VALID+2)
#define STATUS_ADDR_ONCURRENT_CHARGE2 (STATUS_ADDR_ONCURRENT_VALID+3)
#define STATUS_ADDR_ONCURRENT_CHARGE3 (STATUS_ADDR_ONCURRENT_VALID+4)
#define STATUS_ADDR_ONCURRENT_VOLTAGE0 (STATUS_ADDR_ONCURRENT_VALID+5)
#define STATUS_ADDR_ONCURRENT_VOLTAGE1 (STATUS_ADDR_ONCURRENT_VALID+6)
#define STATUS_ADDR_ONCURRENT_H (STATUS_ADDR_ONCURRENT_VALID+10)
#define STATUS_ADDR_ONCURRENT_M (STATUS_ADDR_ONCURRENT_VALID+11)
#define STATUS_ADDR_ONCURRENT_S (STATUS_ADDR_ONCURRENT_VALID+12)
#define STATUS_ADDR_ONCURRENT_DAY (STATUS_ADDR_ONCURRENT_VALID+13)
#define STATUS_ADDR_ONCURRENT_MONTH (STATUS_ADDR_ONCURRENT_VALID+14)
#define STATUS_ADDR_ONCURRENT_YEAR (STATUS_ADDR_ONCURRENT_VALID+15)
#define STATUS_ADDR_ONCURRENT_TIME (STATUS_ADDR_ONCURRENT_VALID+16)
#define STATUS_ADDR_ONCURRENT_TIME_1 (STATUS_ADDR_ONCURRENT_VALID+17)
#define STATUS_ADDR_ONCURRENT_TIME_2 (STATUS_ADDR_ONCURRENT_VALID+18)
#define STATUS_ADDR_ONCURRENT_TIME_3 (STATUS_ADDR_ONCURRENT_VALID+19)*/


// MPU related settings - MPU requires ~50 bytes of non-volatile storage
#define CONFIG_ADDR_MPU_SETTINGS 600

unsigned long main_perfbench(unsigned long mintime);

#endif /* GLOBAL_H_ */
