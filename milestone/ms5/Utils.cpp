
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include "Utils.h"
using namespace std;
namespace sdds {
int Utils::getInt(int minRange, int maxRange, const char* errorMessage) {
		int selectedItem = 0;
		bool trueInt = false;
		while (trueInt == false)
		{
			cin >> selectedItem;
			if (cin.fail() || selectedItem < minRange || selectedItem > maxRange)
			{
				cout << errorMessage;
				cin.clear();
				cin.ignore(1000, '\n');
				trueInt = false;
			}
			else
			{
				trueInt = true;
			}
		}
		return selectedItem;
	};
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
int Utils::strLen(const char* cstr)
	{
		int i;
		for (i = 0; cstr[i]; i++);
		return i;
	
}
void Utils::strCpy(char* des, const char* src) {
	while (*src) *des++ = *src++;
	*des = *src;
}


}