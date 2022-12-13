
#include "Six.h"

void Six::Run()
{
	cout << "Output: " << Implementation();
}

int Six::Implementation(int markerSize)
{
	string text;
	ifstream file(filename);

	int marker = -1;

	while (getline(file, text))
	{
#ifdef DEBUG
		cout << text;
#endif
		int lineMarker = 0;

		int len = text.length();
		for (int i = 0; i < len - markerSize; i++)
		{
			vector<char> encryp;
			for (int j = 0; j < markerSize; j++)
			{
				encryp.push_back(text[i + j]);
			}
			if (AreUnique(encryp))
			{
				lineMarker = i + markerSize;
				break;
			}
		}

		//	Just used for the test case with multiple lines
		if (marker == -1)
		{
			marker = lineMarker;
		}

#ifdef DEBUG
		cout << "	- [" << lineMarker << "]\n";
#endif
	}
	return marker;
}

bool Six::AreUnique(vector<char> marker)
{
	int size = marker.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (marker[i] == marker[j])
			{
				return false;
			}
		}
	}
	return true;
}
