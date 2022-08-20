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
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include "iAccount.h"
#include <iostream>
namespace sdds {
    class Account : public iAccount{
        double current_balance;
    public:
        Account(double balance);
        bool credit(double amount);
        bool debit(double amount);
    protected:
        double balance() const;
     };
}
#endif 