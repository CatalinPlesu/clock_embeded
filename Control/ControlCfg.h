#ifndef CONTROLCFG_H_
#define CONTROLCFG_H_

#include <avr/io.h>

#define PORT_DIRECTION_LED DDRA
#define PORT_LED PORTA
#define PIN_LED_CLOCK PA0
#define PIN_LED_Timer PA1
#define PIN_LED_Alarm PA2
#define PIN_LED_Contdown PA3
#define PIN_LED_Temperature PA4
#define LED_COUNT 5

#define PIN_BUTTON PD0
#define PORT_BUTTON PORTD
#define PORT_DIRECTION_BUTTON DDRD


typedef enum
{
	DisplayClock,
    DisplayTimer,
    DisplayAlarm,
    DisplayContdown,
    DisplayTemperature
}DisplayComponent;

typedef enum
{
    DisplayView,
    DisplaySettings,
}DisplayMode;

typedef struct
{
	uint8_t port;
	uint8_t portDig;
	uint8_t componentsCount;
	uint8_t digitsPinValue[LED_COUNT];
}ControlHandleConfig;


void ControlInit();
void DisplayCurrentComponent();

#endif
