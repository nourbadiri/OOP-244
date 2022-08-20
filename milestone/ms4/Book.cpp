 /*
*****************************************************************************
                          Final Project Milestone 4
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/28/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Utils.h"
using namespace std;
namespace sdds {

Book::Book() {
    m_author = nullptr;
}
Book::Book(const Book& src) {
    operator=(src);
}
Book& Book::operator=(const Book& src) {
    if (this != &src && src) {
        Publication::operator=(src);
        Utils::copyStr(m_author, src.m_author);
}
     return *this;
}
Book::~Book() {
    delete[] m_author;
    m_author = nullptr;
}
void Book::set(int member_id) {
    Publication::set(member_id);
    Publication::resetDate();
}
char Book::type()const {
    return 'B';
}
void Book::setDefault() {
    delete[] m_author;
    m_author = nullptr;
}
ostream& Book::write(ostream& ostr)const {
    Publication::write(ostr);
    if (conIO(ostr)) {
        ostr << " ";
        ostr.setf(ios::left);
        if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {
            for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) ostr << m_author[i];
        }
        else {
            ostr.width(SDDS_AUTHOR_WIDTH);
            ostr << m_author;
        }
        ostr << " |";
        ostr.unsetf(ios::left);
    }
    else {
        ostr << '\t' << m_author;
    }
    return ostr;
}
istream& Book::read(istream& istr) {
    char author[255 + 1];
    setDefault();
    Publication::read(istr);
    if (conIO(istr)) {
        Utils::getChar(istr, '\n');
        cout << "Author: ";
        istr.getline(author, 255 + 1);
    }
    else {
        Utils::getChar(istr, '\t');
        istr.get(author, 255 + 1);
    }
        if (istr) {
              Utils::copyStr(m_author, author);
    }
        else {
            setDefault();
    }
    return istr;
}
bool Book::conIO(std::ios& io)const {
    return Publication::conIO(io);
}
Book::operator bool()const {
    return (m_author && m_author[0] && Publication::operator bool());
}
}