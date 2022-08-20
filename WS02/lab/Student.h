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
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include<iostream>


namespace sdds {
  struct Student {
     char* m_name;
     int m_studentNumber;
     char m_grade;
    };

void sort();
bool load(const char filename[]);
bool load(Student &students);
void display(const Student &students);
void display();
void deallocateMemory();
}
#endif