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
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Utils.h"
#include "Lib.h"
namespace sdds {

	class Publication : public Streamable {
		char* m_title{};
		char m_shelfId[SDDS_SHELF_ID_LEN +1]{};
		int m_membership{};
		int m_libRef{ -1 };
		Date m_date;
	public:
	    virtual void setDefault();
		Publication();
		Publication(const Publication& pbc);
		Publication& operator=(const Publication& pbc);
		~Publication();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		bool conIO(const std::ios& iosref)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		void setTodefaultValue();
		operator bool() const;
	};
};
#endif