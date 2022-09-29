#include "DList.h"
#include <iostream>
using namespace std;

template <class T>
DList<T>::DList() {
	head = nullptr;
	tail = nullptr;
}

template <class T>
void DList<T>::setHead(DNode<T>* Head) {
	if (head == nullptr) {
		head = tail = Head;
	}
	else {
		DNode<T>* temp = head;
		head = Head;
		temp->prev = head;
		head->next = temp;
	}
}

template <class T>
void DList<T>::setTail(DNode<T>* Tail) {
	if (head == nullptr) {
		head = tail = Tail;
	}
	else {
		DNode<T>* temp = tail;
		tail = Tail;
		temp->next = tail;
		tail->prev = temp;
	}
}

template <class T>
DNode<T>* DList<T>::getHead() {
	return head;
}

template <class T>
DNode<T>* DList<T>::getTail() {
	return tail;
}

template <class T>
void DList<T>::insertAtHead(T value) {
	DNode<T>* node = new DNode<T>(value);
	if (head == nullptr) {
		head = tail = node;
	}
	else {
		DNode<T>* temp = head;
		head = node;
		temp->prev = head;
		head->next = temp;
	}
}

template <class T>
void DList<T>::insertAtTail(T value) {
	DNode<T>* node = new DNode<T>(value);
	if (head == nullptr) {
		head = tail = node;
	}
	else {
		DNode<T>* temp = tail;
		tail = node;
		temp->next = tail;
		tail->prev = temp;
	}
}

template <class T>
bool DList<T>::deleteAtHead() {
	if (head != nullptr) {
		DNode<T>* temp = head->next;
		delete head;
		temp->prev = nullptr;
		head = temp;
		return true;
	}
	return false;
}

template <class T>
bool DList<T>::deleteAtTail() {
	if (head != nullptr) {
		DNode<T>* temp = tail->prev;
		delete tail;
		temp->next = nullptr;
		tail = temp;
		return true;
	}
	return false;
}

template <class T>
void DList<T>::printList() {
	DNode<T>* temp = head;
	while (temp != nullptr) {
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << endl;
	delete temp;
}

template <class T>
void DList<T>::printReverse() {
	DNode<T>* temp = tail;
	while (temp != nullptr) {
		cout << temp->info << " ";
		temp = temp->prev;
	}
	cout << endl;
	delete temp;
}

template <class T>
DNode<T>* DList<T>::getNode(int n) {
	int count = 0;
	DNode<T>* temp = head;
	while (temp != nullptr) {
		if (n -1 == count) {
			return temp;
		}
		temp = temp->next;
		count++;
	}
	delete temp;
	return tail;
}

template <class T>
DNode<T>* DList<T>::search(T key) {
	DNode<T>* temp = head;
	while (temp != nullptr) {
		if (temp->info == key) {
			return temp;
		}
		temp = temp->next;
	}
	delete temp;
}

template <class T>
bool DList<T>::insertAfter(T value, T key) {
	DNode<T>* temp = head;
	// creating node which is to be inserted
	DNode<T>* node = new DNode<T>(value);
	while (temp != nullptr) {
		if (temp->info == key) {
			node->next = temp->next;
			node->prev = temp;
			temp->next->prev = node;
			temp->next = node;
			return true;
		}
		temp = temp->next;
	}
	delete temp;
	return false;
}

template <class T>
bool DList<T>::deleteAfter(T value) {
	DNode<T>* temp = head;
	while (temp != nullptr) {
		if (temp->info == value) {
			if (temp == tail) {
				return deleteAtTail();
			}
			else if (temp == head) {
				return deleteAtHead();
			}
			else {
				DNode<T>* nodeToDelete = temp->next;
				temp->next = nodeToDelete->next;
				nodeToDelete->next->prev = temp;
				delete nodeToDelete;
				return true;
			}
		}
		temp = temp->next;
	}
	delete temp;
	return false;
}

template <class T>
int DList<T>::getLength() {
	DNode<T>* temp = head;
	int count = 0;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	delete temp;
	return count;
}

template <class T>
DList<T>::~DList() {
	while (head != nullptr) {
		DNode<T>* temp = head;
		head = temp->next;
		temp = nullptr;
		delete temp;
	}
	delete head;
	delete tail;
}

int main() {
	DList<int> lis;
	DNode<int>* n = new DNode<int>(23);
	DNode<int>* n2 = new DNode<int>(11);
	lis.setHead(n);
	lis.setTail(n2);
	lis.insertAtTail(21);
	lis.insertAtHead(9);
	lis.search(21)->printValue();
	lis.insertAfter(50, 23);
	lis.deleteAfter(9);
	lis.printList();
	lis.printReverse();
	cout << lis.getLength() << endl;
	lis.getNode(1)->printValue();
	lis.getNode(lis.getLength())->printValue();
	return 0;
}