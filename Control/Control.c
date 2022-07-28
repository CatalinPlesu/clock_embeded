#include "Control.h"

DisplayComponent displayState = DisplayClock;
DisplayMode displayMode = DisplayView;

void ControlInit()
{
    PORT_DIRECTION_LEDS = 0x1F;
}

void DisplayCurrentComponent()
{
}
