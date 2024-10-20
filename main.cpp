#include <iostream>
#include "LinkedList.h"
#include "Student.h"
#include "Utilities.h"
#include "Messages.h"

using namespace std;

int main()
{
	LinkedList<Student> studentList;

	printWelcomeMessage();

	int choice;
	bool continueExecuting = true;

	programStartQuit(continueExecuting);

	// Read student data from file
	readFileAndStoreData(studentList, "studentData.txt");

	while (continueExecuting)
	{
		displayMenu();
		choice = ValidateUpdateMarks<int>(1, 3);

		//Body of Main menu
		switch (choice) 
		{
		case 1:
			printAll(studentList);
			break;

		case 2: 
			{
			string id;
			double coursework=0.0, finalExam=0.0;

			cout << "Enter student ID to update: ";
			cin >> id;

			Student* student =findById(studentList,id);
			if (student)
			{
				updateMarkMenu();
				int updateChoice;
				updateChoice = ValidateUpdateMarks<int>(1, 3);

				switch (updateChoice) {
				case 1:
					cout << "Enter new coursework marks (0 - 50): ";
					coursework = ValidateUpdateMarks<double>(0.0, 50.0);
					break;

				case 2:
					cout << "Enter new final exam marks (0 - 50): ";
					finalExam = ValidateUpdateMarks<double>(0.0, 50.0);
					break;

				case 3:
					cout << "Enter new coursework marks (0 - 50): ";
					coursework = ValidateUpdateMarks<double>(0.0, 50.0);

					cout << "Enter new final exam marks (0 - 50): ";
					finalExam = ValidateUpdateMarks<double>(0.0, 50.0);
					break;
				}

				student->updateMarks(coursework, finalExam);
				cout << "Marks updated!\n";
				printAll(studentList);
			}
			else
			{
				cout << "Student not found.\n";
			}
			break;
		}

		case 3: {
			cout << "Exiting program.\n";
			endProgram(continueExecuting);
		}
		}
	}

	return 0;
}