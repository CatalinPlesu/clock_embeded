/*
 * SevSegCfg.c
 *
 * Created: 7/13/2022 2:49:14 PM
 *  Author: alexei.guriev
 */ 
#include "SevSegCfg.h"

static SevSegHandleConfig disp7SegHandleConfig;

SevSegHandleConfig* SevSegCfgInitAndGet()
{
	disp7SegHandleConfig.port = DISPLAY_7_SEGMENT_PORT;
	disp7SegHandleConfig.portDig = DISPLAY_7_SEGMENT_DIGIT_PORT;
	
	DISPLAY_7_SEGMENT_PORT_DIR = 0xFF;
	
	disp7SegHandleConfig.digitsPinValue[0] = DISPLAY_7_SEGMENT_DIGIT_1_PIN;
	disp7SegHandleConfig.digitsPinValue[1] = DISPLAY_7_SEGMENT_DIGIT_2_PIN;
	disp7SegHandleConfig.digitsPinValue[2] = DISPLAY_7_SEGMENT_DIGIT_3_PIN;
	disp7SegHandleConfig.digitsPinValue[3] = DISPLAY_7_SEGMENT_DIGIT_4_PIN;
		
	DISPLAY_7_SEGMENT_DIGIT_PORT_DIR |= (1 << DISPLAY_7_SEGMENT_DIGIT_1_PIN);
	DISPLAY_7_SEGMENT_DIGIT_PORT_DIR |= (1 << DISPLAY_7_SEGMENT_DIGIT_2_PIN);
	DISPLAY_7_SEGMENT_DIGIT_PORT_DIR |= (1 << DISPLAY_7_SEGMENT_DIGIT_3_PIN);
	DISPLAY_7_SEGMENT_DIGIT_PORT_DIR |= (1 << DISPLAY_7_SEGMENT_DIGIT_4_PIN);
	
	return &disp7SegHandleConfig;
}

void SevSegCfgAllDigitsOff(void)
{
	DISPLAY_7_SEGMENT_DIGIT_PORT |= (1 << DISPLAY_7_SEGMENT_DIGIT_1_PIN);
	DISPLAY_7_SEGMENT_DIGIT_PORT |= (1 << DISPLAY_7_SEGMENT_DIGIT_2_PIN);
	DISPLAY_7_SEGMENT_DIGIT_PORT |= (1 << DISPLAY_7_SEGMENT_DIGIT_3_PIN);
	DISPLAY_7_SEGMENT_DIGIT_PORT |= (1 << DISPLAY_7_SEGMENT_DIGIT_4_PIN);
	
}

void SevSegCfgSetDigitValue(uint8_t value)
{
#if (DISPLAY_7_SEGMENT_MODE == COMUN_POWER_SUPPLY)
	DISPLAY_7_SEGMENT_PORT = ~value;
#else
	DISPLAY_7_SEGMENT_PORT = value;
#endif
}

void SevSegCfgDigitOn(uint8_t digit)
{
	if (digit < DISPLAY_7_SEGMENT_DIGITS_COUNT)
	{
		DISPLAY_7_SEGMENT_DIGIT_PORT &= ~(1 << disp7SegHandleConfig.digitsPinValue[digit]);		
	}	
}

