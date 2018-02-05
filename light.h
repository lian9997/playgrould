#pragma once
#include "lian.h"

namespace light 
{
	BOOL started;
	DWORD *color;
	int currNeo;
	void init()
	{
		color = new DWORD[NEO_SIZE];
		currNeo = 0;
		for(int i = 0;i < NEO_SIZE;i++)
			color[i] = (uint32_t)DEF_COLOR;
		for (int pixel=0; pixel<NEO_SIZE; pixel++) 
			CircuitPlayground.setPixelColor(pixel, color[pixel]);
		started = true;
	}

	void quit()
	{
		started = false;
		delete color;
		color = 0;
	}

	void action(DWORD message)
	{
		if(!started)
		{
			init();
		}
		else
		{
			if((state & ~SWITCH) << 16) 
				digitalWrite(13, HIGH);
			else 
				CircuitPlayground.redLED(false);

			if((state & SWITCH))
			{
				//read button;
				if(message & LEFT_BUTTON)
					color[currNeo] = color[currNeo] * 2;

				if(message & RIGHT_BUTTON)
					color[currNeo] = color[currNeo] * 2 + 1;
			}
			else
			{
				if(message & RIGHT_BUTTON)
					if(++currNeo == NEO_SIZE)
						currNeo = 0;
				if(message & LEFT_BUTTON)
					if(--currNeo == -1)
						currNeo = NEO_SIZE - 1;
			}
			//set neo 
			for (int pixel = 0; pixel < currNeo; pixel++) {
				CircuitPlayground.setPixelColor(pixel, color[pixel]);
			}
			//blink selected Neo 
			CircuitPlayground.setPixelColor(currNeo,state & SWITCH || millis() % 1000 > 500 ? color[currNeo]: 0x0);
			for (int pixel = currNeo + 1; pixel < NEO_SIZE; pixel++) {
				CircuitPlayground.setPixelColor(pixel, color[pixel]);
			}
			/*
			   if(message & LEFT_BUTTON) 
			   {
			   program = PROGRAM_MENU;
			   quit();
			   }*/
			//can not exot now

		}//started - else
	}//action

}//namespace


