#include "cGo.h"

//This Is The Do_Method Which All Dervied Classes Of cSquare Have
void cGo::do_method(cPlayer& playerName, cPlayer& otherPlayerName){
	cout << "<" << playerName.getPlayerName() << "> lands on " << this->printName() << "" << endl;
}
cGo::~cGo()
{
}
