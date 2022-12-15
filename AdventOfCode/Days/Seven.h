#pragma once

#include "../Day.h"

#include <vector>
#include <map>

class Seven : public Day
{
	class Directory;

public:
	void Run() override;

private:
	class File
	{
	public:
		File(Directory* parent, string name) { Parent = parent;  Name = name;}

		int Memory;

		Directory* Parent;
		string Name;
	};

	class Directory
	{
	public:
		Directory(Directory* parent, string name) { Parent = parent;  Name = name;}

		map<string, Directory*> Directories;
		map<string, File*> Files;
		int Memory;

		Directory *Parent;
		string Name;
	};

	string filename =
#ifdef TEST
		"Data/Test_7.txt";
#else
		"Data/Input_7.txt";
#endif

	int Implementation();

	bool GetFirstIntFromString(string str, int& i);
	bool IsInt(string str);
};

