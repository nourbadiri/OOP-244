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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CleanerBot.h"
using namespace std;
namespace sdds {
	CleanerBot::CleanerBot() {
		set();
	}
	CleanerBot::CleanerBot(const char* location, double battery, int brush, bool active) {
		set();
		setLocation(location);
		c_battery = battery;
		c_brush = brush;
		setActive(active);
	}
	CleanerBot::~CleanerBot() {
		delete[] c_location;
		c_location = nullptr;
		c_battery = 0.0;
		c_brush = 0;
		c_active = false;
	} 
	void CleanerBot::set() {
		c_location = nullptr;
		c_battery = 0.0;
		c_brush = 0;
		c_active = false;
	}
	void CleanerBot::setLocation(const char * location) {
		c_location = new char[strlen(location) + 1];
		strcpy(c_location, location);
	}
    bool CleanerBot::setActive(const bool active) {
		
		return c_active = active;
    }
	const char* CleanerBot::getLocation() const
	{
		return c_location;
	}
	double CleanerBot::getBattery()const {
		return c_battery;
	}
	
	int CleanerBot::getBrush()const {
		return c_brush;
	}

	bool CleanerBot::isActive()const {
		return c_active ? true:false;
	}

	bool CleanerBot::isValid() const {
		return (c_location != nullptr) && (c_battery > 0.0 && c_brush > 0) ;
	}
	int report(CleanerBot* bot, short num_bots) {
		
		cout << "         ------ Cleaner Bots Report -----\n";
		cout << "     ---------------------------------------\n";
		printf("| Location   | Battery |  Number of Brushes | Active |\n");
		printf("|------------+---------+--------------------+--------|\n");
		for (int i = 0; i < num_bots; i++) {
			if (bot[i].isValid()) {
				cout << "| " << setw(8) << bot[i].getLocation()<< " | " << setw(6) << fixed << setprecision(1) 
    << bot[i].getBattery()<< " | " << setw(5) << bot[i].getBrush()<< " | " << (bot[i].isActive()? "YES" : "NO") << " |" << endl;
			}
		}
		cout << "\n";
		cout << "|====================================================|\n";
		cout << "| LOW BATTERY WARNING:                               |\n";
		cout << "|====================================================|\n";
		int needCharge = 0;
		for (int i = 0; i < num_bots; i++)
		{
			if (bot[i].isValid() && bot[i].getBattery() < 30)
			{
				needCharge++;
			}
		}
		cout << "| Number of robots to be charged: " << needCharge <<
			"                  |\n";
		cout << "| Sorting robots based on their available power:     |\n";
		cout << "| Location   | Battery |  Number of Brushes | Active |\n";
		cout << "|------------+---------+--------------------+--------|\n";

		double* batteryTemp;
		batteryTemp = new double[num_bots];
		int* temp;
		temp = new int[num_bots];
		double temp1;
		int temp2;
		for (int i = 0; i < num_bots; i++) {
			batteryTemp[i] = bot[i].getBattery();
			temp[i] = i;
		}
		for (int i = 0; i < num_bots - 1; i++) {
			for (int j = i + 1; j < num_bots; j++) {
					if (batteryTemp[i] < batteryTemp[j]) {
						temp1 = batteryTemp[i];
						temp2 = temp[i];
						temp[i] = temp[j];
						temp[j] = temp2;
						batteryTemp[i] = batteryTemp[j];
						batteryTemp[j] = temp1;
					}
				}
		}
		for (int i = 0; i < num_bots; i++)
		{
			if (batteryTemp[i] > 0)
			{
				printf("| %-10s | %7.1lf | %18d | %-6s |\n", bot[temp[i]].getLocation(), bot[temp[i]].getBattery(), 
				bot[temp[i]].getBrush(), bot[temp[i]].isActive() ? "YES" : "NO");
			}
		}
		cout << "|====================================================|\n";
		delete[] batteryTemp;
		delete[] temp;
		return 0;
	}
} 