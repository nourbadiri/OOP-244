
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
      if (read(students.m_studentNumber) && read(students.m_grade) && read(name)){
         students.m_name = new char[strlen(name) + 1];
         strcpy(students.m_name, name);
         ok = true;
      }
      return ok;
   }
bool load(const char* filename){
		FILE* fptr;
		fptr = fopen(filename, "r");		
		if(!openFile(filename)){
			return false;
		}
		noOfStudents=noOfRecords();
		closeFile();
				
		students = new Student[noOfStudents];
	
		for(int i=0;i<noOfStudents;i++){
			int index=0;
			char name[128],ch;
			wh	ile (fscanf(fptr, "%c", &ch) == 1) {
		        if(ch==',') break;
		        else{
		        	name[index++]=ch;
				}
		    }
 		students[i].m_name = new char[index];
		    students[i].m_name[index]='\0';
		    while(index--){
		    	students[i].m_name[index]=name[index];
			}
			
		    while (fscanf(fptr, "%c", &ch) == 1) {
		        if(ch=='\n') break;
		        students[i].m_grade=ch;
             }
		}	
	return true;
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
