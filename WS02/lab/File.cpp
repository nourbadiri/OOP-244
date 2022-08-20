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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   bool read(char* m_name){
      fptr = fopen(filename, "r");
      fscanf(fptr, "%[^,],", m_name);
      return 1;
   }
   bool read(int m_studentNumber){
      fptr = fopen(filename, "r");
      fscanf(fptr, "%d,", &m_studentNumber);
      return 1;
   }
   bool read(char m_grade){
      fptr = fopen(filename, "r");
      fscanf(fptr, "%c\n", &m_grade);
      return 1;
   }
}