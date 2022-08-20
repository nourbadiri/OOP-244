/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 06/05/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_BAR_H_
#define SDDS_BAR_H_
#include <iostream>
#include <cstring>
#define MAX_CHAR 20
using namespace std;
namespace sdds{
  class Bar{
      string title;
      char fill;
      int value;
    public:
      void setEmpty();
      void init(string t, char f, int v);
      bool isValid() const;
      void draw() const;
  };
}
#endif 