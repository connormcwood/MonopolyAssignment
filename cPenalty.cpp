#include "cPenalty.h"
//This Is The Do_Method Which All Dervied Classes Of cSquare Have
void cPenalty::do_method(cPlayer& playerName, cPlayer& otherPlayerName)
{
	cout << "<" << playerName.getPlayerName() << "> lands on " << this->printName() << endl;
	//Retreives Random Number
	int random = rand() % 6;

	//Outputs The Information So A User Knows What They Have Run (Decided By The Random Above)
	//Decreases Money Based On The Type Of Penalty They Recevied.
	//Retrieves All Consts From Headerfile
	if (random == 0)
	{
		cout << "<" << playerName.getPlayerName() << "> Food bill. Player Loses " << char(156) << foodbill << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() - foodbill);
	}
	else if (random == 1)
	{
		cout << "<" << playerName.getPlayerName() << "> Phone bill. Player Loses " << char(156) << phonebill << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() - phonebill);
	}
	else if (random == 2)
	{
		cout << "<" << playerName.getPlayerName() << "> Heating bill. Player Loses " << char(156) << heatingbill << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() - heatingbill);
	}
	else if (random == 3)
	{
		cout << "<" << playerName.getPlayerName() << "> Vehicle bill. Player Loses " << char(156) << vehiclebill << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() - vehiclebill);
	}
	else if (random == 4)
	{
		cout << "<" << playerName.getPlayerName() << "> Fuel bill. Player Loses " << char(156) << fuelbill << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() - fuelbill);
	}
	else if (random == 5)
	{
		cout << "<" << playerName.getPlayerName() << "> Windfall Tax. Player Loses " << char(156) << windfalltax << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() - windfalltax);
	}
}

cPenalty::~cPenalty()
{
}
