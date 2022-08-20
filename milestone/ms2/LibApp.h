 /*
*****************************************************************************
                          Final Project Milestone 2
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/14/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_LIBAPP_H_
#define SDDS_LIBAPP_H_
#include "Menu.h"
#include <iostream>
namespace sdds {
class LibApp{
    bool m_changed=false;
    Menu m_mainMenu{"Seneca Library Application"};
    Menu m_exitMenu{"Changes have been made to the data, what would you like to do?"};
bool confirm(const char* message);
void load();
void save();
void search(); 
void returnPub();
void newPublication();
void removePublication();
void checkOutPub();
public:
LibApp();
void run();
};
}
#endif 