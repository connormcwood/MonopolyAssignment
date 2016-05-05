#pragma once
#include "cSquare.h"

const int airportCost = 200;
const int airportFee = 10;
class cAirport :
	public cSquare
{
private:
	string airportOwner;
public:
	//Constructor Of The Airport Class. Takes In One Extra Parameter In Comparison To cSquare.
	cAirport(int identificationNum, string cardName, string secondName) : cSquare(identificationNum, cardName){
		{
			//The Extra Parameter Is Joined With The cardName Parameter To Create A First And Second Name (Airports Have 2 Names)
			setName(cardName, secondName);
			//Used To Give Ownership To No One Until Purchased.
			airportOwner = "None";
		}
	}
	virtual void do_method(cPlayer&, cPlayer&);
	void setAirportOwner(string);
	string getOwner();
	virtual ~cAirport();
};

