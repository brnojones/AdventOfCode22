#include "Seven.h"

void Seven::Run()
{
	cout << "Output: " << Implementation();
}

int Seven::Implementation()
{
	string text;
	ifstream file(filename);

	int runningTotal = 0;



	while (getline(file, text))
	{

		Directory tree = Directory(0, "/");
		//tree.Directories.insert(pair<string, Directory*>("A", &Directory("A", tree)));
		//tree.Directories["A"] = &Directory(&tree, "A");












#ifdef DEBUG
		cout << text;
#endif

		int memory;
		if (GetFirstIntFromString(text, memory))
		{
			if (memory <= 100000)
			{
				runningTotal += memory;
			}
#ifdef DEBUG
			cout << "		- [" << memory << "]";
#endif
		}

#ifdef DEBUG
		cout << "\n";
#endif
	}
	return runningTotal;
}

bool Seven::GetFirstIntFromString(string str, int &i)
{
	int start = 0;
	int end = str.find(" ");
	bool done = false;

	do
	{
		if (end == -1)
		{
			done = true;
			end = str.length();
		}

		string tempStr = str.substr(start, end - start);

		if (IsInt(tempStr))
		{
			i = stoi(tempStr);
			return true;
		}

		start = end + 1;
		end = str.find(" ", start);

	} while (!done);
	return false;
}

bool Seven::IsInt(string str)
{
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

