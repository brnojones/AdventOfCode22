
#include "One.h"

void One::Run()
{
	cout << "\nOutput: " << PartOne();
	//cout << "\nOutput: " << PartTwo();
}

int One::PartOne()
{
	string text;
	ifstream file(filename);

	int max = 0;
	int temp = 0;

	while (getline(file, text))
	{
		if (text != "")
		{
#ifdef DEBUG
		cout << "\n" << text;
#endif
			int lineNum = stoi(text);
			temp += lineNum;
		}

		if (text == "" || file.eof())
		{
			if (temp > max)
			{
				max = temp;
			}
#ifdef DEBUG
			cout << "\n = " << temp << "\n";
#endif
			temp = 0;
		}
	}

#ifdef DEBUG
	cout << "\n * Highest = " << max << "\n";
#endif

	return max;
}

int One::PartTwo()
{
	string text;
	ifstream file(filename);

	int temp = 0;
	int highest[3] = { 0, 0, 0 };

	while (getline(file, text))
	{
		if (text != "")
		{
#ifdef DEBUG
		cout << "\n" << text;
#endif
			int lineNum = stoi(text);
			temp += lineNum;
		}

		if (text == "" || file.eof())
		{
			AddTo(highest, temp);
#ifdef DEBUG
			cout << "\n = " << temp << "\n";
#endif
			temp = 0;
		}
	}

	int amount = highest[0] + highest[1] + highest[2];

#ifdef DEBUG
	cout << "\n* " << highest[0] << " + " << highest[1] << " + " << highest[2] << " = " << amount << "\n";
#endif

	return amount;
}

void One::AddTo(int* arr, int val, const int count)
{
	for (int i = 0; i < count; i++)
	{
		if (val > arr[i])
		{
			int temp = arr[i];
			arr[i] = val;
			val = temp;
		}
	}
}
