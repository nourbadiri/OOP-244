/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 05/30/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "BirthDate.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
    FILE *fptr;
    Employee *employee;
    int noOfEmployee;
    int inputMonth;
    int numResult;

    bool beginSearch(const char *filename) {
        fptr = fopen(filename, "r");
        if (fptr != NULL) {
            loadFile();
            cout << "Birthdate search program" << "\n";
            return true;
        }
        else {
            cout << "Data file " << filename << " not found!";
            return false;
        }               
    }

    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployee - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employee[j].year > employee[j + 1].year) {
                    temp = employee[j];
                    employee[j] = employee[j + 1];
                    employee[j + 1] = temp;
                }
            }
        }
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
        if (fptr)
            fclose(fptr);
    }

    bool loadFile() {

        int k;
        char tempName[30 + 1];
        employee = nullptr;
        noOfEmployee = noOfRecords() + 1;
        employee = new Employee[noOfEmployee];
        //cout << "lines : " << noOfEmployee << endl;
        for (k = 0; k < noOfEmployee; k++) {
            if (readName(tempName) && readMonth(employee[k].month) && 
                readDay(employee[k].day), readYear(employee[k].year))
            {
             
                employee[k].name = new char[strlen(tempName) + 1];
                strcpy(employee[k].name, tempName);
             
            }
        }
        return true;
    }

    bool readName(char *name) { 
        return fscanf(fptr, "%[^,],", name) == 1;
    }

    bool readDay(int &day) {
        return fscanf(fptr, "%d/", &day) == 1;
    }

    bool readMonth(int &month) { 
        return fscanf(fptr, "%d/", &month) == 1;
    }
   
    bool readYear(int &year) {
        return fscanf(fptr, "%d\n", &year) == 1;
    }
    void displayBirthdays() { 
        int k = 0;
        int p = 1;
        cout << numResult << " birthdates found:" << endl;
       for (k = 0; k < noOfEmployee ; k++) {
         
           if (employee[k].month == inputMonth) {
               cout << p << ") " << employee[k].name
                   << ":" << endl;
               cout << employee[k].year << "-" << employee[k].month
                   << "-" << employee[k].day << endl;
               cout << "===================================" << endl;
                p += 1;
           }
        }
        rewind(fptr);
    }
    void deallocate() { 
       return;
    }	

    void endSearch() { 
         int i;
        for (i = 0; i < noOfEmployee; i++) {
            delete[] employee[i].name;
        }
        delete[] employee;
        employee = nullptr;
        if (fptr)
            fclose(fptr);
        fptr = nullptr;
        cout << "Birthdate Search Program Closed." << endl;
    }

    bool readBirthDate(int month) {
        inputMonth = month;
        int k;
        numResult = 0;
        for (k = 0; k < noOfEmployee; k++) {
            if (employee[k].month == inputMonth)
                numResult += 1;                 
        } 
        return numResult;
    }
} 

