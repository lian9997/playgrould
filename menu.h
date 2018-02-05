#pragma once
#include "lian.h"

namespace menu {
	BOOL started;
	int selected;
	int programs[PROGRAM_NUMBER];
	void init()
	{
		selected = 0;
		programs[0] = PROGRAM_1;
		programs[1] = PROGRAM_2;
		programs[2] = PROGRAM_3;
		programs[3] = PROGRAM_4;
		CircuitPlayground.clearPixels();
		started = true;
	}
	void action(DWORD message)
	{
		if(!started)
		{
			init();
		}
		else
		{
			if(message & RIGHT_BUTTON)
			{
				CircuitPlayground.clearPixels();
				if(++selected == PROGRAM_NUMBER)
					selected = 0;
			}
			else if (message & LEFT_BUTTON)
			{
				started = false;
				program = programs[selected];
			}
			CircuitPlayground.setPixelColor(selected, 0xffffff);
		}
	}
}

