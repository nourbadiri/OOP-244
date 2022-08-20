/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/20/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "SavingsAccount.h" 
#include "ChequingAccount.h" 

namespace sdds {
	// account rates and charges
	const double interestRate = 0.05;
	const double transactionFee = 0.50;
	const double monthlyFee = 2.00;

	// calls the appropriate constructor
	iAccount* CreateAccount(const char* str, double balance) {
		iAccount* account = nullptr;
		switch (str[0]) {
		case 'S':
			account = new SavingsAccount(balance, interestRate);
			break;
		case 'C':
			account = new ChequingAccount(balance, transactionFee, monthlyFee);
			break;
		}
		return account;
	}
}
