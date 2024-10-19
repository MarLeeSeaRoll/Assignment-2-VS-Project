#ifndef UTILITIES_H
#define UTILITIES_H

#include <fstream>
#include <string>
#include <iomanip>
#include "LinkedList.h"
#include "Student.h"

// Function Prototypes
void programStartQuit(bool& continueExecuting);

void readFileAndStoreData(LinkedList<Student>& studentList, const string& filename);

template <typename V>
V ValidateUpdateMarks(V lowerLimit, V upperLimit);


// Function Definitions

void programStartQuit(bool &continueExecuting)
{
	string userDecision;
	cout << "Enter S to start or Q to quit" << endl;
	cin >> userDecision;

	while (userDecision != "S" && userDecision != "s" && userDecision != "Q" && userDecision != "q")
	{
		cin.clear();
		cout << "ERROR! Invalid input detected." << endl;
		cout << "Please enter either \"S\" or \"Q\" only." << endl;
		cin >> userDecision;
	}

	if (userDecision == "S" || userDecision == "s")
	{
		continueExecuting = true;
	}
	else if (userDecision == "Q" || userDecision == "q")
	{
		continueExecuting = false;
	}
}

void readFileAndStoreData(LinkedList<Student>& studentList, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File failed to load! Please check if file exists" << endl;
        return;
    }
    double coursework, finalExam;
    string id;
    string line;
    getline(file, line);
    while (file >> id >> coursework >> finalExam) {
        Student student(id, coursework, finalExam);
        studentList.insert(student);
    }
    file.close();
}


// Generic input validation function
template <typename V>
V ValidateUpdateMarks(V lowerLimit, V upperLimit)
{
    V input;
    cin >> input;

    while(input < lowerLimit || input > upperLimit || cin.fail())
    {
        if (cin.fail())
        {
            cin.clear();
            string dummy;
            getline(cin,dummy);
            cout << "ERROR! Invalid option detected." << endl;
            cout << "Please enter a number." << endl;
        }
        else if (input < lowerLimit || input > upperLimit)
        {
            cin.clear();
            cout << "ERROR! Your choice is not in range." << endl;
            cout << "Please enter a number between " << lowerLimit << " and " << upperLimit << endl;
        }
        cin >> input;
    }
    return input;
}

#endif
