/*
*****************************************************************************
                          Workshop - #10 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 08/05/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/ 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

using namespace std;
#include "Pet.h"
namespace sdds {
    Pet::Pet() {
        set("", "", 0);
    }
    Pet::Pet(const char* name, const char* type, int age) {
        set(name, type, age);
    }
    void Pet::set(const char* name, const char* type, int age) {
        strcpy(m_name, name);
        strcpy(m_type, type);
        m_age = age;
    }
    ostream& Pet::display(ostream& os)const {
        return os <<"Type: " << m_type << ", Name: " << m_name << " Age: " << m_age;
    }
    bool Pet::operator==(int age)const {
        return m_age == age;
    }
    bool Pet::operator==(const char* type)const {
        return strcmp(m_type, type) == 0;
    }

    std::ostream& operator<<(std::ostream& os,const Pet& pet) {
        pet.display(os);
        return os;
    }
}