#ifndef CPLAYER_H
#define CPLAYER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cSquare;

class cPlayer
{
private:
	string playerName;
	float playerBalance;
	int currentPosition;
	vector<cSquare*> vOwnedProperties;
	vector<cSquare*> vMortgageProperties;
	cSquare* cPropertyAddress;

public:
	cPlayer(string, float, int);
	void setPlayerName(string);
	void setPlayerBalance(float);
	void setPropertyOwnership(cSquare*);
	void setMortgage(cSquare*);
	void removeMortage();
	int getPropertiesAmount();
	int getMortageAmount();
	cSquare* getMortages(int);
	cSquare* getProperties(int);
	void setPosition(int);
	string getPlayerName();
	float getPlayerBalance();
	int getCurrentPosition();
	virtual ~cPlayer();
};
#endif