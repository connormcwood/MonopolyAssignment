#include "cBonus.h"

//This Is The Do_Method Which All Dervied Classes Of cSquare Have
void cBonus::do_method(cPlayer& playerName, cPlayer& otherPlayerName)
{
	cout << "<" << playerName.getPlayerName() << "> lands on " << this->printName() << endl;
	//Retreives Random Number
	int random = rand() % 6;
	
	//Outputs The Information So A User Knows What They Have Got And How Much (Decided By The Random Above)
	//Increments Money Based On The Type Of Bonus They Recevied.
	// Calls For The Player's Balance To Be Set At Their Current Balance Plus Whatever Bonus They End Up With
	if (random == 0)
	{
		cout << "<" << playerName.getPlayerName() << "> Finds Some Money. Player Gains " << char(156) << findmoney << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() + findmoney);
	}
	else if (random == 1)
	{
		cout << "<" << playerName.getPlayerName() << "> Win Competition. Player Gains " << char(156) << wincompetition << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() + wincompetition);
	}
	else if (random == 2)
	{
		cout << "<" << playerName.getPlayerName() << "> Tax Rebate. Player Gains " << char(156) << taxrebate << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() + taxrebate);
	}
	else if (random == 3)
	{
		cout << "<" << playerName.getPlayerName() << "> Wins Lottery. Player Gains " << char(156) << winlottery << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() + winlottery);
	}
	else if (random == 4)
	{		
		cout << "<" << playerName.getPlayerName() << "> Bequest. Player Gains " << char(156) << bequest << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() + bequest);
	}
	else if (random == 5)
	{
		cout << "<" << playerName.getPlayerName() << "> Birthday. Player Gains " << char(156) << birthday << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() + birthday);
	}
}
cBonus::~cBonus()
{
}
