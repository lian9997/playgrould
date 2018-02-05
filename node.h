

#define MINUTE 60000


#define B5      988
#define Bb5     932
#define A5      880
#define Ab5     831
#define G5      784
#define Gb5     740
#define F5      698
#define E5      659
#define Eb5     622
#define D5      587
#define Db5     554
#define C5      523
#define B4      494
#define Bb4     466
#define A4      440
#define Ab4     415
#define G4      392
#define Gb4     370
#define F4      349
#define E4      330
#define Eb4     311
#define D4      294
#define Db4     277
#define C4      262
#define B3      247
#define Bb3     233
#define A3      220
#define Ab3     208
#define G3      196
#define Gb3     185
#define F3      175
#define E3      165
#define Eb3     156
#define D3      147
#define Db3     139
#define C3      131



#define B0      31
#define C1      33
#define CS1     35
#define D1      37
#define DS1     39
#define E1      41
#define F1      44
#define FS1     46
#define G1      49
#define GS1     52
#define A1      55
#define AS1     58
#define B1      62
#define C2      65
#define CS2     69
#define D2      73
#define DS2     78
#define E2      82
#define F2      87
#define FS2     93
#define G2      98
#define GS2     104
#define A2      110
#define AS2     117
#define B2      123



#define C6      1047
#define CS6     1109
#define D6      1175
#define DS6     1245
#define E6      1319
#define F6      1397
#define FS6     1480
#define G6      1568
#define GS6     1661
#define A6      1760
#define AS6     1865
#define B6      1976
#define C7      2093
#define CS7     2217
#define D7      2349
#define DS7     2489
#define E7      2637
#define F7      2794
#define FS7     2960
#define G7      3136
#define GS7     3322
#define A7      3520
#define AS7     3729
#define B7      3951
#define C8      4186
#define CS8     4435
#define D8      4699
#define DS8     4978


#ifdef MAJ_C

#define u3Re  D8
#define u3Do  C8

#define u3Ti  B7
#define u3La  A7
#define u3So  G7
#define u3Fa  F7
#define u3Mi  E7
#define u3Re  D7
#define u3Do  C7

#define u2Ti  B6
#define u2La  A6
#define u2So  G6
#define u2Fa  F6
#define u2Mi  E6
#define u2Re  D6
#define u2Do  C6


#define uTi  B5
#define uLa  A5
#define uSo  G5
#define uFa  F5
#define uMi  E5
#define uRe  D5
#define uDo  C5

#define Ti  B4
#define La  A4
#define So  G4
#define Fa  F4
#define Mi  E4
#define Re  D4
#define Do  C4

#define dTi B3
#define dLa A3
#define dSo G3
#define dFa F3
#define dMi E3
#define dRe D3
#define dDo C3


#define d2Ti B2
#define d2La A2
#define d2So G2
#define d2Fa F2
#define d2Mi E2
#define d2Re D2
#define d2Do C2


#define d3Ti B1
#define d3La A1
#define d3So G1
#define d3Fa F1
#define d3Mi E1
#define d3Re D1
#define d3Do C1


#define d4Ti B0

#endif


#ifdef MAJ_D

#define u4Do  D8

#define u3Ti  CS8
#define u3La  B7
#define u3So  A7
#define u3Fa  G7
#define u3Mi  FS7
#define u3Re  E7
#define u3Do  D7


#define u2Ti  ES7
#define u2La  B6
#define u2So  A6
#define u2Fa  G6
#define u2Mi  FS6
#define u2Re  E6
#define u2Do  D6



#define uTi  CS6
#define uLa  B5
#define uSo  A5
#define uFa  G5
#define uMi  Gb5
#define uRe  E5
#define uDo  D5

#define Ti  Db5
#define La  B4
#define So  A4
#define Fa  G4
#define Mi  Gb4
#define Re  E4
#define Do  D4

#define dTi  Db4
#define dLa  B3
#define dSo  A3
#define dFa  G3
#define dMi  Gb3
#define dRe  E3
#define dDo  D3

#endif

typedef struct NODE 
{
    WORD tone;
    WORD length;
};