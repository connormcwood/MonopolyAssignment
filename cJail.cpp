#include "cJail.h"

//This Is The Do_Method Which All Dervied Classes Of cSquare Have
void cJail::do_method(cPlayer& playerName, cPlayer& otherPlayerName){
	//Retrieves The Class Of The Player And Outputs Their Name And Outputs This Classes Name
	cout << "<" << playerName.getPlayerName() << "> lands on " << this->printName() << "" << endl;
	//Outputted When Player Lands On Jail
	cout << "<" << playerName.getPlayerName() << ">" << " Is Just Visting" << endl;
}
cJail::~cJail()
{
}
