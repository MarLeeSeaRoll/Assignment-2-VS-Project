#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
using namespace std;

class Student 
{
private:
	string id;
	double courseworkMarks;
	double finalExamMarks;
	double totalMarks;

public:
	Student() 
	{
		this->id = "";
		this->courseworkMarks = 0;
		this->finalExamMarks = 0;
		this->totalMarks = 0;
	}

	void setAllData(string id, double coursework, double finalExam) 
	{
		this->id = id;
		this->courseworkMarks = coursework;
		this->finalExamMarks = finalExam;
		this->totalMarks = courseworkMarks + finalExamMarks;
	}

	string getId() const
	{
		return id;
	}
	double getCourseWorkMarks() {
		return courseworkMarks;
	}
	double getFinalExamMarks() {
		return finalExamMarks;
	}

	double getTotalMarks() const 
	{
		return totalMarks;
	}

	string getGrade() const {
		if (totalMarks >= 85)
		{
			return "A+ ";
		}
		else if (totalMarks >= 78)
		{
			return "A";
		}
		else if (totalMarks >= 71)
		{
			return "B+";
		}
		else if (totalMarks >= 64)
		{
			return "B";
		}
		else if (totalMarks >= 57)
		{
			return "C+";
		}
		else if (totalMarks >= 50)
		{
			return "C";
		}
		else if (totalMarks >= 40) 
		{
			return "D";
		}
		else
			return "E";
	}

	void updateMarks(double coursework, double finalExam) 
	{
		courseworkMarks = coursework;
		finalExamMarks = finalExam;
		totalMarks = courseworkMarks + finalExamMarks;
	}

	void print() const
	{
		cout << left << setw(10) << id
			<< setw(10) << courseworkMarks
			<< setw(10) << finalExamMarks
			<< setw(10) << totalMarks
			<< setw(5) << getGrade() << endl;
	}
};

#endif
