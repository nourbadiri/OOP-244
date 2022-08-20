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
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
#include <cstring>

namespace sdds {

   class Name {
      char* m_value;
   public:
      Name(); 
      Name(const char* name); 
      Name(const Name& name); // copy constructor
      Name& operator=(const Name& name); 
      ~Name(); 
      operator const char* ()const; 
      virtual operator bool()const; 
      virtual std::ostream& display(std::ostream& ostr = std::cout)const; 
      virtual std::istream& read(std::istream& istr = std::cin); 
   };
   std::ostream& operator <<(std::ostream& ostr, const Name& N);
   std::istream& operator>>(std::istream& istr, Name& N);
}
#endif