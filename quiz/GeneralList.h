#pragma once
#include<iostream>
#include"DoubleNode.h"

using namespace std;

template <typename T>

class GeneralList
{
private:
	DoubleNode<T>* head;
public:
	GeneralList() {
		head = nullptr;
	}
	GeneralList(DoubleNode<T>* head) {
		this->head = head;
	}
	DoubleNode<T>* getHead() {
		return head;
	}
	void setHead(DoubleNode<T>* head) {
		this->head = head;
	}
	void deleteData(T* data) {

		DoubleNode<T>* currentNode = head;
		DoubleNode<T>* auxNode;

		while (currentNode->getNext) {
			if ((currentNode == head) && (currentNode->getData() == data)) {
				DoubleNode<T>* auxNode = currentNode;
				head = currentNode->getNext();
				head->getPrevious() == nullptr;
				auxNode->getNext() = nullptr;
				delete auxNode;
			}
			else if (currentNode->getData() == data) {
				DoubleNode<T>* auxNode = currentNode;
				currentNode->getNext()->getPrevious() = currentNode->getPrevious();
				currentNode->getPrevious()->getNext() = currentNode->getNext();
				auxNode->getNext() = nullptr;
				auxNode->getPrevious() = nullptr;
				delete auxNode;
			}
			currentNode = currentNode->getNext();
		}
		if (currentNode->getData() == data) {
			delete currentNode;
		}

	}
	void insertEnd(T* data) {

		if (!head) {
			head = new DoubleNode<T>(data);
		}
		else {
			DoubleNode<T>* currentNode = head;
			while (currentNode->getNext())
			{
				currentNode = currentNode->getNext();
			}

			currentNode->setNext(new DoubleNode<T>(data));
			currentNode->getNext()->setPrevious(currentNode);

		}
	}
	void printList() {
		DoubleNode<T>* currentNode = head;
		while (currentNode) {
			currentNode->getData()->toString();
			currentNode = currentNode->getNext();
		}
		cout << endl;
	}
};