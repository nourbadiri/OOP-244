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
#include "Streamable.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Streamable& st) {
		if (st) {
			st.write(os);
		}
		return os;
	}
	std::istream& operator>>(std::istream& istr, Streamable& st) {
		st.read(istr);
		return istr;
	}
}