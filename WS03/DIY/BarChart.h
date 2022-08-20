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
#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_
#include "Bar.h"
#include <iostream>
using namespace std;
namespace sdds{
  class BarChart{
      const char *chartTitle;
      Bar *bars;
    public:
      char fillChar;
      int sizeBars;
      int samplesAdded;
      bool isValid() const;
      void init(const char* title, int noOfSampels, char fill);
      void add(const char* bar_title, int value);
      void draw() const;
      void deallocate();
  };
}
#endif 