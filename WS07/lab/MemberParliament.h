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
#ifndef SDDS_MEMBERPARLIAMENT_H_
#define SDDS_MEMBERPARLIAMENT_H_
#include <iostream>
namespace sdds {
    class MemberParliament{
        char m_parliament_id[32];
        char m_district[64];
        int m_age;
    public:
    MemberParliament(const char* id, int age);
    void NewDistrict(const char* district);
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& in) ;
    };
    std::ostream& operator<<(std::ostream& os, const MemberParliament& M);
    std::istream& operator>>(std::istream& istr, MemberParliament& N);
    }
#endif 