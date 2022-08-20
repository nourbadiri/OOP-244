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
#include "iAccount.h"
using namespace std;
namespace sdds {
Account::Account(double balance){
    if(balance < 0)
        current_balance=0.0;
    else
        current_balance = balance;
    }
bool Account::credit(double amount){
    if (amount > 0) {
        current_balance += amount;
	        return true;
    }
    return false;
}
bool Account::debit(double amount){
    if (amount > 0) {
        current_balance -= amount;
	        return true;
    }
    return false;
}
double Account::balance() const{
    return current_balance;
}
}