#include <Adafruit_Circuit_Playground.h>
#include <Adafruit_CircuitPlayground.h>
#include <EEPROM.h>
#include "lian.h"
#include "beep.h"
#include "menu.h"
#include "light.h"
#include "beephit.h"
#include "taptest.h"


void setup() {
	CircuitPlayground.begin();
  CircuitPlayground.setBrightness(BRIGHT_NESS);
  
	program = PROGRAM_MENU;
	menu::started = false;
	light::started = false;
	beep::started = false;
  beephit::started = false;
  taptest::started = false;
}

void loop() {

  float temp = CircuitPlayground.temperature();

  if(temp > MAX_TEMP)
  {
    program = PROGRAM_MENU;
  }
  
	DWORD message = getMessage();

	switch(program)
	{
    case PROGRAM_4 :
      taptest::action(message);
      break;
    case PROGRAM_3 :
      beephit::action(message);
      break;
		case PROGRAM_2 :
			beep::action(message);
			break;
		case PROGRAM_1 :
			light::action(message);
			break;
		case PROGRAM_MENU:
			{
				menu::action(message);
			}
      break;
	}
}
