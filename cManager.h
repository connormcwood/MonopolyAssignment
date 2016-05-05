#include "cAirport.h"
#include "cBonus.h"
#include "cFreeParking.h"
#include "cGo.h"
#include "cGoToJail.h"
#include "cJail.h"
#include "cPenalty.h"
#include "cProperty.h"

#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream> 
#include <vector>

using namespace std;

const int passingGoWindfall = 200;
const int fileSize = 26;
const int amountOfRounds = 40;
const int seedFileSize = 1;

class cManager
{

public:
	cManager(vector<cSquare*>&); //Creates Game Using
	void retrieveFile(vector<cSquare*>&);
	int stringToInt(const string &convertString);
	int retrieveSeed();
	int random();
	bool isOdd(int);
	void squareLocation(int playerLocation, cPlayer& playerName, cPlayer& otherPlayerName, vector<cSquare*>&);
	void diceLocationMove(int, int, cPlayer&);
	void roll(int[]);
	void checkPlayerBalance(cPlayer&);
	void clearMemory(vector<cSquare*>&);
	virtual ~cManager();
};

