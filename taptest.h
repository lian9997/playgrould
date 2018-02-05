#pragma once
#include "lian.h"

namespace taptest
{
    BOOL started;

    void init()
    {

		CircuitPlayground.clearPixels();
        CircuitPlayground.setAccelTap(2, 64);
        started = true;
    }

    void quit()
    {

        started = false;
    }

    void action(DWORD message)
    {
        if(!started)
        {
            init();
        }
        else
        {
            if(CircuitPlayground.getAccelTap() || message & LEFT_BUTTON)
            {
                for(WORD i = 0;i < sizeof(unsigned long);i++)
		            CircuitPlayground.setPixelColor(i, 0xff00ff);
            }
            if(message & RIGHT_BUTTON)
            {
		        CircuitPlayground.clearPixels();
            }
        }
    }

}
