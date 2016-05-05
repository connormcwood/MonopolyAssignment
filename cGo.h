#pragma once
#include "cSquare.h"
class cGo :
	public cSquare
{
public:
	//Uses The Default cSquare Constructor Parameters. No Additional Parameters Needed For Go.
	cGo(int identificationNum, string cardName) : cSquare(identificationNum, cardName) {}
	virtual void do_method(cPlayer&, cPlayer&);
	virtual ~cGo();
};

