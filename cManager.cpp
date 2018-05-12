#include "cManager.h"
#include <algorithm> 
cManager::cManager(vector<cSquare*> &vSquareVector)
{
	vector<cSquare*> vOwnedProperties;

	//Uses A Const To Determine The Amount Of Rounds
	int managerRounds[amountOfRounds];

	//Outputs A Welcoming Message To User
	cout << "Welcome To Monopoly." << endl;

	//Reads The Monopoly.txt File And Creates Pointers Of Classes
	retrieveFile(vSquareVector);

	//Uses The Amount Of Rounds Const To Determine The Random's Length
	roll(managerRounds);

	//Creates The Objects Of cPlayer Class.
	cPlayer Player1("Dog", 300, 0);
	cPlayer Player2("Car", 300, 0);

	//Uses The Amount Of Rounds To Determine Howmany Times To Loop
	for (int i = 0; i < amountOfRounds; i++)
	{
		// Splits Evenly For Each Use(Odd 1 Player , Even The Other)
		if (isOdd(i) == true)
		{
			diceLocationMove(Player1.getCurrentPosition(), managerRounds[i], Player1);
			squareLocation(Player1.getCurrentPosition(), Player1, Player2, vSquareVector);
			checkPlayerBalance(Player1);

		}
		else
		{
			diceLocationMove(Player2.getCurrentPosition(), managerRounds[i], Player2);
			squareLocation(Player2.getCurrentPosition(), Player2, Player1, vSquareVector);
			checkPlayerBalance(Player2);

		}
	}
	clearMemory(vSquareVector);
}
// This Is The Random File Given By Gareth
int cManager::random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}
// The Function Which Reads The Monopoly.txt File And Sets Up The Class
void cManager::retrieveFile(vector<cSquare*> &vSquareVector)
{
	ifstream fileRetreiver;
	fileRetreiver.open("Monopoly.txt");
	while (!fileRetreiver.is_open())
	{
		cout << "No Monopoly.txt found!" << endl;
		system("pause");
	}
	string word[26];
	while (fileRetreiver.good())
	{
		for (int i = 0; i < fileSize; i++)
		{
			getline(fileRetreiver, word[i]);
		}
	}
	for (int i = 0; i < fileSize; i++)
	{
		int lineLoopTimes = 0;
		// Detects The Start Of The Line So It Knows How To Handle It
		// Method Is Breakdown Line By Line then Word by Word
		if (word[i].find("1") == 0)
		{ //starts with 1
			istringstream is(word[i]);
			string aword;
			string arr[6];
			int loopTimes = 0;
			// Goes Through The Line And Divides It Into Strings
			while (is >> aword)
			{    // read each word from line

				if (loopTimes == 0)
				{
					arr[0] = aword;
				}
				else if (loopTimes == 1)
				{
					arr[1] = aword;
				}
				else if (loopTimes == 2)
				{
					arr[2] = aword;
				}
				else if (loopTimes == 3)
				{
					arr[3] = aword;
				}
				else if (loopTimes == 4)
				{
					arr[4] = aword;
				}
				else if (loopTimes == 5)
				{
					arr[5] = aword;
				}
				loopTimes++;
			}
			// Pushes The Address Of The Class Into The Vector
			vSquareVector.push_back(new cProperty(stringToInt(arr[0]), arr[1], arr[2], stringToInt(arr[3]), stringToInt(arr[4]), stringToInt(arr[5])));
		}
		// Detects The Start Of The Line So It Knows How To Handle It
		// Method Is Breakdown Line By Line then Word by Word
		if (word[i].find("2") == 0)
		{ //starts with 2
			istringstream is(word[i]);
			string aword;
			string arr[2];
			int loopTimes = 0;
			// Goes Through The Line And Divides It Into Strings
			while (is >> aword)
			{    // read each word from line

				if (loopTimes == 0)
				{
					arr[0] = aword;
				}
				else if (loopTimes == 1)
				{
					arr[1] = aword;
				}
				loopTimes++;
			}
			// Pushes The Address Of The Class Into The Vector
			vSquareVector.push_back(new cGo(stringToInt(arr[0]), arr[1]));
		}
		// Detects The Start Of The Line So It Knows How To Handle It
		// Method Is Breakdown Line By Line then Word by Word
		if (word[i].find("3") == 0)
		{ //starts with 3
			istringstream is(word[i]);
			string aword;
			string arr[3];
			int loopTimes = 0;
			// Goes Through The Line And Divides It Into Strings
			while (is >> aword) {    // read each word from line

				if (loopTimes == 0)
				{
					arr[0] = aword;
				}
				else if (loopTimes == 1)
				{
					arr[1] = aword;
				}
				else if (loopTimes == 2)
				{
					arr[2] = aword;
				}
				loopTimes++;
			}
			// Pushes The Address Of The Class Into The Vector
			vSquareVector.push_back(new cAirport(stringToInt(arr[0]), arr[1], arr[2]));
		}
		// Detects The Start Of The Line So It Knows How To Handle It
		// Method Is Breakdown Line By Line then Word by Word
		if (word[i].find("4") == 0)
		{ //starts with 4
			istringstream is(word[i]);
			string aword;
			string arr[2];
			int loopTimes = 0;
			// Goes Through The Line And Divides It Into Strings
			while (is >> aword)
			{    // read each word from line

				if (loopTimes == 0)
				{
					arr[0] = aword;
				}
				else if (loopTimes == 1)
				{
					arr[1] = aword;
				}
				loopTimes++;
			}
			// Pushes The Address Of The Class Into The Vector
			vSquareVector.push_back(new cBonus(stringToInt(arr[0]), arr[1]));
		}
		// Detects The Start Of The Line So It Knows How To Handle It
		// Method Is Breakdown Line By Line then Word by Word
		if (word[i].find("5") == 0)
		{ //starts with 5
			istringstream is(word[i]);
			string aword;
			string arr[2];
			int loopTimes = 0;
			// Goes Through The Line And Divides It Into Strings
			while (is >> aword)
			{    // read each word from line

				if (loopTimes == 0)
				{
					arr[0] = aword;
				}
				else if (loopTimes == 1)
				{
					arr[1] = aword;
				}
				loopTimes++;
			}
			// Pushes The Address Of The Class Into The Vector
			vSquareVector.push_back(new cPenalty(stringToInt(arr[0]), arr[1]));
		}
		// Detects The Start Of The Line So It Knows How To Handle It
		// Method Is Breakdown Line By Line then Word by Word
		if (word[i].find("6") == 0)
		{ //starts with 6
			istringstream is(word[i]);
			string aword;
			string arr[2];
			// Goes Through The Line And Divides It Into Strings
			int loopTimes = 0;
			int intAword = stringToInt(aword);
			while (is >> aword)
			{    // read each word from line

				if (loopTimes == 0)
				{
					arr[0] = aword;
				}
				else if (loopTimes == 1)
				{
					arr[1] = aword;
				}

				loopTimes++;
			}
			// Pushes The Address Of The Class Into The Vector
			vSquareVector.push_back(new cJail(stringToInt(arr[0]), arr[1]));

		}
		// Detects The Start Of The Line So It Knows How To Handle It
		// Method Is Breakdown Line By Line then Word by Word
		if (word[i].find("7") == 0)
		{ //starts with 7
			istringstream is(word[i]);
			string aword, firstname, secondname;
			string arr[4];
			int loopTimes = 0;
			// Goes Through The Line And Divides It Into Strings
			while (is >> aword)
			{    // read each word from line

				if (loopTimes == 0)
				{
					arr[0] = aword;
				}
				else if (loopTimes == 1)
				{
					arr[1] = aword;
				}
				else if (loopTimes == 2)
				{
					arr[2] = aword;
				}
				else if (loopTimes == 3)
				{
					arr[3] = aword;
				}
				loopTimes++;
			}
			// Pushes The Address Of The Class Into The Vector
			vSquareVector.push_back(new cGoToJail(stringToInt(arr[0]), arr[1], arr[2], arr[3]));
		}
		// Detects The Start Of The Line So It Knows How To Handle It
		// Method Is Breakdown Line By Line then Word by Word
		if (word[i].find("8") == 0)
		{ //starts with 8
			istringstream is(word[i]);
			string aword;
			string arr[3];
			int loopTimes = 0;
			// Goes Through The Line And Divides It Into Strings
			while (is >> aword)
			{    // read each word from line

				if (loopTimes == 0)
				{
					arr[0] = aword;
				}
				else if (loopTimes == 1)
				{
					arr[1] = aword;
				}
				else if (loopTimes == 2)
				{
					arr[2] = aword;
				}
				loopTimes++;
			}
			// Pushes The Address Of The Class Into The Vector
			vSquareVector.push_back(new cFreeParking(stringToInt(arr[0]), arr[1], arr[2]));
		}

	}
	fileRetreiver.close(); //closes the fileRetreiver file Stream
}
// Function Which Is Called To Convert String To Int
int cManager::stringToInt(const string &convertString)
{
	string stringConverting = convertString;
	const char * charConverting = stringConverting.c_str();
	int intConverted = atoi(charConverting);
	return intConverted;
}
// Retrieves The Value of seed.txt
int cManager::retrieveSeed()
{
	ifstream seedFileRetreiver;
	seedFileRetreiver.open("seed.txt");
	string seedValue;
	while (!seedFileRetreiver.is_open())
	{
		cout << "No seed.txt Found!" << endl;
		system("pause");
	}
	while (seedFileRetreiver.good())
	{
		for (int i = 0; i < seedFileSize; i++)
		{
			seedFileRetreiver >> seedValue;
		}
	}
	int seed = atoi(seedValue.c_str());
	return seed;
}
// Performs A Check Every Round To See Whether A User Needs To Mortgage Properties, Or If They Can UnMortgage Any They Have Done So
void cManager::checkPlayerBalance(cPlayer& playerName)
{
	//Player's Balance Is Less Zero
	if (playerName.getPlayerBalance() < 0)
	{
		int timesLooped = 0;
		while (playerName.getPlayerBalance() < 0)
		{
			cProperty* pointer = dynamic_cast<cProperty*>(playerName.getProperties(timesLooped));
			playerName.setMortgage(playerName.getProperties(timesLooped));
			playerName.setPlayerBalance(playerName.getPlayerBalance() + pointer->getPropertyCost());
			cout << "<" << playerName.getPlayerName() << "> Mortgaged <" << pointer->getName() << "> For <" << pointer->getPropertyCost() << ">" << endl;
			timesLooped++;
		}
	}
	//Player's Balance Above Zero
	else if (playerName.getPlayerBalance() > 0)
	{
		//While The Player's Balance Is Above Zero And Still Have Mortgages To Mortgage
		while (playerName.getPlayerBalance() > 0 && playerName.getMortageAmount() != 0)
		{
			int timesLooped = 0;
			//Casted The Mortgage So I have the Ability To Use cProperty Methods Instead of cSquares (Needed To Due As It is Derived)
			cProperty* pointer = dynamic_cast<cProperty*>(playerName.getMortages(timesLooped));
			playerName.setPlayerBalance(playerName.getPlayerBalance() + pointer->getPropertyCost());
			cout << "<" << playerName.getPlayerName() << "> UnMortgaged <" << pointer->getName() << "> For <" << pointer->getPropertyCost() << "> " << playerName.getPlayerBalance() << endl;
			playerName.removeMortage();
			timesLooped++;

		}
	}
	if (playerName.getPlayerBalance() < 0 && playerName.getMortageAmount() == 0)
	{
		cout << "<" << playerName.getPlayerName() << "> Has Lost " << endl;
		system("pause");
	}
	cout << "<" << playerName.getPlayerName() << "> has <" << char(156) << playerName.getPlayerBalance() << ">" << endl;
	cout << endl;
}
//Uses The Const arrOfRoll To Decide The Amonut Of Round's Dices there would be.
void cManager::roll(int arrOfRoll[])
{

	srand(retrieveSeed());	
	for (int i = 0; i < amountOfRounds; i++)
	{
		arrOfRoll[i] = random();
	}

}
//Used To Switch Between The Turns Of The Players
bool cManager::isOdd(int inputOdd)
{
	if (inputOdd % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Moves The Users Location 
void cManager::diceLocationMove(int currentPlayerPosition, int playerDice, cPlayer& playerName)
{
	int overallPosition;
	overallPosition = currentPlayerPosition + playerDice;
	cout << "<" << playerName.getPlayerName() << "> Rolls <" << playerDice << ">" << endl;
	//Works Out Difference Of Anything Above 26 AND also does the Go Payments
	if (overallPosition >= 26)
	{
		//Works Out Whether The User Will Pass Go Or Not
		overallPosition -= 26;
		cout << "<" << playerName.getPlayerName() << "> passes Go and collects " << char(156) << passingGoWindfall << endl;
		playerName.setPlayerBalance(playerName.getPlayerBalance() + passingGoWindfall);
	}
	//Moves The Player To His New Location
	playerName.setPosition(overallPosition);
}
void cManager::squareLocation(int playerLocation, cPlayer& playerName, cPlayer& otherPlayerName,
	vector<cSquare*> &vSquareVector){
	//Retrieves SquareType and calls its do_method method.
	vSquareVector[playerLocation]->do_method(playerName, otherPlayerName);	
}
void cManager::clearMemory(vector<cSquare*> &vSquareVector)
{
	for (unsigned int i = 0; i < vSquareVector.size(); i++)
	{
		delete vSquareVector[i];
	}
}

cManager::~cManager()
{
}
