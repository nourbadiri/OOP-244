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
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds {
	void Chapter::init_chapter() {
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}
	Chapter::Chapter() {
		init_chapter();
	}

	Chapter::Chapter(const char* title_) {
		init_chapter();
		strcpy(m_title , title_);
	}
	Chapter::Chapter(const char* title_, int chapter_num,  int n_pages, int n_words) {
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}
	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |";
		return os;
	}
	Chapter::operator int(){
		return m_num_pages;
	}
	Chapter::operator double(){
		return (double(m_num_words) / double(m_num_pages)); 
	}
	Chapter::operator const char*(){
		return m_title;
	}
	Chapter& Chapter::operator=(const Chapter& chapter){
		strcpy(m_title, chapter.m_title);
        m_num_pages = chapter.m_num_pages;
        m_num_words = chapter.m_num_words;
        m_chapter_number = chapter.m_chapter_number;
		return *this;
	}
	int Chapter::operator++(){
		return ++m_num_pages;
	}
	int Chapter::operator--(){
		return --m_num_pages;
	}
	std::ostream& operator<<(std::ostream& os,const Chapter& chapter){
		return chapter.display(os);
	}
}

