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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "LibApp.h"
using namespace std;
namespace sdds {
bool LibApp::confirm(const char* message){
    Menu confirm(message);
        confirm<<"Yes";
        int t_return = confirm.run();
        if(t_return) 
            return true;
        else
            return false;
}
void LibApp::load(){
    cout<<"Loading Data"<<endl;
}
void LibApp::save(){
    cout<<"Saving Data"<<endl;
    }
void LibApp::search(){
    cout<<"Searching for publication"<<endl;
    }
void LibApp::returnPub(){
    search();
    cout<<"Returning publication"<<endl;
    cout<<"Publication returned"<<endl;
    m_changed=true;
}
void LibApp::newPublication(){
    cout<<"Adding new publication to library"<<endl;
    if(confirm("Add this publication to library?")){
        m_changed = true;
        cout<<"Publication added"<<endl;
    }
}
void LibApp::removePublication(){
    cout<<"Removing publication from library"<<endl;
    search();
    if(confirm("Remove this publication from the library?")){
        m_changed = true;
        cout<<"Publication removed"<<endl;
    }
}
void LibApp::checkOutPub(){
    search();
    if(confirm("Check out publication?")){
        m_changed = true;
        cout<<"Publication checked out"<<endl;
    }
}
LibApp::LibApp(){
    m_mainMenu << "Add New Publication" << "Remove Publication" 
        << "Checkout publication from library" <<"Return publication to library";
    m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
    load();
}
void LibApp::run(){
    while(1){  
        int option =  m_mainMenu.run();
        if(option == 1){
            newPublication();
        }else if(option == 2) {
            removePublication();
        }else if(option == 3){
            checkOutPub();
        }else if(option == 4){
            returnPub();
        }else if(option == 0){
            if(m_changed){
                int choices = m_exitMenu.run();
            if(choices == 1){
                save();
                break;
            }else if(choices == 2){
                ;
            }else if(choices == 0){  
                if(confirm("This will discard all the changes are you sure?"))
                    break;
                }
            }
        else break;
        }
        cout<<endl;
        }
    cout<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Thanks for using Seneca Library Application"<<endl;
}
}