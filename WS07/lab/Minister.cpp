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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Minister.h"
#include "MemberParliament.h"
using namespace std;
namespace sdds {
Minister::Minister(const char* id, int age, double year, const char* primeMinister, const char* district)
:MemberParliament(id, age){
    NewDistrict(district);
    m_year = year;
    strcpy(m_primeMinister, primeMinister);
}
void Minister::changePM(const char* pm){
    strcpy(m_primeMinister, pm);
}
void Minister::assumeOffice(double year){
    m_year = year;
}
ostream& Minister::write(std::ostream& os) const{
    MemberParliament::write(os);
      os << " | " << m_primeMinister << "/" << m_year;
        return os;
}
istream& Minister::read(std::istream& in){
    MemberParliament::read(in);
    cout << "Reports TO: ";
    in >> m_primeMinister;
    cout << "Year Assumed Office: ";
    in >> m_year;
    return in;
}
ostream& operator<<(ostream& os, const Minister& M){
    M.write(os);
    return os;
}
istream& operator>>(istream& istr, Minister& N){
    N.read(istr);
    return istr;
}
}