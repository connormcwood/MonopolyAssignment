#include "cFreeParking.h"

//Sets Amount Of Free Parking
void cFreeParking::setFreeParkingAmount(float inputFreeParkingAmount)
{
	freeParkingAmount = inputFreeParkingAmount;
}
//Retrieves Amount Of Free Parking
float cFreeParking::getFreeParkingAmount()
{
	return freeParkingAmount;
}
//This Is The Do_Method Which All Dervied Classes Of cSquare Have
void cFreeParking::do_method(cPlayer& playerName, cPlayer& otherPlayerName)
{
	cout << "<" << playerName.getPlayerName() << "> lands on <" << this->printName() << ">" << endl;
}
cFreeParking::~cFreeParking()
{
}
