 /*
*****************************************************************************
                          Final Project Milestone 3
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/22/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include <fstream>
#include "Publication.h"
#include "Date.h"
using namespace std;
using namespace sdds;
Publication readPublication(istream& istr) {
   Publication P;
   cin >> P;
   return P;
}
Publication getNextRec(ifstream& ifstr) {
   Publication P;
   ifstr >> P;
   ifstr.ignore(1000, '\n');
   return P;
}
int main() {
   sdds::sdds_test = true;
   Publication pd;
   cout << "An Invalid publication printout:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << "Enter the following: " << endl
      << "P1234" << endl
      << "------------------------------" << endl;
   pd = readPublication(cin);
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
   }
   else {
      cout << "This is not supposed to be printed!" << endl;
   }
   cout << "You entered:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << "Enter the following: " << endl
      << "P123" << endl
      << "Seneca Weekly" << endl
      << "2022/13/17" << endl
      << "------------------------------" << endl;
   pd = readPublication(cin);
   if (!cin) {
      cin.clear();
      cin.ignore(1000, '\n');
   }
   else {
      cout << "This is not supposed to be printed!" << endl;
   }
   cout << "You entered:" << endl;
   cout << ">" << pd << "<" << endl;
   cout << "Enter the following: " << endl
      << "P123" << endl
      << "Seneca Weekly" << endl
      << "2022/7/17" << endl
      << "------------------------------" << endl;
   pd = readPublication(cin);
   cout << "You entered:" << endl;
   cout << pd << endl;
   cout << "And the title is agian: \"" << (const char*)pd << "\"" << endl;
   pd.set(12345);
   if (pd.onLoan()) {
      cout << "Now this publication is on loan to a member with the id: 12345" << endl;
      pd.resetDate();
      cout << "The checkout date is: " << pd.checkoutDate() << endl;
      pd.setRef(9999);
      cout << "The library unique reference id is: " << pd.getRef() << endl;
      cout << pd << endl;
      cout << "----------------------------------------------------------------" << endl;
    }
   cout << "Adding the periodical publication to the end of the data file:" << endl;
   ofstream fileout("Periodicals.txt", ios::app);
   if (pd) {
      cout << "appeneded to the file" << endl;
      fileout << pd << endl;
   }
   fileout.close();
   cout << endl << "Contents of the file:" << endl;
   ifstream filein("Periodicals.txt");
   char pType{};
   for (int row = 1; filein; row++) {
      filein >> pType;
      if (pType != 'P') {
         cout << "The Record type signature is supposed to be B, but it is: " << pType << endl;
         filein.setstate(ios::failbit);
      }
      filein.ignore();
      pd = getNextRec(filein);
      if (filein) {
         cout << (pd.onLoan() ? "|*" : "| ");
         cout.width(4);
         cout.fill(' ');
         cout.setf(ios::right);
         cout << row << (pd.onLoan()? "*": " ");
         cout.unsetf(ios::right);
         cout << pd << (pd == "Star" ? "<<<":"") << endl;
      }
   }
   return 0;
}