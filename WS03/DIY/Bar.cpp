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
#include "Bar.h"
#include <iostream>
using namespace std;
namespace sdds{

void Bar::setEmpty(){
  title = " ";
  fill = ' ';
  value = 0;
}

void Bar::init(string t, char f, int v){
  if (v < 0 || v > 100){
    setEmpty();
  }
  else{
    title = t;
    fill = f;
    value = v;
  }
}

bool Bar::isValid() const{
  return title != "" && fill != ' ' && value != 0;
}

void Bar::draw() const{
  if (isValid()){
    cout << title; // print the title

    int dots = MAX_CHAR - title.length(); // print dots after the title
    cout << string(dots, '.');

    cout << '|'; // print the pipe

    cout << string(value/2, fill)<< endl; // print the fill character
  }
}
}