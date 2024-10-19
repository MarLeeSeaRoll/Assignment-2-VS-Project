#ifndef MESSAGES_H
#define MESSAGES_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void printWelcomeMessage()
{
    cout << "+-------------------------------------------------+\n";
    cout << "|      WELCOME TO THE STUDENT GRADES PROGRAM      |\n";
    cout << "+-------------------------------------------------+\n";
}

void displayMenu(){
        cout << "\nMenu:\n";
        cout << "1. Print Student Details\n";
        cout << "2. Update Student Marks\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
}

void endProgram(bool& continueExecuting)
{
    continueExecuting = false;

    cout << endl;
    cout << "+-------------------------------------+\n";
    cout << "|  Thank you for using this program!  |\n";
    cout << "+-------------------------------------+\n";
}

void updateMarkMenu(){
    cout << "Which Mark Would You Like To Update?" << endl;
    cout << "1. Coursework Only" << endl;
    cout << "2. Final Exam Only" << endl;
    cout << "3. Course and Final Exam" << endl;	
}
	
#endif
