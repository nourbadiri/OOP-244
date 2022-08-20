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
#include "MemberParliament.h"
using namespace std;
namespace sdds {
MemberParliament::MemberParliament(const char* id, int age){
	strcpy(m_parliament_id, id);
   	strcpy(m_district, "Unassigned");
   	m_age = age;
}

void MemberParliament::NewDistrict(const char* district){
    char mp_district[64];
    strcpy(mp_district, m_district);
    strcpy(m_district, district);
    cout << "|" << setw(8) << right << m_parliament_id << "| |" << setw(20) << right << mp_district << " ---> " << setw(23) << left << district  << "|" << endl;
}
ostream& MemberParliament::write(ostream& os) const{
    os << "| " << m_parliament_id << " | " << m_age << " | " << m_district;
   return os;
}
istream& MemberParliament::read(istream& in) {
    cout<<"Age: "; 
    in>>m_age;
    cout << "Id: "; 
    in>>m_parliament_id;
    cout << "District: ";
    in>>m_district;
    return in;
}
ostream& operator<<(ostream& os, const MemberParliament& M){
    M.write(os);
    return os;
}
istream& operator>>(istream& istr,  MemberParliament& N){
    N.read(istr);
    return istr;
}
}