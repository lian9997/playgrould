#pragma once
#include "lian.h"

#define QUEUE_SZIE 5
#define INIT_SCORE 2000


#define MAJ_D
#include "node.h"

#define BPM 92
#define QUATER  (MINUTE / BPM)
#define MIN_BEAT (QUATER/4)

#define Q 4

#define RED     0xff0000
#define ORANGE  0xff3300
#define YELLOW  0xcccc00
#define GREEN   0x00ff00
#define CYAN    0x00cccc
#define BLUE    0x0000ff
#define VILOET  0xcc00cc
#define WHITE   0xffffff
#define DARK    0x101010
#define BLACK   0x000000

#define COLOR_INDEX_SIZE 8

#ifdef MUSIC_LENGTH
#undef MUSIC_LENGTH
#endif
#define MUSIC_LENGTH 20

namespace beephit
{
    BOOL started;
    
    COLOR neoColors[NEO_SIZE];
    COLOR leftQueue[QUEUE_SZIE];
    COLOR rightQueue[QUEUE_SZIE];
	WORD  colorState;
    WORD  passedMinBeat;
    WORD  colorDisp;

	DWORD tone_start;
    DWORD beat_start;
    WORD  pos;

    DWORD score;
    BOOL  hasHit;



    const NODE SONG[MUSIC_LENGTH] = 
    {
      {  Mi  ,   Q/4    },
      {  Re  ,   Q/4    },
      {  Mi  ,   Q/4    },
      {  Fa  ,   Q/4    },

      {  La  ,   Q/4    },
      {  So  ,   Q/4    },
      {  uDo ,   Q/4    },
      {  La  ,   Q/4    },
        
      {  So  ,   Q/4    },
      {  Mi  ,   Q/4    },
      {  So  ,   Q      },
      {  La  ,   Q/2    },
        
      {  uDo ,   Q/2    },
      {  uRe ,   Q/4    },
      {  uMi ,   Q/4    },

      {  uRe ,   Q/4    },
      {  uDo ,   Q/4    },
      {  La  ,   Q/4    },
      {  uDo ,   Q/4    },

      { So  ,   Q*2     }
        /*
        uRe ,   Q,
        uRe ,   Q,
        uRe ,   Q,
        uRe ,   Q,
        */
    };

    COLOR colorIndex[COLOR_INDEX_SIZE] = {
        WHITE ,
        RED   ,
        ORANGE,
        YELLOW,
        GREEN ,
        CYAN  ,
        BLUE  ,
        VILOET
        };
    /*
    SONG[pos-1] is freq of played Tone. 
    SONG[pos]   is the time of the tone will play. 
    pos % 2 == 0 only when not playing.
    */

    void init()
    {
        pos = MAX_WORD;
        colorState = 1;
		CircuitPlayground.clearPixels();
        for(int i = 0;i < NEO_SIZE;i++)
            neoColors[i] = BLACK;
        started = true;
    }

    void quit()
    {
		noTone(5);	
        started = false;
    }

    DWORD inline getEndTime()
    {
        return SONG[pos].length * MIN_BEAT;
    }

    WORD inline getTone()
    {

        return 0;
        return SONG[pos].tone;
    }

    void inline nextNode()
    {
        pos++;
        passedMinBeat = 0;
        if(pos >= MUSIC_LENGTH)
            pos = MAX_WORD;
    }

    WORD inline nodeLength(WORD lpos)
    {
        return SONG[lpos].length;
    }

    BOOL inline toneRise(WORD lpos)
    {
        if(lpos < 1)
        return 0;
        return SONG[lpos].tone > SONG[lpos-1].tone;
    }

    COLOR inline getColor(WORD col)
    {
        
        return col == 1 ? WHITE : colorIndex[ 1 + (col + colorDisp) % (COLOR_INDEX_SIZE - 1)];
    }

    void changeColor()
    {
        if(pos == MAX_WORD)
            return;

        for(int i = 0;i < QUEUE_SZIE;i++)
        {
            leftQueue[i] = rightQueue[i] = BLACK;
        }
        colorDisp = pos;
        colorState = 1;
        WORD lnextpos = pos;
        WORD li = 0;
        
        //first node 
        if(toneRise(lnextpos))
        {
            leftQueue[li] = getColor(colorState++);
            for(int i = li + 1;i < nodeLength(lnextpos) - passedMinBeat;i++)/// - passed beats
            {
                leftQueue[i] = DARK;
            }
        }
        else
        {
            rightQueue[li] = getColor(colorState++);
            for(int i = li + 1;i < nodeLength(lnextpos) - passedMinBeat;i++)
            {
                rightQueue[i] = DARK;
            }
        }
        li += nodeLength(lnextpos) - passedMinBeat;
        lnextpos++;
    //other nodes
        while(li < QUEUE_SZIE && lnextpos < MUSIC_LENGTH)
        {
            if(toneRise(lnextpos))
            {
                leftQueue[li] = getColor(colorState++);
                for(int i = li + 1;i < li + nodeLength(lnextpos) && i < QUEUE_SZIE;i++)
                {
                    leftQueue[i] = DARK;
                }
            }
            else
            {
                rightQueue[li] = getColor(colorState++);
                for(int i = li + 1;i < li + nodeLength(lnextpos)  && i < QUEUE_SZIE;i++)
                {
                    rightQueue[i] = DARK;
                }

            }
            li += nodeLength(lnextpos);
            lnextpos++;
        }
        for(li = 0;li < QUEUE_SZIE;li++)
            neoColors[li] = leftQueue[li];
        for(li = 0;li < QUEUE_SZIE;li++)
            neoColors[NEO_SIZE-1-li] = rightQueue[li];

        passedMinBeat++;
    }

    void showScore()
    {
        if(score)
        {
            colorState = true;
            double floatscore = score / (MUSIC_LENGTH * 199.9);
            for(int i = 0;i < NEO_SIZE;i++)
                neoColors[i] = floatscore > 0.025 * i ? RED : BLACK;

            for(int i = 0;i < NEO_SIZE;i++)
                neoColors[i] = floatscore > 0.25 + 0.025 * i ? YELLOW : neoColors[i];

            for(int i = 0;i < NEO_SIZE;i++)
                neoColors[i] = floatscore > 0.5 + 0.025 * i ? GREEN : neoColors[i];

            for(int i = 0;i < NEO_SIZE;i++)
                neoColors[i] = floatscore > 0.75 + 0.025 * i ? BLUE : neoColors[i];

        }
    }

    void countPoint(DWORD message)
    {
        if(message & LEFT_BUTTON)
        {
            score++;
        }
    }

    void action(DWORD message)
    {

        if(!started)
        {
            init();
        }
        else
        {
            //scheduled move
            if(pos != MAX_WORD)
            {
                if(millis() - tone_start > getEndTime())
			    {
			    	if(pos < MUSIC_LENGTH)
			    	{
                        nextNode();
                 		tone_start = millis();
                        if(getTone())
                            CircuitPlayground.playTone(getTone(), nodeLength(pos) * MIN_BEAT, false);
			    	}
			    	else
			    	{
	                    noTone(5);
                        CircuitPlayground.clearPixels();
                        pos = MAX_WORD;
			    	}
			    }

                if(millis() - beat_start > MIN_BEAT)
                {
                        changeColor();                    
                        beat_start = millis();
                }

                countPoint(message);

            }
            else if(message & LEFT_BUTTON)
            {
                pos = 0;
                colorDisp = 0;
                beat_start = millis();
                score = INIT_SCORE;
                changeColor();
                tone_start = millis();
               // tone(5, getTone());
                CircuitPlayground.playTone(getTone(), nodeLength(pos) * MIN_BEAT, false);
            }
            else if(message & RIGHT_BUTTON)
            {
                program = PROGRAM_MENU;
                quit();
            }
            else
            {
                noTone(5);
                showScore();
            }

            if(colorState)
            {
                colorState = 0;
                for(int i = 0;i < NEO_SIZE;i++)
                {
                    CircuitPlayground.setPixelColor(i, neoColors[i]);
                }
            }
        }
    }
}
/*
purple error

*/