#pragma once
#include "lian.h"
#define MUSIC "1155665.4433221."
#define MUSIC_LENGTH 16

namespace beep 
{
	WORD nodes[7] = {262,294,330,349,392,440,493};
	BOOL started;
	DWORD time_start;
	unsigned long tone_start;
	int pos;
	void init() 
	{
		time_start = millis();
		tone_start = 0;
		started = true;
		pos = 0;
		pinMode(5, OUTPUT);
		CircuitPlayground.clearPixels();
		CircuitPlayground.setPixelColor(0, 0xff00ff);
		CircuitPlayground.setPixelColor(9, 0xff00ff);
	}
	void quit()
	{
		noTone(5);	
		started = false;
	}

	WORD getTone(char c)
	{
		if(c == '.')
			return 0;
		return (nodes[c-'1']);

	}

	void action(DWORD message) 
	{
		if(!started)
		{
			init();
		}
		else
		{	
			if(millis() - tone_start > 500)
			{ 
				if(pos < MUSIC_LENGTH)
				{
					tone_start = millis();
					tone(5, getTone(MUSIC[pos++]));
				}
				else
				{
					noTone(5);
				}
			}
			if(message & LEFT_BUTTON)
			{	
				tone_start = 0;
				pos = 0;
			}

			if(message & RIGHT_BUTTON)
			{
				quit();
				program = PROGRAM_MENU;
			}
		}
	}
}

