#pragma once
#include "lian.h"

BOOL myxor(DWORD, DWORD);


DWORD getMessage() 
{
	DWORD message = 0;

	if(myxor((state & SWITCH),  CircuitPlayground.slideSwitch()))
	{
		state = state ^ SWITCH;
		if((state & SWITCH))
			message += SWITCH;
	}
	if(myxor((state & LEFT_BUTTON),  CircuitPlayground.leftButton()))
	{
		state = state ^ LEFT_BUTTON;
		if((state & LEFT_BUTTON))
			message += LEFT_BUTTON;
	}
	if(myxor((state & RIGHT_BUTTON),  CircuitPlayground.rightButton()))
	{
		state = state ^ RIGHT_BUTTON;
		if((state & RIGHT_BUTTON))
			message += RIGHT_BUTTON;
	}
	if(myxor((state & DOUBLE_TAP),  CircuitPlayground.getAccelTap()))
	{
		state = state ^ DOUBLE_TAP;
		if((state & DOUBLE_TAP))
			message += DOUBLE_TAP;
	}
	// will be more messages
	return message;
}

BOOL myxor(DWORD l, DWORD r) {
	if(l&&!r)
		return 1;
	if(!l&&r)
		return 1;
	return 0;
}
