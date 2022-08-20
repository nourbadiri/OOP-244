/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 06/13/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include "CleanerBot.h"

using namespace std;
using namespace sdds;

int main()
{
	const int num_bots = 8;
	CleanerBot bot[num_bots] = {
		{},
		{"library", 82.5, 7, false},
		{"corridor", 75, 3, true},
		{"pantry", 23.6, 12, false},
		{"parking", 30.1, 9, true},
		{"storage", 57, 2, true},
		{"?", -1, 1, false},
		{"basement", 29.9, 1, true}
	};

	report(bot, num_bots);

	return 0;
}