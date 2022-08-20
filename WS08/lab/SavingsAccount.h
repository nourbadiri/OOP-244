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
#ifndef SDDS_SAVINGSACCOUNT_H_
#define SDDS_SAVINGSACCOUNT_H_
#include <iostream>
#include "Account.h"
namespace sdds {
class SavingsAccount : public Account{
	double interest_rate;
public:
    SavingsAccount(double balance, double interest);
    void monthEnd();
    void display(std::ostream& os) const;
};
}
#endif 