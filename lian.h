#pragma once

#include <Adafruit_Circuit_Playground.h>
#include <Adafruit_CircuitPlayground.h>


#define PIN_00        0b00000000000000000000000000000001
#define PIN_01        0b00000000000000000000000000000010
#define PIN_02        0b00000000000000000000000000000100
#define PIN_03        0b00000000000000000000000000001000
#define SWITCH        0b00000000000000000000000000010000
#define DOUBLE_TAP    0b00000000000000000000000000100000
#define PIN_06        0b00000000000000000000000001000000
#define LEFT_BUTTON   0b00000000000000000000000010000000
#define RIGHT_BUTTON  0b00000000000000000000000100000000
#define PIN_09        0b00000000000000000000001000000000
#define PIN_10        0b00000000000000000000010000000000
#define RESERVE_01    0b00000000000000000000100000000000
#define PIN_12        0b00000000000000000001000000000000

#define PROGRAM_MENU  0x1
#define PROGRAM_1     0x2
#define PROGRAM_2     0x3
#define PROGRAM_3     0x4
#define PROGRAM_4     0x5
#define PROGRAM_NUMBER 4

#define MAX_WORD 0xffff
#define DEF_COLOR 0xffffff
#define MAX_TEMP 55.0
#define BRIGHT_NESS 255
#define NEO_SIZE 10

typedef uint32_t DWORD;
typedef uint32_t COLOR;
typedef uint16_t WORD;
typedef uint8_t  BYTE;
typedef int BOOL;

DWORD state;
DWORD program;

#include "message.h"