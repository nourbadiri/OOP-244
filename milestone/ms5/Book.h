
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