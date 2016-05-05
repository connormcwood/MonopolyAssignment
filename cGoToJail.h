#pragma once
#include "cSquare.h"
const int jailFee = 50;

class cGoToJail :
	public cSquare
{
public:
	//Constructor Of The GoToJail Class. Takes In Two Extra Parameter In Comparison To cSquare.
	cGoToJail(int identificationNum, string cardName, string secondName, string thirdName) : cSquare(identificationNum, cardName)
	{
		//The Extra Two Parameters Are Joined With The cardName Parameter To Create A First,Second And Third Name (GoToJail Has 3 Names)
		setName(cardName, secondName, thirdName);
	}
	virtual void do_method(cPlayer&, cPlayer&);
	void setIdentificationNum(int);
	int getIdentifcaitonNum();
	virtual ~cGoToJail();
};

