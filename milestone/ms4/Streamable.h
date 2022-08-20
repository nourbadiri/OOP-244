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
#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>
namespace sdds {
    class Streamable{
public:
    virtual std::ostream& write(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& istr) = 0;
    virtual bool conIO(const std::ios& io) const = 0;
    virtual operator bool()const = 0;
    virtual ~Streamable() {};
};
std::ostream& operator<<(std::ostream& os, const Streamable& st);
std::istream& operator>>(std::istream& istr, Streamable& st);
}
#endif