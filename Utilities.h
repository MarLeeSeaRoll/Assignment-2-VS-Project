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

void printAll(const LinkedList<Student>& studentList);

Student* findById(const LinkedList<Student>& studentList, const string& id);

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

// Print all student data
void printAll(const LinkedList<Student>& studentList) {
	Node<Student>* temp = studentList.getHead();
	cout << "ID        CW Marks   FE Marks   Total      Grade\n";
	cout << "----------------------------------------------\n";

	double totalMarks = 0.0;
	double count = 0;
	double passCount = 0;
	double convertToPercentage = 100.0;
	Node<Student>* topStudent = NULL;

	while (temp) {
		temp->data.print();
		totalMarks += temp->data.getTotalMarks();
		count++;
		if (temp->data.getGrade() != "D" && temp->data.getGrade() != "E") {
			passCount++;
		}

		if (!topStudent || temp->data.getTotalMarks() > topStudent->data.getTotalMarks()) {
			topStudent = temp;
		}

		temp = temp->next;
	}
	double averageMarks = totalMarks / count;
	double passRate = passCount / count * convertToPercentage;
	cout << "\nAverage Marks: " << fixed << setprecision(2) << averageMarks << endl;
	cout << "Pass Rate: " << fixed << setprecision(2) << passRate << "%" << endl;
	cout << "\nHighest Scorer:\n";
	cout << "ID        CW Marks   FE Marks   Total      Grade\n";
	cout << "----------------------------------------------\n";
	topStudent->data.print();
	cout << endl;
}

// Find a student by ID
Student* findById(const LinkedList<Student>& studentList, const string & id) {
	Node<Student>* temp = studentList.getHead();
	while (temp) {
		if (temp->data.getId() == id) {
			return &(temp->data);
		}
		temp = temp->next;
	}
	return NULL;
}

#endif
