#include "cPlayer.h"

//This Is The Constructor For The Class File
//It Creates It's Name, Balance And Its Location.
cPlayer::cPlayer(string inputPlayerName, float inputPlayerBalance, int inputCurrentLocation)
{
	setPlayerBalance(inputPlayerBalance);
	setPlayerName(inputPlayerName);
	setPosition(inputCurrentLocation);
}
//Sends The Address To OwnedProperties Array
void cPlayer::setPropertyOwnership(cSquare* cPropertyAddress)
{
	vOwnedProperties.push_back(cPropertyAddress);
}
//Sets A Mortgage Using A Address
void cPlayer::setMortgage(cSquare* cMortgageAddress)
{
	vMortgageProperties.push_back(cMortgageAddress);
}
//Retrieves Address Of Property
cSquare* cPlayer::getProperties(int input)
{
	return vOwnedProperties[input];
}
//Retrieves Address Of Mortgage
cSquare* cPlayer::getMortages(int input)
{
	return vMortgageProperties[input];
}
//Retrieves Properties Amount
int cPlayer::getPropertiesAmount()
{
	return vOwnedProperties.size();
}
//Retrieves The Size Of Mortgage
int cPlayer::getMortageAmount()
{
	return vMortgageProperties.size();
}
//Removes A Vector Of Mortgage
void cPlayer::removeMortage()
{
	vMortgageProperties.erase(vMortgageProperties.begin());
}
//Sets The Player's Name To The Inputted Value
void cPlayer::setPlayerName(string inputPlayerName)
{
	playerName = inputPlayerName;
}
//Sets The Player's Balance To The Inputted Value
void cPlayer::setPlayerBalance(float inputPlayerBalance)
{
	playerBalance = inputPlayerBalance;
}
//Sets The Player's Position To The Inputted Value
void cPlayer::setPosition(int inputPlayerPosition)
{
	currentPosition = inputPlayerPosition;
}
//Returns The Player's Balance
string cPlayer::getPlayerName()
{
	return playerName;
}
//Returns The Player's Balance
float cPlayer::getPlayerBalance()
{
	return playerBalance;
}
//Returns The Player's Position
int cPlayer::getCurrentPosition()
{
	return currentPosition;
}

cPlayer::~cPlayer()
{
}
