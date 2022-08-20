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
#include <iostream>
#include "BarChart.h"
using namespace sdds;
using namespace std;
int main() {
   BarChart bc;
   bc.init("How much students like this lab.", 5, '=');
   bc.add("Best Lab Ever", 2);
   bc.add("Good Lab", 10);
   bc.add("Doable Lab", 63);
   cout << "Premature draw call:"<< endl; 
   bc.draw(); // will not draw; it will print an error instead
   bc.add("Bad Lab", 10);
   bc.add("Worst Lab Ever", 5);
   cout << "Proper draw call after all samples are entered:" << endl;
   bc.draw();
   bc.deallocate();
   return 0;
}