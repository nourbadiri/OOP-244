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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Army.h"
using namespace std;
namespace sdds {
    Army::Army(){
        setEmpty();
    }
void Army::setEmpty(){
    nationality[0]='\0';
    units = 0;
    power = 0;
}
void Army::createArmy(const char* country, double pow, int troops){
  if(country != nullptr && strlen(country) > 0 && pow > 0 && troops > 0)
{

if(strlen(country) > MAX_NAME_LEN) 
{
strncpy(nationality, country, MAX_NAME_LEN);
}
else 
strcpy(nationality, country);

units = troops;
power = pow;
}
else 
setEmpty();
}
void Army::updateUnits(int troops){
    units += troops; // add input troops to units
    power += troops*0.25; // add 25% of the newly provided troops as power
}
const char* Army::checkNationality() const{
    return nationality;
}
int Army::checkCapacity() const{
    return units;
}
double Army::checkPower() const{
    return power;
}
bool Army::isEmpty() const{
    if(strlen(nationality) == 0 && units <= 0)
        return true;
    else
        return false; 
}
bool Army::isStrongerThan(const Army& army) const{
    if(power>army.power)
        return true;
    else
        return false;
}
void battle( Army& arm1, Army& arm2){
    if(!arm1.isEmpty() && !arm2.isEmpty()){
cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality();
// arm2 is the loosing army
if(arm1.isStrongerThan(arm2)){
// decrement the units of arm2 by 50%
arm2.updateUnits(-arm2.checkCapacity()/2);
cout << ", " << arm1.checkNationality() << " is victorious!" << endl;
}
else
{
// arm1 is the loosing army
cout << ", " << arm2.checkNationality() << " is victorious!" << endl;
// decrement the units of arm1 by 50%
arm1.updateUnits(-arm1.checkCapacity()/2);
}
}
}
void displayDetails(const Army* armies, int size){
    cout << "Armies reporting to battle: " << endl;

for(int i=0;i<size;i++){
if(!armies[i].isEmpty())
cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " << armies[i].checkCapacity()
<< ", Power left: " << fixed << setprecision(1) << armies[i].checkPower() << endl;
}
}
}