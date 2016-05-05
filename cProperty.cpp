#include "cProperty.h"
//Sets The Property's Colour To The Inputted Value
void cProperty::setPropertyColour(int inputPropertyColour)
{
	propertyColour = inputPropertyColour;
}
//Sets The Property's Cost To The Inputted Value
void cProperty::setPropertyCost(int inputPropertyCost)
{
	propertyCost = inputPropertyCost;
}
//Sets The Property's Rent To The Inputted Value
void cProperty::setPropertyRent(int inputPropertyRent)
{
	propertyRent = inputPropertyRent;
}
//This Is The Do_Method Which All Dervied Classes Of cSquare Have
void cProperty::do_method(cPlayer& playerName, cPlayer& otherPlayerName)
{
	cout << "<" << playerName.getPlayerName() << "> lands on <" << this->printName() << ">" << endl;
	if (thisPlayerOwnSquare(playerName) == true)
	{
		//Owned By Player do Nothing
	}
	// Checks If This Property Is Owned By Someone Else And Also Checks Whether It Is Mortgaged
	else if (otherPlayerOwnSquare(otherPlayerName) == true && otherPlayerMortgageProperty(otherPlayerName) == false)
	{
		
		//Reduces Cost of Renting Property
		playerName.setPlayerBalance(playerName.getPlayerBalance() - this->getPropertyRent());
		//Outputs The Renting Statement For User Feedback
		cout << "<" << playerName.getPlayerName() << "> pays rent <" << char(156) << this->getPropertyRent() << ">" << endl;
		//Gives The Other Player The Money For The Rent
		otherPlayerName.setPlayerBalance(otherPlayerName.getPlayerBalance() + this->getPropertyRent());
	}
	else if (otherPlayerOwnSquare(otherPlayerName) == true && otherPlayerMortgageProperty(otherPlayerName) == true)
	{
		//Property Is Owned However It Is Mortgaged No Charge!
	}
	else
	{
		if (playerName.getPlayerBalance() > this->getPropertyCost())
		{
			//Reduces Cost Of Property From Players Balance
			playerName.setPlayerBalance(playerName.getPlayerBalance() - this->getPropertyCost());
			//Outputs Purchasing Statement For User Feedback
			cout << "<" << playerName.getPlayerName() << "> buys <" << this->getName() << "> for <" << char(156) << this->getPropertyCost() << ">" << endl;
			//Performs The Ownership Exchange Giving The Player's cSquare Pointer Vector The Value of This Property
			playerName.setPropertyOwnership(this);
		}
		else
		{
			//When Square Is Not Owned By Anyone But User Cannot Afford To Buy It
			//Cannot Afford Would Go Under Zero
		}		
	}
}
//Provides True Or False Whether This Square Is Owned By Player
bool cProperty::thisPlayerOwnSquare(cPlayer& playerName)
{
	for (int i = 0; i < playerName.getPropertiesAmount(); i++)
	{
		if (playerName.getProperties(i) == this)
		{
			return true;
		}
	}
	return false;
}
//Provides True Or False Whether This Square Is Owned By Other Player
bool cProperty::otherPlayerOwnSquare(cPlayer& otherPlayerName)
{
	for (int i = 0; i < otherPlayerName.getPropertiesAmount(); i++)
	{
		if (otherPlayerName.getProperties(i) == this)
		{
			return true;
		}
	}
	return false;
}
//Provides True Or False Whether This Square Is Mortgaged By Other Player
bool cProperty::otherPlayerMortgageProperty(cPlayer& otherPlayerName)
{
	for (int i = 0; i < otherPlayerName.getMortageAmount(); i++)
	{
		if (otherPlayerName.getMortages(i) == this )
		{
			return true;
		}
	}
	return false;
}
//Returns The Property's Cost
int cProperty::getPropertyCost()
{
	return propertyCost;
}
//Returns The Property's Colour
int cProperty::getPropertyColour()
{
	return propertyColour;
}
//Returns The Property's Rent
int cProperty::getPropertyRent()
{
	return propertyRent;
}
cProperty::~cProperty()
{
}
