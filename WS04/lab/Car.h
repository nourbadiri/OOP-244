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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
namespace sdds{
class Car{
    char* m_type;
    char* m_brand;
    char* m_model;
    int m_year;
    int m_code;
    double m_price;
    void resetInfo();
public:
    Car();
    Car(const char* type, 
    const char* brand, 
    const char* model);
    Car(const char* type, 
    const char* brand, 
    const char* model, 
    int year, 
    int code, 
    double price);
    ~Car();
    Car& setInfo(const char* type, 
            const char* brand, 
            const char* model, 
            int year, 
            int code, 
            double price);
    void printInfo() const;
    bool isValid() const;
    bool isSimilarTo(const Car& car) const;
};
    bool has_similar(const Car car[], const int num_cars);
    bool has_invalid(const Car car[], const int num_cars);
    void print(const Car car[], const int num_cars);
}
#endif