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
#include <fstream>
#include "Publication.h"
#include "Book.h"

using namespace std;
using namespace sdds;
int main() {
   Book bk;
   cout << ">" << bk << "<" << endl;
   ofstream fileout("Books.txt",ios::app);
   cout << "Enter the Book infomation to be added to the file:" << endl;
   cin >> bk;
   cout << bk << endl;
   if (bk) {
      cout << "added to the file" << endl;
      fileout << bk << endl;
   }
   fileout.close();
   cout << endl << "Contents of the file:" << endl;
   ifstream filein("Books.txt");
   char pType{};
   for (int row = 1; filein; row++) {
      filein >> pType;
      if (pType != 'B') {
         cout << "The Record type signature is supposed to be B, but it is: " << pType << endl;
         filein.setstate(ios::failbit);
      }
      filein.ignore();
      filein >> bk;
      filein.ignore(1000, '\n');
      if (filein) {
         cout << "| ";
         cout.width(4);
         cout.fill(' ');
         cout.setf(ios::right);
         cout << row << " ";
         cout.unsetf(ios::right);
         cout << bk << endl;
      }
   }
   return 0;
}