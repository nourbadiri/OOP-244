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
#include "Book.h"
namespace sdds {
    Book::Book() {
        set(0, "", "", 0.0);
    }
    Book::Book(int upc, const char* title, const char* author, double price) {
        set(upc, title, author, price);
    }
    void Book::set(int upc, const char* title, const char* author, double price) {
        m_upc = upc;
        strcpy(m_title, title);
        strcpy(m_author, author);
        m_price = price;
    }
    ostream& Book::display(ostream& os)const {
        return os << m_upc << " " << m_title << " (Author: " << m_author << ") Price: $" << setprecision(2) << fixed << m_price;
    }
    bool Book::operator==(int upc)const {
        return m_upc == upc;
    }
    bool Book::operator==(const char* title)const {
        return strcmp(m_title,title)==0;
    }

    std::ostream& operator<<(std::ostream& os,const Book& book) {
        book.display(os);
        return os;
    }
}
