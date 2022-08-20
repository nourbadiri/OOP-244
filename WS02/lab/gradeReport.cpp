/*
*****************************************************************************
                          Workshop - #2 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 05/27/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "Student.h"
using namespace sdds;
int main() {
   if (load("simpsons.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}