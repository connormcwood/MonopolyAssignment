#include <iostream>
#include <ctime>
using namespace std;

// Returns a random number in the range 1 .. 6
// Note that I am using casting to convert one data type to another
int Random()
{
	return static_cast<int>( static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1 );
}


int main()
{
	// A random number generator actually produces a pseudo-random sequence of numbers.
	// This means that the random number generator will always produce the same sequence of numbers.
	// The generator needs to be "seeded" with a value. You seed the generator with the function srand().
	// If you want to create a different sequence of numbers each time then seed it with the time as follows:
	srand( static_cast<unsigned int> (time(0)) );
	// The output of time() is time_t (which is actually an int).
	// static_cast<unsigned int> merely converts the output of time() into an unsigned integer.
	for( int i = 0; i < 10; i++ )
	{
		cout << Random() << endl;
	}
	cout << endl;

	// However, if you seed the generator with the same value each time then it will always produce
	// the same sequence of numbers. You want this to occur with the Monopoly program.
	// The next bit of code does this:
	srand( 4 );
	for( int i = 0; i < 10; i++ )
	{
		cout << Random() << endl;
	}
	system( "pause" );
}
