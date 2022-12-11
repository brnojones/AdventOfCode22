
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

	string texts[3];
	int runningTotal = 0;

	bool endOfFile = false;

	while (!endOfFile)
	{
		for (int i = 0; i < 3; i++)
		{
			if (getline(file, text))
			{
				texts[i] = text;

				if (file.eof())
				{
					endOfFile = true;
				}
			}
		}
		
		char c = DuplicateChar(texts);
		int score = ScoreFromChar(c);
		runningTotal += score;

		cout << "\n" << texts[0] << "\n" << texts[1] << "\n" << texts[2] << "\n";
		cout << "Dupe: " << c << " - Score: " << score << " - Running total: " << runningTotal << "\n";
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

char Three::DuplicateChar(string texts[3])
{
	for (int a = 0; a < texts[0].length(); a++)
	{
		for (int b = 0; b < texts[1].length(); b++)
		{
			if (texts[0][a] == texts[1][b])
			{
				for (int c = 0; c < texts[2].length(); c++)
				{
					if (texts[2][c] == texts[0][a])
					{
						return texts[0][a];
					}
				}
			}
		}
	}
	return 0;
}
