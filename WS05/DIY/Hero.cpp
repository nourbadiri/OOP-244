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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Hero.h"
#include "Power.h"

using namespace std;

namespace sdds {
	Hero::Hero(){
		h_name[0] = '\0';
		p_powers = new Power[1];
		powerscount = 0;
		powerlevel = 0;
	}

	Hero::Hero(const char* name, Power* powers, int powerscount){
		strcpy(this->h_name, name);
		this->p_powers = powers;
		this->powerscount = powerscount;
		int sum = 0;
		for (int i = 0;i < powerscount;i++) {
			sum += this->p_powers[i].checkRarity();
		}
		this->powerlevel = sum*powerscount;
	}

	Hero::~Hero(){
		h_name[0]='\0';
    	delete [] p_powers; 
    	p_powers = nullptr;
    	powerscount = 0;
    	powerlevel = 0;
	}
	ostream& Hero::display() const {
		cout << "Name: " << h_name << endl;
		cout << "List of available powers: " << endl;
		for (int i = 0; i < powerscount; i++) {
			if (!p_powers[i].isEmpty()) {
				cout << "  Name: " << p_powers[i].checkName() << ", "
					<< "Rarity: " << p_powers[i].checkRarity() << endl;
			}
		}
		cout << "Power Level: " << this->powerlevel;
		return cout;
	}

	Hero& Hero::operator +=(const Power& pow){
		Power* temp = new Power[powerscount + 1];
		for (int i = 0;i < powerscount;i++) {
			temp[i] = p_powers[i];
		}
		temp[powerscount] = pow;
		powerscount += 1;
		p_powers = new Power[powerscount];
		for (int i = 0;i < powerscount;i++) {
			p_powers[i] = temp[i];
		}
		delete[] temp;
		int sum = 0;
		for (int i = 0;i < powerscount;i++) {
			sum += p_powers[i].checkRarity();
		}
		powerlevel = sum * powerscount;
		return (*this);
	}

	Hero& Hero::operator -=(const int& i){
		powerlevel -= i;
		return (*this);
	}

	bool Hero::operator<(const Hero& her){
		return powerlevel < her.powerlevel;
	}

	bool Hero::operator>(const Hero& her){
		return powerlevel > her.powerlevel;
	}

	void operator >>(const Power& pow, Hero& her){
		Power* temp = new Power[her.powerscount + 1];
		for (int i = 0;i < her.powerscount;i++) {
			temp[i] = her.p_powers[i];
		}
		temp[her.powerscount] = pow;
		her.powerscount += 1;
		her.p_powers = new Power[her.powerscount];
		for (int i = 0;i < her.powerscount;i++) {
			her.p_powers[i] = temp[i];
		}
		delete[] temp;
		int sum = 0;
		for (int i = 0;i < her.powerscount;i++) {
			sum += her.p_powers[i].checkRarity();
		}
		her.powerlevel = sum * her.powerscount;
	}

	void operator <<(Hero& her, const Power& pow){
		Power* temp = new Power[her.powerscount + 1];
		for (int i = 0;i < her.powerscount;i++) {
			temp[i] = her.p_powers[i];
		}
		temp[her.powerscount] = pow;
		her.powerscount += 1;
		her.p_powers = new Power[her.powerscount];
		for (int i = 0;i < her.powerscount;i++) {
			her.p_powers[i] = temp[i];
		}
		delete[] temp;
		int sum = 0;
		for (int i = 0;i < her.powerscount;i++) {
			sum += her.p_powers[i].checkRarity();
		}
		her.powerlevel = sum * her.powerscount;
	}

	ostream& operator << (std::ostream& ostr, const Hero& her){
		ostr << "Name: " << her.h_name << endl;
		ostr << "List of available powers: " << endl;
		for (int i = 0; i < her.powerscount; i++) {
			if (!her.p_powers[i].isEmpty()) {
				ostr << "  Name: " << her.p_powers[i].checkName() << ", "
					<< "Rarity: " << her.p_powers[i].checkRarity() << endl;
			}
		}
		ostr << "Power Level: " << her.powerlevel;
		return ostr;
	}
}