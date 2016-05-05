#include "cSquare.h"
#include "cManager.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <istream>
#include <sstream>
#include <vector>
#include <ctime>
#include <stack>
#include <list>
#include <memory>

using namespace std;

int main(){	
	//Vector Of Pointers Of Base Class cSquare
	vector<cSquare*> vSquareVector; 
	//Class's Constructor Creates Game
	cManager GameManager(vSquareVector);

	//Displays Memorys Leaks
	_CrtDumpMemoryLeaks();

	//Waits For User Input
	system("pause");

}