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
#ifndef SDDS_BIRTHDATE_H_
#define SDDS_BIRTHDATE_H_

namespace sdds {
// struct for employee info
	struct Employee {
		char *name;
		int day;
		int month;
		int year;
	};
	bool beginSearch(const char *filename); 
	bool readBirthDate(int month);
	bool readName(char *name);
	bool readDay(int &day);
	bool readMonth(int &month);
	bool readYear(int &year);
	void sort();          
	void displayBirthdays();
	void deallocate();	
	void endSearch();    
	int noOfRecords();  
	bool loadFile(); 
} 
#endif