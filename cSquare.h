#ifndef CSQUARE_H
#define CSQUARE_H

#include "cPlayer.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#pragma once
class cSquare
{
protected:
	int identificationNum;
	string cardName;
public:
	//Used To Create The Base Class With The Parameter Of An Int And A String.
	cSquare(int, string);
	//Used So That All Dervied Classes Can Output Their Name(cardName)
	string getName();
	//Tells The Compiler That Each Class Should Have A do_method Method However This One Does Not.
	virtual void do_method(cPlayer&, cPlayer&) = 0;
	//Allows The Class To Individually Call Their Own GetName Method As this Refers To A Pointer
	string printName() { return this->getName(); }
	// Overloading Of The SetName Method Occurs Below. They Take One, Two or Three Parameters And Are Used
	// Different Depending On The Class Which Is Using Them.
	void setName(string);
	void setName(string, string);
	void setName(string, string, string);
	// Used By All Classes To Set The IdentificationNum
	void setIdentificationNum(int);
	// Used To Retrieve The Class' IdentificationNum
	int getIdentificationNum();
	virtual ~cSquare();
};
#endif