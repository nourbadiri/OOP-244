/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/15/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_MINISTER_H_
#define SDDS_MINISTER_H_
#include "MemberParliament.h"
#include <iostream>
namespace sdds {
    class Minister : public MemberParliament{
        char m_primeMinister[50];
        int m_year;
    public:
    
    Minister(const char* id, int age, double year, const char* district, const char* primeMinister);
    void changePM(const char* pm);
    void assumeOffice(double year);
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& os, const Minister& M);
    std::istream& operator>>(std::istream& istr, Minister& N);
    }
#endif 