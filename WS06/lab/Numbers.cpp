/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/05/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const Numbers& n) {
      setEmpty(); 
      m_isOriginal = false;
      m_numCount = n.m_numCount;
      m_numbers = new double[m_numCount];
         for(int i = 0; i < m_numCount; i++){
            m_numbers[i] = n.m_numbers[i];
         }
      m_filename = new char[strlen(n.m_filename) + 1];
      strcpy(m_filename,n.m_filename);  
    }

   Numbers& Numbers::operator=(const Numbers& number){
   if(this != &number){
      if(m_numbers != nullptr){
          delete[] m_numbers;
          m_numbers = nullptr;   
      }
    } 
    m_numbers = new double[number.m_numCount];
    m_numCount = number.m_numCount;
    for(int i = 0; i < m_numCount; i++){
        m_numbers[i] = number.m_numbers[i];
    }
    setFilename(number.m_filename);
    return *this;
}
   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
      
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }   

   int Numbers::numberCount() {
   ifstream f(m_filename);
        char ch[10];
        int num = 0;
        while (f.getline(ch,10)) {
            num++;
        }
        return num;
    }

   bool Numbers::load(){
      ifstream inFile;
      inFile.open(m_filename);
      if(!inFile || m_numCount == 0){
        delete[] m_numbers;
        setFilename(NULL);
        m_isOriginal = false;
        cout << "Error opening file" << endl;
        return false;
    }
    m_numbers = new double[m_numCount];
    for(int i = 0; i < m_numCount; i++){
        inFile >> m_numbers[i];
    }
    inFile.close();
    return true; 
    }

   bool Numbers::save(){
     if (m_isOriginal && !isEmpty()) {
            ofstream f(m_filename);
            if (!f) {
                cout << "Error opening file" << endl;
                exit(1);
            }
            for (int i = 0; i < m_numCount; i++) {
                f << m_numbers[i] << endl;
            }
            f.close();
            return true;
        }
        return true;
    }
    
   ostream& Numbers::display(std::ostream & ostr) const{
       if (m_numCount == 0) {
            ostr << "Empty list";
        }
        else {
            ostr << "=========================" << endl;
            if(m_isOriginal)ostr << m_filename << endl;
            else ostr << "*** COPY ***" << endl;
            for (int i = 0; i < m_numCount; i++) {
                 ostr << m_numbers[i];
                 if (i <  m_numCount - 1) {
                     ostr << ", ";
                  }
            }
             ostr << endl << "-------------------------" << endl;
             ostr << "Total of " << m_numCount << " number(s)" << endl;
             ostr << "Largest number:  "   << max() << endl;
             ostr << "Smallest number: "  << min() << endl;
             ostr << "Average :        " << average() << endl;
             ostr << "=========================";
         }
        return ostr;  
   }

   Numbers& Numbers::operator+=(const double numbers){
      double* temp;
        temp = new double[m_numCount + 1];
        temp[0] = numbers;
        for (int i = 0; i < m_numCount; i++) {
            temp[i + 1] = m_numbers[i] ;
        }
        m_numCount++;
        delete[] m_numbers;
        m_numbers = temp;
        sort();
        return *this; 
   }

   ostream& operator<<(std::ostream& os, const Numbers& N){
      return N.display(os);
   }
   istream& operator>>(std::istream& istr, Numbers& N){
      double temp;
      istr>>temp;;
      N += temp;
      return istr;
   }           
}