/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 06/09/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "Car.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds{

void Car::resetInfo(){
    m_type=nullptr;
    m_brand=nullptr;
    m_model=nullptr;
    m_year=0;
    m_code=0;
    m_price=0;
    }
Car::Car()
   {
      resetInfo();
   }   
Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price){
	resetInfo();
	this->setInfo(type, brand, model, year, code, price);
} 
Car::Car(const char* type, const char* brand, const char* model){
    resetInfo();
    setInfo(type, brand, model, 2022, 100, 1);
}
Car::~Car(){
    delete [] m_type;
    m_type = nullptr;
    delete [] m_brand; 
    m_brand = nullptr;
    delete [] m_model;
    m_model = nullptr;
    m_year = 0;
    m_code = 0;
    m_price = 0;
    }
Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price){
    delete[] m_type;
	m_type = nullptr;
	delete[] m_brand;
	m_brand = nullptr;
	delete[] m_model;
	m_model = nullptr;
	if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code < 100 || price < 0){
		resetInfo();
	}
	else{
		m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		    strcpy(m_model, model);

		m_year = year;
		m_code = code;
		m_price = price;
	}
        return *this;
}

void Car::printInfo() const{
    cout << "| " << setw(11) << left << m_type << "| " << setw(17) << m_brand << "| " << setw(17) << m_model << "| " << setw(5) 
    << m_year << "|  " << setw(4) << m_code << "|" << setw(10) << right << fixed << setprecision(2) << m_price << " |" << endl;
}

bool Car::isValid() const{
    return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_price > 0;
}
bool Car::isSimilarTo(const Car& car) const{
    return m_type == car.m_type && m_brand == car.m_brand && m_model == car.m_model && m_year == car.m_year;       
}

bool has_similar(const Car car[], const int num_cars){
    bool found = true;
    for (int i = 0; i < num_cars; i++){
        for (int j = i + 1; j < num_cars; j++){
            if (car[i].isSimilarTo(car[j])){
                found= true;
            } 
        }
    }
return found;

}
bool has_invalid(const Car car[], const int num_cars){
    for (int i = 0; i < num_cars; i++){
            if (car[i].isValid()){
                return true;
            }
        }
                return false;
}
void print(const Car car[], const int num_cars){
    for (int i = 0; i < num_cars; i++){
        if(car[i].isValid()){
            car[i].printInfo();
        }
        else{
            bool has_invalid();
    }
    }
}
}