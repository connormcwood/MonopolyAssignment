#include "cSquare.h"

//Tells Derived Classes That This Is A Base Class And You Should Expect Atleast identificationNum & cardName to appear.
cSquare::cSquare(int identificationNum, string cardName) : identificationNum(identificationNum), cardName(cardName){}

string cSquare::getName()
{
	return cardName;
}
//Used To Set The Name Of A Class (Takes Only One Parameter)
void cSquare::setName(string inputName)
{
	cardName = inputName;
}
//Used To Set The Name Of A Class (Takes Two Parameter) Overloaded Method
void cSquare::setName(string inputFirstName, string inputSecondName)
{
	cardName = inputFirstName + " " + inputSecondName;
}
//Used To Set The Name Of A Class (Takes Three Parameter) Overloaded Method
void cSquare::setName(string inputFirstName, string inputSecondName, string inputThirdName)
{
	cardName = inputFirstName + " " + inputSecondName + " " + inputThirdName;
}
//Used To Set The IdentificationNum Of A Class
void cSquare::setIdentificationNum(int inputIdentificationNum)
{
	identificationNum = inputIdentificationNum;
}
//Used To Retrieve The IdentificationNum Of A Class
int cSquare::getIdentificationNum()
{
	return identificationNum;
}
cSquare::~cSquare()
{
}
