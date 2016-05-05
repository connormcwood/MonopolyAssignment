#pragma once
#include "cSquare.h"
//Bonus Consts
const int findmoney = 20;
const int wincompetition = 50;
const int taxrebate = 100;
const int winlottery = 150;
const int bequest = 200;
const int birthday = 300;
class cBonus :
	public cSquare
{
public:
	//Uses The Default cSquare Constructor Parameters. No Additional Parameters Needed For Bonus.
	cBonus(int identificationNum, string cardName) : cSquare(identificationNum, cardName) 
	{
	}
	virtual void do_method(cPlayer&, cPlayer&);
	virtual ~cBonus();
};

