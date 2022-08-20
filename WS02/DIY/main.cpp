/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 05/30/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include "BirthDate.h"
using namespace std;
using namespace sdds;
int main() {
   bool done = false;
   int month = 0;
   char filename[256];
   cout << "V1.1 corrected the data file records" << endl;
   cout << "Enter data file name: ";
   cin >> filename;
   if (beginSearch(filename)) {
      while (!done) {
         cout << "Enter a month of birth or 0 to exit: ";
         cin >> month;
         if (month == 0) {
            done = true;
         }
         else {
            if (readBirthDate(month)) {
               sort();
               displayBirthdays();
               deallocate();
            }
            else {
               cout << "No match found!" << endl;
            }
         }
      }
      endSearch();
   }
   return 0;
}
