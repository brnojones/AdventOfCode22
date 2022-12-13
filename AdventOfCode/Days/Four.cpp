
#include "Four.h"

void Four::Run()
{
	cout << "Output: " << Implementation(/*false*/);
}

int Four::Implementation(bool fullyContained)
{
	string text;
	ifstream file(filename);

	int runningTotal = 0;

	while (getline(file, text))
	{
#ifdef DEBUG
		cout << text;
#endif
		auto groups = SplitStringByChar(text, ',');
		auto groupA = SplitStringByChar(get<0>(groups), '-');
		auto groupB = SplitStringByChar(get<1>(groups), '-');
		tuple<int, int, int, int> minMaxs = { stoi(get<0>(groupA)), stoi(get<1>(groupA)), stoi(get<0>(groupB)), stoi(get<1>(groupB)) };
		bool overlap = GroupOverlaps(minMaxs, fullyContained);
		runningTotal += overlap;
#ifdef DEBUG
		cout << "		- Groups = [" 
			<< get<0>(minMaxs) << " - " << get<1>(minMaxs) << "][" << get<2>(minMaxs) << " - " << get<3>(minMaxs) << "]" 
			<< (overlap ? "  <-->" : "") << "\n";
#endif
	}

	return runningTotal;
}

tuple<string, string> Four::SplitStringByChar(string s, char c)
{
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == c)
		{
			return { s.substr(0, i), s.substr(i + 1, len) };
		}
	}
}

bool Four::GroupOverlaps(tuple<int, int, int, int> minMaxs, bool fullyContained)
{
	if (fullyContained)
	{
		return (get<0>(minMaxs) >= get<2>(minMaxs) && get<1>(minMaxs) <= get<3>(minMaxs))	//	group A within B
			|| (get<2>(minMaxs) >= get<0>(minMaxs) && get<3>(minMaxs) <= get<1>(minMaxs));	//	group B within A
	}

	return (get<0>(minMaxs) <= get<2>(minMaxs) && get<1>(minMaxs) >= get<2>(minMaxs)) 
		|| (get<2>(minMaxs) <= get<0>(minMaxs) && get<3>(minMaxs) >= get<0>(minMaxs));
}

