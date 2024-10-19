#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* next;

	Node(T data) {
		this->data = data;
		next = NULL;
	}

	~Node() {}
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;

public:
	LinkedList() {
		head = NULL;
	}

	// Insert a new node at the end of the linked list
	void insert(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (!head) {
			head = newNode;
		}
		else {
			Node<T>* temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	// Accessor method to get the head of the linked list
	Node<T>* getHead() const {
		return head;
	}

	// Find a student by ID
	T* findById(string id) {
		Node<T>* temp = head;
		while (temp) {
			if (temp->data.getId() == id) {
				return &(temp->data);
			}
			temp = temp->next;
		}
		return NULL;
	}

	// Print all student data
	void printAll() const {
		Node<T>* temp = head;
		cout << "ID        CW Marks   FE Marks   Total      Grade\n";
		cout << "----------------------------------------------\n";

		double totalMarks = 0.0;
		double count = 0;
		double passCount = 0;
		double convertToPercentage = 100.0;
		Node<T>* topStudent = NULL;

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

// Destructor to clean up memory
~LinkedList() {
	Node<T>* temp = head;
	while (temp) {
		Node<T>* next = temp->next;
		delete temp;
		temp = next;
	}
}
};

#endif
