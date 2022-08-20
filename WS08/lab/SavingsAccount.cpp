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
#include "Account.h"
#include "SavingsAccount.h"
#include <iomanip>
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
SavingsAccount::SavingsAccount(double balance, double interest):Account(balance){
    if(interest >= 0.0)
        interest_rate=interest;
    else
        interest_rate=0.0;
}
void SavingsAccount::monthEnd(){
    double interest;
		interest = this->interest_rate*this->balance();
		this->credit(interest);
}
void SavingsAccount::display(std::ostream& os) const{
    os << "Account type: Savings" << endl;
	os << fixed << setprecision(2);
	os << "Balance: $" << Account::balance() << endl;
	os << "Interest Rate (%): " << interest_rate * 100 << endl;
}
}