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
#include "BarChart.h"
#include <iostream>
using namespace std;
namespace sdds{

bool BarChart::isValid() const{
  for (int i = 0; i < sizeBars; i++){
    if (!bars[i].isValid()){
      return false;
    }
  }
  return true;
}

void BarChart::init(const char* title, int noOfSampels, char fill){
  
  chartTitle = title;
  
  sizeBars = noOfSampels;
  samplesAdded = 0;
  bars = new Bar[sizeBars];
  
  fillChar = fill;
}

void BarChart::add(const char* bar_title, int value){
  
  Bar b;
  b.init(bar_title, fillChar, value);
  
  if (samplesAdded < sizeBars){
    bars[samplesAdded] = b;
    samplesAdded++;
  }
}

void BarChart::draw() const{
  if (isValid()){
    cout << chartTitle << endl;
    cout << string(71, '-') << endl;
    for (int i = 0; i < sizeBars; i++){
      bars[i].draw();
    }
    cout << string(71, '-') << endl;
  }
  else{
    cout << "Invalid Chart!" << endl;
  }
}

void BarChart::deallocate(){
  int i;
        for (i = 0; i < sizeBars; i++) {
            delete[] bars;
        }
  chartTitle = nullptr;
  bars = nullptr;
  delete chartTitle;
  delete bars;
  }  
}