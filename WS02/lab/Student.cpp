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
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
	int noOfStudents;
	Student* students;
void sort() {
    int i, j;
    Student temp;
    	for (i = noOfStudents - 1; i > 0; i--) {
        	for (j = 0; j < i; j++) {
            	if (students[j].m_grade > students[j + 1].m_grade) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            	}
        	}
    	}
   	}
bool load(Student &students){
      bool ok = false;
      char name[128];
      if (read(name) && read(students.m_studentNumber) && read(students.m_grade)){
         students.m_name = new char[strlen(name) + 1];
         strcpy(students.m_name, name);
         ok = true;
      }
      return ok;
   }
bool load(const char* filename){
		bool ok = false;
      int i = 0;
      if (openFile(filename)){
         noOfStudents = noOfRecords();

         students = new Student[noOfStudents];

         for (int a = 0; a < noOfStudents; a++){
            i += load(students[a]);
         }

         if (i != noOfStudents){
            cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         }
         else{
            ok = true;
         }

         closeFile();
      }
      else{
         cout << "Could not open data file: " << filename << endl;
      }
      return ok;
	}

void display(const Student &students){
      cout << students.m_name << ", " << students.m_studentNumber << ": " << students.m_grade << endl;
   }

void display(){
    sort();
    for (int i = 0; i < noOfStudents; i++){
         cout << i + 1 << ": ";
         display(students[i]);
      }
   }
	
	void deallocateMemory(){
		for (int i = 0; i < noOfStudents; i++){

         delete[] students[i].m_name;
      }
      delete[] students;
   }
}
