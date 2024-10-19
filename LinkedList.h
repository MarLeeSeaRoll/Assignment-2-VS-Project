#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node* next;

	Node(T data)
	{
		this->data = data;
		next = NULL;
	}

	~Node() {}
};

template <typename T>
class LinkedList
{
private:
	Node<T>* head;

public:
	LinkedList()
	{
		head = NULL;
	}

	// Insert a new node at the end of the linked list
	void insert(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (!head)
		{
			head = newNode;
		}
		else 
		{
			Node<T>* temp = head;
			while (temp->next) 
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	// Accessor method to get the head of the linked list
	Node<T>* getHead() const 
	{
		return head;
	}

	// Destructor to clean up memory
	~LinkedList()
	{
		Node<T>* temp = head;
		while (temp) 
		{
			Node<T>* next = temp->next;
			delete temp;
			temp = next;
		}
	}
};

#endif
