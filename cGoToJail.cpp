#include "cGoToJail.h"

//This Is The Do_Method Which All Dervied Classes Of cSquare Have
void cGoToJail::do_method(cPlayer& playerName, cPlayer& otherPlayerName)
{
	//Uses The Retrieved Player Class To Output Their Name
	//Retrieves Jailfee From Headerfile
	cout << "<" << playerName.getPlayerName() << "> Lands On Go To Jail" << endl;
	cout << "<" << playerName.getPlayerName() << "> Goes To Jail" << endl;
	cout << "<" << playerName.getPlayerName() << "> Pays " << char(156) << jailFee << endl;
	//Sets The Player's Balance To Their Current Balance Minus The Cost Of Jail
	playerName.setPlayerBalance(playerName.getPlayerBalance() - jailFee);
	//Sets The Player's Location To The Location Of Jail (6th In the Vector)
	playerName.setPosition(6);
}
cGoToJail::~cGoToJail()
{
}
