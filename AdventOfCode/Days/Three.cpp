
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
		int len = text.length();		
		char dupe = 0;

		for (int i = 0; i < len / 2; i++)
		{
			for (int j = len / 2; j < len; j++)
			{
				if (text[i] == text[j])
				{
					dupe = text[i];
					break;
				}
			}
		}

		int score = ScoreFromChar(dupe);
		runningTotal += score;

#ifdef SPEW
		cout << "Dupe = " << dupe << " - Score = " << score;
		cout << "\n";
#endif
	}
	return runningTotal;
}

int Three::PartTwo()
{
	string text;
	ifstream file(filename);

	int runningTotal = 0;
	int groupCounter = 0;

	string texts[3];

	while (getline(file, text))
	{
#ifdef SPEW
		cout << text;
#endif
		int len = text.length();
		texts[groupCounter] = text;

		if (groupCounter >= 2)
		{
			groupCounter = 0;
		}
		groupCounter++;
#ifdef SPEW
		cout << "\n";
#endif
	}
	return runningTotal;
}

int Three::ScoreFromChar(char c)
{
	if (c >= 97)
	{
		return c - 96;
	}
	return c - 38;
}
