 /*
*****************************************************************************
                          Final Project Milestone 3
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/22/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Lib.h"
using namespace std;
namespace sdds {
	Publication::Publication(){
        m_title=nullptr;
        m_shelfId[0]='\0';
        m_membership=0;
        m_libRef = -1;
    }
	Publication::Publication(const Publication& pub) {
		*this = pub;
	}
	Publication& Publication::operator=(const Publication& pub) {
		if (this != &pub){
			if (m_title){
				delete[] m_title;
				m_title = nullptr;
			}
			if (pub.m_title){
				m_title = new char[strlen(pub.m_title) + 1];
				strcpy(m_title, pub.m_title);
			}
			strcpy(m_shelfId, pub.m_shelfId);
			set(pub.m_membership);
			setRef(pub.m_libRef);
			m_date = pub.m_date;
		}
		return *this;
	}
	Publication::~Publication(){
		delete [] m_title;
        m_title = nullptr;
        
        m_shelfId[0] = '\0';
        m_membership=0;
        m_libRef = -1;
	}
	void Publication::set(int member_id) {
		m_membership = member_id;
	}
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	void Publication::resetDate() {
		m_date = Date();
	}
	char Publication::type()const {
		return 'P';
	}
	bool Publication::onLoan()const {
		return m_membership != 0;
	}
	Date Publication::checkoutDate()const {
		return m_date;
	}
	bool Publication::operator==(const char* title)const {
		return strstr(m_title, title) != nullptr;
	}
	Publication::operator const char* ()const {
		return m_title;
	}
	int Publication::getRef()const {
		return m_libRef;
	}
	bool Publication::conIO(const ios& io)const {
		return &io == &std::cin || &io == &std::cout;
	}
	ostream& Publication::write(ostream& os) const {
		if (conIO(os)) {
			os << "| ";
			os << m_shelfId;
			os << " | ";
			os.setf(ios::left);
			os.fill('.');
			os.width(SDDS_TITLE_WIDTH);
			os << m_title;
			os.unsetf(ios::left);
			os.fill(' ');

			
			os << " | ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | ";
			os << m_date;
			os << " |";
		}
		else{
			os << type();
			os << "\t";
			os << m_libRef;
			os << "\t";
			os << m_shelfId;
			os << "\t";
			os << m_title;
			os << "\t";
			os << m_membership;
			os << "\t";
			os << m_date;
		}
		return os;
	}
	void Publication::setTodefaultValue() {
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
	}
	std::istream& Publication::read(std::istream& is) {
		char shelfid[SDDS_SHELF_ID_LEN + 2] = { 0 },
			title[256] = { 0 };
		int libref = -1, membership = 0;
		Date date;
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
		m_membership = 0;
		m_libRef = -1;
		m_shelfId[0] = 0;
		if (conIO(is)) {
			std::cout << "Shelf No: ";
			is.get(shelfid, SDDS_SHELF_ID_LEN + 2);
			if (is.gcount() != SDDS_SHELF_ID_LEN) {
				is.setstate(std::ios_base::failbit);
			}
			else {
				is.ignore(1000, '\n');
			}
			std::cout << "Title: ";
			is.get(title, sizeof(title), '\n');
			std::cout << "Date: ";
			is >> date;
		}else {
			is >> libref;
			is.ignore();
			is.get(shelfid, SDDS_SHELF_ID_LEN + 1, '\t');
			is.ignore();
			is.get(title, sizeof(title), '\t');
			is.ignore();
			is >> membership;
			is.ignore();
			is >> date;
		}
		if (!date) {
			is.setstate(std::ios_base::failbit);
		}
		if (is.good()) {
			m_title = new char[std::strlen(title) + 1];
			std::strcpy(m_title, title);
			std::strcpy(m_shelfId, shelfid);
			m_membership = membership;
			m_date = date;
			m_libRef = libref;
		}
		return is;
	}
	Publication::operator bool() const {
		return m_title && m_shelfId[0];
	}
};