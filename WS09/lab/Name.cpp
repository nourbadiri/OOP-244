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
#define _CRT_SECURE_NO_WARNINGS
#include "Name.h" 
#include "FullName.h" 
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sdds {

   Name::Name() {
      m_value = nullptr;
   }
   Name::Name(const char* name) {
      m_value = new char[strlen(name) + 1];
      strcpy(m_value, name);
   }

   Name::Name(const Name& name) {
     m_value = new char[strlen(name.m_value)+1];
      strcpy(m_value, name.m_value);
   }
   
   Name& Name::operator=(const Name& name) {
      if (this != &name) {
         delete[] m_value;
         m_value = new char[strlen(name.m_value) + 1];
         strcpy(m_value, name.m_value);
       }               
      return*this;
   }

   Name::~Name() {
      delete[] m_value;
   }

   Name::operator const char* ()const {
      return m_value;
   }

   Name::operator bool()const {
      return (m_value != nullptr);
   }

   std::ostream& Name::display(std::ostream& ostr)const {
      if (*this) {
         ostr << m_value;
      }
      return ostr;
   }

   std::istream& Name::read(std::istream& istr) {
      char* temp = new char[100];
      istr >> temp;
      if (istr) {
         delete[] m_value;
         m_value = nullptr;
         if (temp) {
            m_value = new char[strlen(temp) + 1];
            strcpy(m_value, temp);
          istr.ignore();
         }
      }
      delete[] temp;
      return istr;
   }

std::ostream& operator <<(std::ostream& ostr, const Name& N) {
   return N.display(ostr);
}
std::istream& operator>>(std::istream& istr, Name& N) {
   return N.read(istr);
}
}