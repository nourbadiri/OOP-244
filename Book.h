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
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds {
   const int MAX_NUM_CHAPTERS = 10;
   const int MAX_BOOK_TITEL = 40;
   const int MAX_AUTHOR_NAME = 20;
    class Book
    {
        char m_title[MAX_BOOK_TITEL+1];
        char m_author[MAX_AUTHOR_NAME+1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();
        int add_chapter(Chapter* chapter);
    
    public:
        Book();
        Book(const char* title_);
        Book(const char* title_, const char* author_, double price_);
        void summary(); 
        int operator++(int); 
        std::ostream& display(std::ostream&)const; 
        operator int(); 
        operator bool();
        operator double();
        operator char*();
        Book& operator+=(Chapter chapter);
        Book& operator-=(double price);
    };
    std::ostream& operator<<(std::ostream& os,const Book& book); // helper

}
#endif
