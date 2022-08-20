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
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
namespace sdds {
	class Book : public Publication {
		char* m_author{};
	public:
		Book();
		Book(const Book& src);
		Book& operator=(const Book& src);
		virtual ~Book();
		void setDefault();
		void set(int member_id);
		char type()const;
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		bool conIO(std::ios& io)const;
		operator bool()const;
	};
}
#endif