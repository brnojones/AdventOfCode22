#include "Three.h"

void Three::Run()
{
	cout << "Output: " << PartOne();
	//cout << "Output: " << PartTwo();
}

int Three::PartOne()
{
	string text;
	ifstream file(filename);

	int runningTotal = 0;

	while (getline(file, text))
	{
#ifdef SPEW
		cout << text;
#endif



#ifdef SPEW
		cout << "\n";
#endif
	}
	return 0;
}

int Three::PartTwo()
{
	return 0;
}
