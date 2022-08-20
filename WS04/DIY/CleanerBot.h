/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 06/13/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H	
namespace sdds {
class CleanerBot {
	char* c_location;   
	double c_battery;      
	int c_brush;         
	bool c_active;         
public:
	CleanerBot();
	CleanerBot( const char* location,double battery, int brush,bool active);
	~CleanerBot();
	void set();
	void setLocation(const char* location);
	bool setActive(const bool active);
	const char* getLocation() const; 	
	double getBattery() const;
	int getBrush() const;
	bool isActive() const;
	bool isValid() const;
	}; 
	int report(CleanerBot* bot, short num_bots);
} 
#endif 
