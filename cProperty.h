#pragma once
#include "cSquare.h"

#include <string>
#include <iostream>

using namespace std;
class cProperty :
	public cSquare
{
private:
	int propertyCost;
	int propertyRent;
	int propertyColour;

public:
	//Constructor Of The Property Class. Takes In Four Extra Parameters In Comparison To cSquare.
	cProperty(int identificationNum, string cardName, string secondName, int propertyCost, int propertyRent, int propertyColour) : cSquare(identificationNum, cardName)
	{
		//One Of The Extra Parameters Are Used To Set The Name
		setName(cardName, secondName);
		//Another Is Used To Create The Cost
		setPropertyCost(propertyCost);
		//Another Is Used To Create The Rent
		setPropertyRent(propertyRent);
		//Another Is Used To Create The Colour
		setPropertyColour(propertyColour);
		//This Is Used To Set The Ownership Of The Property
	}
	virtual void do_method(cPlayer&, cPlayer&);
	void setPropertyCost(int);
	void setPropertyColour(int);
	void setPropertyRent(int);
	bool otherPlayerOwnSquare(cPlayer&);
	bool thisPlayerOwnSquare(cPlayer&);
	bool otherPlayerMortgageProperty(cPlayer& otherPlayerName);
	int getIdentificationNum();
	int getPropertyCost();
	int getPropertyRent();
	int getPropertyColour();
	virtual ~cProperty();
};

