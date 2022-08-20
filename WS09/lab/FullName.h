/*
*****************************************************************************
                          Workshop - #9 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/29/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/ 
#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H
#include <iostream> 
#include "Name.h" 

namespace sdds {

   class FullName : public Name {
      char* m_value;
   public:
      FullName();
      FullName(const char* name, const char* lastName);
      FullName(const FullName& fname);
      FullName& operator=(const FullName& fname);
      ~FullName();
      operator const char* ()const;
      virtual operator bool()const;
      virtual std::ostream& display(std::ostream& ostr = std::cout)const;
      virtual std::istream& read(std::istream& istr = std::cin);
   };

}
#endif