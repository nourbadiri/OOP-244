/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 06/01/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_ARMY_H_
#define SDDS_ARMY_H_
#define MAX_NAME_LEN 50
namespace sdds {
class Army{
private:
    char nationality[MAX_NAME_LEN+1];
    int units;
    double power;
public:
Army();
void setEmpty();
void createArmy(const char* country, double pow, int troops);
void updateUnits(int troops);
const char* checkNationality() const;
int checkCapacity() const;
double checkPower() const;
bool isEmpty() const;
bool isStrongerThan(const Army& army)const;
};
void battle( Army& arm1, Army& arm2);
void displayDetails(const Army* armies, int size);
}
#endif 