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
 #ifndef SDDS_BASKET_H 
 #define SDDS_BASKET_H 
 #include<iostream> 
 #include<cstring> 
 using namespace std; 
 namespace sdds { 
    struct Fruit{
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };
    class Basket { 
        Fruit* m_fruits; 
        int m_cnt; 
        double m_price; 
        public: 
        Basket(); 
        Basket(Fruit fruits[], int cnt, double price);
        Basket(const Basket& b); 
        Basket& operator=(const Basket& b); 
        ~Basket(); 
        void setPrice(double price); 
        operator bool() const; 
        Basket& operator+=(Fruit add); 
        friend std::ostream& operator<<(std::ostream& out, const Basket& basket); 
    };
}
#endif