 /*
*****************************************************************************
                          Final Project Milestone 4
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/28/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
	class Utils {
	public:
		Utils() = delete;
		static void getChar(std::istream& is, char ch); 
		static void getChar(std::istream& is);	
		static void copyStr(char*& des, const char* src);	
		int static strLen(const char* str);
		void static strCpy(char* des, const char* src);
	};
}
#endif