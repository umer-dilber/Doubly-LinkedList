#pragma once
#include <iostream>
using namespace std;

template<class T>
class DNode
{
public:
	T info;
	DNode<T>* next;
	DNode<T>* prev;
	// default constructor
	DNode() {
		next = nullptr;
		prev = nullptr;
	}

	// parametrized constructor
	DNode(T val) {
		info = val;
		next = nullptr;
		prev = nullptr;
	}

	// function to print node' info
	void printValue() {
		cout << info << endl;
	}
};

template<class T>
class DList
{
	DNode<T>* head;
	DNode<T>* tail;
	// Public member functions…
public:
	DList();
	void setHead(DNode<T>* head);
	void setTail(DNode<T>* Tail);
	DNode<T>* getHead();
	DNode<T>* getTail();
	void insertAtHead(T value);
	void insertAtTail(T value);
	bool deleteAtHead();
	bool deleteAtTail();
	void printList();
	void printReverse();
	//This function should return pointer to nth node in the list.Returns last node if n is greater than the number of nodes present in the list.
	DNode<T>* getNode(int n);

	//Search a node with value “key” from listand return its link.If multiple nodes of same value exist, then return pointer to first node having the key value.
	DNode<T>* search(T key);
	
	//Insert a node after some node whose info equals input parameter valueand returns true if node is successfully inserted, false otherwise.
	bool insertAfter(T value, T key);
	
	//Delete a node that is after some node whose info equals input parameter value and returns true if node is successfully inserted, false otherwise.Check boundary cases i.e if node to be deleted is last node or first node in the list.
	bool deleteAfter(T value);
	
	//Returns the total number of nodes in the list.
	int getLength();

	~DList();
};