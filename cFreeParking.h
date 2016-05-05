#pragma once
#include "cSquare.h"
class cFreeParking :
	public cSquare
{
private: 
	float freeParkingAmount;

public:
	//Constructor Of The FreeParking Class. Takes In One Extra Parameter In Comparison To cSquare.
	cFreeParking(int identificationNum, string cardName, string secondName) : cSquare(identificationNum, cardName)
{	
		//The Extra Parameter Is Joined With The cardName Parameter To Create A First And Second Name (FreeParking Has 2 Names)
		setName(cardName, secondName);
		//Initalises The Amount To Zero.
		freeParkingAmount = 0.00;
	}
	virtual void do_method(cPlayer&, cPlayer&);
	void setFreeParkingAmount(float);
	float getFreeParkingAmount();
	virtual ~cFreeParking();
};

