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
#ifndef SDDS_IACCOUNT_H_
#define SDDS_IACCOUNT_H_
#include <iostream>
namespace sdds {
    class iAccount{
public:
    virtual bool credit(double) = 0;
    virtual bool debit(double) = 0;
    virtual void monthEnd() = 0;
    virtual void display(std::ostream&) const = 0;
    virtual ~iAccount() {};
};
iAccount* CreateAccount(const char*, double);
}
#endif 