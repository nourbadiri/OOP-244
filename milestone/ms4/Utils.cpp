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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include "Utils.h"
namespace sdds {
void Utils::getChar(std::istream& is, char ch) {
    if (is.peek() == ch) is.get();
}
void Utils::getChar(std::istream& is) {
    if (isdigit(is.peek())) {
        is.setstate(std::ios::failbit);
    }
    else {
        is.get();
}
}
void Utils::copyStr(char*& des, const char* src) {
    delete[] des;
    des = new char[strlen(src) + 1];
    strcpy(des, src);
}
int Utils::strLen(const char* str) {
    int len = -1;
	while (str[++len]);
	return len;
}
void Utils::strCpy(char* des, const char* src) {
	while (*src) *des++ = *src++;
	*des = *src;
}
}