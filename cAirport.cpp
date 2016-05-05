#include "cAirport.h"

//Retrieves The Airports' Owner's Name
string cAirport::getOwner()
{
	return airportOwner;
}

//Sets The Airports' Owner's Name
void cAirport::setAirportOwner(string inputOwner)
{
	airportOwner = inputOwner;
}

//This Is The Do_Method Which All Dervied Classes Of cSquare Have
void cAirport::do_method(cPlayer& playerName, cPlayer& otherPlayerName)
{
	//Outputs Users Name By Retieving Their Name And Outputs This Classes Name Using Print Name Function(Uses This Because It Is A Pointer)
	cout << "<" << playerName.getPlayerName() << "> lands on <" << this->printName() << ">" << endl;
	//Automatically Purchases Airport
	if (this->getOwner() == "None")
	{
		//Charges The Player
		playerName.setPlayerBalance(playerName.getPlayerBalance() - airportCost);
		//Outputs Information For Players
		cout << "<" << playerName.getPlayerName() << "> buys <" << this->printName() << "> for <" << char(156) << airportCost << ">" << endl;
		//Gives Player Ownership
		this->setAirportOwner(playerName.getPlayerName());
	}
	//Already Owned By Player
	else if (this->getOwner() == playerName.getPlayerName())
	{
		//Do Nothing
	}
	//Owned By Other Player
	else
	{
		//Charge Player
		playerName.setPlayerBalance(playerName.getPlayerBalance() - airportFee);
		//Output Information For Players
		cout << "<" << playerName.getPlayerName() << "> pays " << char(156) << airportFee << " of goods" << endl;
		//Give Owner Player Money
		otherPlayerName.setPlayerBalance(otherPlayerName.getPlayerBalance() + airportFee);
	}
}
cAirport::~cAirport()
{
}
