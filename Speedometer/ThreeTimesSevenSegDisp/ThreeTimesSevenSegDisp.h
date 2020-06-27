/*
 * ThreeTimesSevenSegDisp.h
 *
 * Created: 2020-03-29 19:52:20
 *  Author: Sebastian
 */ 


#ifndef THREETIMESSEVENSEGDISP_H_
#define THREETIMESSEVENSEGDISP_H_

#define DIGIT1 PC0
#define DIGIT2 PC1
#define DIGIT3 PC2

//------- 7-segment display init -------//
void initDisplay();

//-------- Functions to turn on/off single digit --------//
void digit1Run();
void digit2Run();
void digit3Run();

#endif /* THREETIMESSEVENSEGDISP_H_ */