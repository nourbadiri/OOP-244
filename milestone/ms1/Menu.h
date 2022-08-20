 /*
*****************************************************************************
                          Final Project Milestone 1
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 07/08/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds {
class Menu;
class MenuItem{
    private:
    char* m_menuItem{};
    MenuItem();
    ~MenuItem();
    operator bool() const;
    MenuItem(const char* item);
    void display();
    friend Menu;
};
int const MAX_MENU_ITEMS = 20; 
class Menu {
    char* m_menuTitle{};
    MenuItem* m_items[MAX_MENU_ITEMS];
    int m_noofmenu=0;
    public:
    Menu();
    Menu(const char* title);
    ~Menu();
    void display();
    int run();
    int operator~();
    Menu& operator<<(const char* menuitemConent);
    char* operator[](int i) const;
    operator unsigned int() const;
    operator bool() const;
    std::ostream& write(std::ostream& os = std::cout)const;   
};
    std::ostream& operator<<(std::ostream& os, const Menu& m);
}
#endif