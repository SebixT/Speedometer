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

//-------Funkcje obs³ugi transmisji do hc595-------//
void initDisplay();

//--------Funkcje w³¹czaj¹ce-wy³¹czajace cyfry--------//
void digit1Run();
void digit2Run();
void digit3Run();

#endif /* THREETIMESSEVENSEGDISP_H_ */