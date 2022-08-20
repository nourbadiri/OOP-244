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
#include "ChequingAccount.h"
#include <iomanip>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
ChequingAccount::ChequingAccount(double balance, double transaction, double monthly):Account(balance){
    if (transaction > 0.0) {
		this->transaction_fee = transaction;
	}else{
        this->transaction_fee = 0.0;
    }
	
	if (monthly > 0.0) {
		this->monthly_fee = monthly;
	}else{
        this->monthly_fee = 0.0;
    }
}
bool ChequingAccount::credit(double balance){
    if (Account::credit(balance)) {
			Account::debit(transaction_fee);
			return true;
		}
		else return false;
}
bool ChequingAccount::debit(double balance){
    if (Account::debit(balance)) {
			Account::debit(transaction_fee);
			return true;
		}
		else return false;
}
void ChequingAccount::monthEnd(){
    debit(monthly_fee);
}
void ChequingAccount::display(std::ostream& os) const{
    os << "Account type: Chequing" << endl;
	os << fixed << setprecision(2);
	os << "Balance: $" << round(Account::balance())  << endl;
	os << "Per Transaction Fee: " << transaction_fee << endl;
	os << "Monthly Fee: " << monthly_fee << endl;
}
}