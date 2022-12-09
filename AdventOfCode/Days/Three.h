#pragma once

#include "Day.h"

class Three : public Day
{
public:
	void Run() override;

private:
	string filename =
#ifdef TEST
		"Test_3.txt";
#else
		"Input_3.txt";
#endif

	int PartOne();
	int PartTwo();

};

