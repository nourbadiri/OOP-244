/*
*****************************************************************************
                          Workshop - #2 (P1)
Full Name  : NOUR BADIRI
Student ID#: 108435215
Email      : nbadiri@myseneca.ca
Section    : NII
Date       : 05/27/2022

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
      
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* m_name);
   bool read(int m_studentNumber);
   bool read(char m_grade);
}
#endif // !SDDS_FILE_H_
