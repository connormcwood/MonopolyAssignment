#pragma once
#include "cSquare.h"
//Penalty Consts
const int foodbill = 20;
const int phonebill = 50;
const int heatingbill = 100;
const int vehiclebill = 150;
const int fuelbill = 200;
const int windfalltax = 300;
class cPenalty :
	public cSquare
{
public:
	//Uses The Default cSquare Constructor Parameters. No Additional Parameters Needed For Penalty.
	cPenalty(int identificationNum, string cardName) : cSquare(identificationNum, cardName){}
	virtual void do_method(cPlayer&, cPlayer&);
	virtual ~cPenalty();
};

