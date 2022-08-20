
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