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
#include "FullName.h" 
#include "Name.h" 
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

namespace sdds {

   FullName::FullName() {
      m_value = nullptr;
   }

   FullName::FullName(const char* name, const char* lastName): Name(name) { 
      m_value = new char[strlen(lastName) + 1];
      strcpy(m_value, lastName);
   }

   FullName::FullName(const FullName& fname) : Name(fname) {
      m_value = new char[strlen(fname.m_value) + 1];
      strcpy(m_value, fname.m_value);
   }
   
   FullName& FullName::operator=(const FullName& fname) {
      if (this != &fname) {
        (Name&)*this = fname;    
         delete[] m_value;
         m_value = new char[strlen(fname.m_value) + 1];
         strcpy(m_value, fname.m_value);
      }
      return *this;
   }
   
   FullName::~FullName() {
      delete[] m_value;
   }

   FullName::operator const char* ()const {
      return m_value;
   }

   FullName::operator bool()const {
      return (m_value && Name::operator bool());
   }
   
   std::ostream& FullName::display(std::ostream& ostr)const {
      if (*this) {
         ostr << Name::operator const char* (); 
         ostr << " " << m_value;                
      }
      return ostr;
   }
  
   std::istream& FullName::read(std::istream& istr) {
      Name::read(istr);
      char* temp = new char[100];
      istr.getline(temp, 100, '\n');
      if (istr) {
         delete[] m_value;
         m_value = nullptr;
         if (temp) {
            m_value = new char[strlen(temp) + 1];
            strcpy(m_value, temp);
         }
      }
      delete[] temp;
      return istr;
   }
}