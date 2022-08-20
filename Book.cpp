/*
*****************************************************************************
                          Workshop - #5 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 06/16/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}
	int Book::operator++(int){
		return m_num_chapters++;
	}
	int Book::add_chapter(Chapter* chapter) {
        m_chapters[m_num_chapters++] = *chapter;
        m_num_pages += int(*chapter);
        return int(m_num_chapters);
    }
  	ostream& Book::display(std::ostream& os)const{
		os << "Title:'" << m_title << "'\n";
        os << "Author: '" << m_author << "'\n";
        for (int i = 0; i < m_num_chapters; i++)
            os << m_chapters[i] << std::endl;
        return os;
	}
    Book::operator int(){
		return m_num_chapters;
	}
    Book::operator bool(){
		if (m_title[0] != '\0' && m_author[0] != '\0' && m_num_chapters != 0)
            for (int i = 0; i < m_num_chapters; i++)
                if (int(m_chapters[i]) != 0)
                    return true;
        return false;
	}
    Book::operator double(){
		return m_price;
	}
    Book::operator char*(){
		return m_title;
	}
    Book& Book::operator+=(Chapter chapter){
		add_chapter(&chapter);
		return *this;
	}
    Book& Book::operator-=(double price){
		m_price -= price;
		return *this;
	}
    std::ostream& operator<<(std::ostream& os,const Book& book){
		return book.display(os);
	}
}
