 /*
*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/09/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<cstring> 
#include<string> 
#include <iomanip>
#include "Basket.h"
using namespace std;
namespace sdds { 
Basket::Basket(){
    this->m_cnt = 0;
	this->m_price = 0;
	this->m_fruits = nullptr;
}

Basket::Basket(Fruit fruits[], int cnt, double price ){
    if (fruits != nullptr && cnt >= 0 && price >= 0) {
			this->m_cnt = cnt;
			this->m_price = price;
			this->m_fruits = new Fruit[cnt];
			for (int i = 0; i < cnt; i++) {
				strcpy(this->m_fruits[i].m_name, fruits[i].m_name);
				this->m_fruits[i].m_qty = fruits[i].m_qty;
			}
		}
		else {
			this->m_cnt = 0;
		    this->m_price = 0;
		    this->m_fruits = nullptr;
		}
		
}
Basket::Basket(const Basket &b){
    if (b.m_fruits != nullptr && b.m_cnt >= 0 && b.m_price >= 0) {
			this->m_cnt = b.m_cnt;
			this->m_price = b.m_price;
			this->m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < b.m_cnt; i++) {
				strcpy(this->m_fruits[i].m_name, b.m_fruits[i].m_name);
				this->m_fruits[i].m_qty = b.m_fruits[i].m_qty;
			}
		}
		else {
			this->m_cnt = 0;
		    this->m_price = 0;
		    this->m_fruits = nullptr;
		} 
}  

Basket& Basket::operator=(const Basket& b){
    if (this != &b) {
			delete[] this->m_fruits;
            if (b.m_fruits != nullptr && b.m_cnt >= 0 && b.m_price >= 0) {
			this->m_cnt = b.m_cnt;
			this->m_price = b.m_price;
			this->m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < b.m_cnt; i++) {
				strcpy(this->m_fruits[i].m_name, b.m_fruits[i].m_name);
				this->m_fruits[i].m_qty = b.m_fruits[i].m_qty;
			}
		}
		else {
			this->m_cnt = 0;
		    this->m_price = 0;
		    this->m_fruits = nullptr;
		} 	
		}
		return *this;
}   

Basket::~Basket(){
    delete[] this->m_fruits;
}

void Basket:: setPrice(double price){
    m_price = price;
}

Basket::operator bool() const { 
    return m_fruits != NULL;
}

Basket& Basket:: operator+=(Fruit add){
 Fruit* temp;
        temp= new Fruit[m_cnt+1];
        for(int i = 0; i < m_cnt; i++){
            temp[i] = m_fruits[i];
        }
        m_cnt++;
        if(m_fruits != nullptr){
            delete[] m_fruits;
        }
        m_fruits = new Fruit[m_cnt];
        for(int a = 0; a < m_cnt; a++){
            m_fruits[a] = temp[a];
        }
        m_fruits[m_cnt - 1] = add;
        delete [] temp;
	return *this;
    }

std::ostream& operator<<(std::ostream &out, const Basket& basket){
    if(basket.m_cnt == 0){
        out<<"The basket is empty!"<<endl;
    }else{
        out<<"Basket Content:"<<endl;
        out<<fixed<<setprecision(2);
    for(int i=0;i<basket.m_cnt;i++){
        out<<right<<setw(10)<<basket.m_fruits[i].m_name<<": "<<basket.m_fruits[i].m_qty<<"kg"<<endl;
}
    out<<"Price: "<<basket.m_price<<endl;
}
return out;
}
}
