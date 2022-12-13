
#include "Five.h"

void Five::Run()
{
	cout << "Output: " << Implementation(/*true*/);
}

string Five::Implementation(bool retainOrder)
{
	string text;
	ifstream file(filename);

	vector<vector<char>> boxes;
	vector<vector<int>> instructions;

	bool readingBoxes = true;
	bool initBoxVector = false;

	while (getline(file, text))
	{
#ifdef DEBUG
		cout << text;
#endif
		if (text == "\0")
		{
			readingBoxes = false;
			continue;
		}

		//	Get boxes into data set
		if (readingBoxes)
		{
			if (!initBoxVector)
			{
				int amount = (text.length() + 1) / 4;
				for (int i = 0; i < amount; i++)
				{
					vector<char> temp;
					boxes.push_back(temp);
				}
				initBoxVector = true;
			}

			vector<char> lineBoxes = GetLineBoxes(text);
			for (unsigned int i = 0; i < boxes.size(); i++)
			{
				char c = lineBoxes[i];
				if (isalpha(c))
				{
					//boxes[i].push_back(lineBoxes[i]);
					auto start = boxes[i].begin();
					boxes[i].insert(start, lineBoxes[i]);
				}
			}
		}
		//	Get instructions into data set
		else
		{
			instructions.push_back(GetLineInstructions(text));
		}

#ifdef DEBUG
		cout << "\n";
#endif
	}

	//	Do the instructions to the boxes
	return DoInstructions(boxes, instructions, retainOrder);
}

vector<char> Five::GetLineBoxes(string str)
{
#ifdef DEBUG
	cout << "	- Boxes: ";
#endif

	vector<char> lineBoxes;
	int len = str.length();

	for (int i = 1; i < len; i += 4)
	{
#ifdef DEBUG
		cout << "[" << str[i] << "]";
#endif
		lineBoxes.push_back(str[i]);
	}
	return lineBoxes;
}

vector<int> Five::GetLineInstructions(string str)
{
#ifdef DEBUG
	cout << "	- Instructions: ";
#endif

	vector<int> lineInstructions;
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
			int tempInt = stoi(tempStr);
			lineInstructions.push_back(tempInt);
#ifdef DEBUG
			cout << "[" << tempInt << "]";
#endif
		}

		start = end + 1;
		end = str.find(" ", start);
		
	} while (!done);

	return lineInstructions;
}

string Five::DoInstructions(vector<vector<char>> &boxes, const vector<vector<int>> instructions, bool retainOrder)
{
	int instructionCount = instructions.size();
	for (int i = 0; i < instructionCount; i++)
	{
		UpdateBoxes(boxes, instructions[i], retainOrder);
	}

	string output;
	int boxCount = boxes.size();
	for (int b = 0; b < boxCount; b++)
	{
		//	Add the the beginning of the vector so we can use pop_back/push_back to move the "top" around easily
		output += boxes[b][boxes[b].size()-1];
	}

	return output;
}

void Five::UpdateBoxes(vector<vector<char>> &boxes, const vector<int> instructions, bool retainOrder)
{
	int amount = instructions[0];
	int from = instructions[1] - 1;
	int to = instructions[2] - 1;

	if (retainOrder)
	{
		vector<char> c;
		for (int i = 0; i < amount; i++)
		{
			c.push_back(boxes[from][boxes[from].size() - 1 - i]);
		}
		for (int i = amount - 1; i >= 0; i--)
		{
			boxes[from].pop_back();
			boxes[to].push_back(c[i]);
		}
	}
	else
	{
		for (int i = 0; i < amount; i++)
		{
			char c = boxes[from][boxes[from].size() - 1];
			boxes[from].pop_back();
			boxes[to].push_back(c);
		}
	}
}

bool Five::IsInt(string str)
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
