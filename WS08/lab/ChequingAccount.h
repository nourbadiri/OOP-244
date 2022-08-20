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
#ifndef SDDS_CHEQUINGACCOUNT_H_
#define SDDS_CHEQUINGACCOUNT_H_
#include <iostream>
#include "Account.h"
namespace sdds {
class ChequingAccount : public Account{
    double transaction_fee;
    double monthly_fee;
public:
    ChequingAccount(double balance, double transaction, double monthly);
    bool credit(double);
    bool debit(double);
    void monthEnd();
    void display(std::ostream& os) const;
};
}
#endif 