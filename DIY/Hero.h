/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 06/18/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include "Power.h"


namespace sdds {
	class Hero {
		
		char h_name[MAX_NAME_LENGTH +1];
		Power* p_powers;
		int powerscount;
		int powerlevel;
		public:
		Hero();
		Hero(const char* name, Power* powers, int powerscount);
		~Hero();
		std::ostream& display() const;
		Hero& operator +=(const Power& pow);
		Hero& operator -=(const int& i);
		bool operator<(const Hero& her);
		bool operator>(const Hero& her);
		friend void operator >>(const Power& pow, Hero& her);
		friend void operator <<(Hero& her, const Power& pow);
		friend std::ostream& operator << (std::ostream& ostr, const Hero& her);		
	};
}
#endif