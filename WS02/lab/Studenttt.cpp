
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

bool load(const char* filename){
	noOfStudents = noOfRecords();
	students = new Student[noOfStudents];
	for(int i=0;i<noOfStudents; i++){
		if(!load(students[i])){
			cout<<"Error: incorrect number of records read; the data is possibly corrupted.";
			return false;
		}
	}
	closeFile();
	return true;
}

bool load(Student &students){
      bool ok = false;
      char name[128];
      if (read(students.m_studentNumber) && read(students.m_grade) && read(name)){
         students.m_name = new char[strlen(name) + 1];
         strcpy(students.m_name, name);
         ok = true;
      }
      return ok;
   }		

void display(const Student &students){
      cout << students.m_name << ": " << students.m_studentNumber << ", " << students.m_grade << endl;
   }

void display(){

    sort();

    for (int i = 0; i < noOfStudents; i++){
         cout << i + 1 << "- ";
         display(students[i]);
      }
   }
	
	void deallocateMemory(){
		delete[] students;
		noOfStudents=0;
		students=nullptr;
	}
}
