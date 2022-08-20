
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
	class Utils {
	public:
		Utils() = delete;
		int static getInt(int minRange, int maxRange, const char* errorMessage);
		static void getChar(std::istream& is, char ch); 
		static void getChar(std::istream& is);	
		static void copyStr(char*& des, const char* src);	
		static int strLen(const char* cstr);
		void static strCpy(char* des, const char* src);
		
	};
}
#endif