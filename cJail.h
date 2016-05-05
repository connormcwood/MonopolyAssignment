#pragma once
#include "cSquare.h"
class cJail :
	public cSquare
{
public:
	//Uses The Default cSquare Constructor Parameters. No Additional Parameters Needed For Jail.
	cJail(int identificationNum, string cardName) : cSquare(identificationNum, cardName){}
	virtual void do_method(cPlayer&, cPlayer&);
	virtual ~cJail();
};

