/*
*****************************************************************************
                          Workshop - #10 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 08/05/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/ 
#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	
	//Find with 3 parameters
	template <typename T1, typename T2>
	bool find(T1 Array[], int index, T2 key) {
		return Array[index] == key;
	}
	//Find with 4 parameters
	template <typename T1, typename T2, typename T3>
	int find(T1 Array[], int size, T2 key, T3 key2) {
		int element = 0;
		int i, j;

		for (i = 0; i < size; i++) {
			
			if (Array[i] == key){
				for (j = 0; j < size; j++) {
					if (Array[i] == key2){
					return element = i;
					}
				} 
			}
				
		}
		return element = -1;
	}
	//Insertion operator
	template<typename T> 
	std::ostream& operator <<(std::ostream& ostr, Collection<T>& col) {
		for (int i = 0; i < col.size(); i++) {
			ostr << col[i];
			ostr << std::endl;
		}		
		return ostr;
	}
	//Load Collection
	template <typename T>
	Collection<T>& loadCollection(Collection<T>& col, T item) {
			col += item;
			return col;
	}
}
#endif // !SDDS_SEARCH_H_

