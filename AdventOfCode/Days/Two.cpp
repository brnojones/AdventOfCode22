
#include "Two.h"

//	A = X = 1 = Rock
//	B = Y = 2 = Paper
//	C = Z = 3 = Scissors

void Two::Run()
{
	cout << "Output: " << PartOne();
	//cout << "Output: " << PartTwo();
}

int Two::PartOne()
{
	string text;
	ifstream file(filename);

	int runningTotal = 0;

	while (getline(file, text))
	{
#ifdef SPEW
		cout << text;
#endif

		text[2] -= 23;	//	Make X, Y, Z into A, B, C

		int handScore = HandToScore(text[2]);
		int winScore = WinScore(text[2], text[0]);
		int roundScore = handScore + winScore;

		runningTotal += roundScore;

#ifdef SPEW
		cout << " = [" << handScore << " + " << winScore << " = " << roundScore << "]\n";
#endif
	}

	return runningTotal;
}

int Two::PartTwo()
{
	string text;
	ifstream file(filename);

	int runningTotal = 0;

	while (getline(file, text))
	{
#ifdef SPEW
		cout << text;
#endif
		text[2] -= 23;	//	Make X, Y, Z into A, B, C

		int score = DesiredScore(text[0], (OutcomeScore)HandToOutcome(text[2]));
		runningTotal += score;

#ifdef SPEW
		cout << " - Score: " << score;
		cout << "\n";
#endif
	}

	return runningTotal;
}

int Two::WinScore(const char me, const char opp)
{
	//	B > A
	//	C > B
	//	A > C

	if (me == opp)
	{
		return OutcomeScore_Draw;
	}

	switch (me)
	{
		case HandChar_Rock:	//	Rock
			return opp == HandChar_Scissors ? OutcomeScore_Win : OutcomeScore_Loss;	//	vs. Scissors
		case HandChar_Paper:	//	Paper
			return opp == HandChar_Rock ? OutcomeScore_Win : OutcomeScore_Loss;		//	vs. Rock
		case HandChar_Scissors:	//	Scissors
			return opp == HandChar_Paper ? OutcomeScore_Win : OutcomeScore_Loss;	//	vs. Paper
		default:
			return OutcomeScore_Loss;
	}
}

int Two::DesiredScore(const char opp, const OutcomeScore outcome)
{
	if (outcome == OutcomeScore_Draw)
	{
		return HandToScore(opp) + outcome;
	}

	switch (opp)
	{
		case 'A':	//	Rock
			return outcome == OutcomeScore_Win ? OutcomeScore_Win + HandToScore(HandChar_Paper) : OutcomeScore_Loss + HandToScore(HandChar_Scissors);	//	Paper wins : Scissors lose
		case 'B':	//	Paper
			return outcome == OutcomeScore_Win ? OutcomeScore_Win + HandToScore(HandChar_Scissors) : OutcomeScore_Loss + HandToScore(HandChar_Rock);	//	Scissors win : Rock loses
		case 'C':	//	Scissors
			return outcome == OutcomeScore_Win ? OutcomeScore_Win + HandToScore(HandChar_Rock) : OutcomeScore_Loss + HandToScore(HandChar_Paper);	//	Rock wins : Paper loses
		default:
			return 0;
	}
}

int Two::HandToScore(const char hand)
{
	return hand - 64;				//	Convert to 1,2,3
}

int Two::HandToOutcome(const char hand)
{
	return ((hand - 64) * 3) - 3;	// Convert to 0,3,6
}
