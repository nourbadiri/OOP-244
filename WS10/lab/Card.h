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
#include <iostream>
#ifndef SDDS_CARD_H_
#define SDDS_CARD_H_
#include "Write.h"
namespace sdds {
    class Card : public ReadWrite {
        char m_suit[10];
        int m_value;
    public:
        Card(const char* suit = "", const int value= 0);
        void set(const char* suit, const int value);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const char* mmSubstr)const;
        bool operator==(const int mmVal)const;
    };
    std::ostream& operator<<(std::ostream& os, const Card& card);
}
#endif // !SDDS_CARD_H_
