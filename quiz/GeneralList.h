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
	GeneralList<T>* cloneList()
	{
		GeneralList<T>* auxListStudent = new GeneralList<T>;
		DoubleNode<T>* currentNode = head;
		while (currentNode) {
			auxListStudent->insertEnd(currentNode->getData()->clone());
			currentNode = currentNode->getNext();
		}
		return auxListStudent;
	}
	void setHead(DoubleNode<T>* head) {
		this->head = head;
	}
	DoubleNode<T>* getNodeData(T* data) {
		DoubleNode<T>* currentNode = head;
		DoubleNode<T>* auxNode;

		while (currentNode->getNext()) {
			if ((currentNode == head) && (currentNode->getData() == data)) {
				DoubleNode<T>* auxNode = currentNode;
				head = currentNode->getNext();
				head->setPrevious(nullptr);
				auxNode->setNext(nullptr);
				return auxNode;
			}
			else if (currentNode->getData() == data) {
				DoubleNode<T>* auxNode = currentNode;
				currentNode->getNext()->setPrevious(currentNode->getPrevious());
				currentNode->getPrevious()->setNext(currentNode->getNext());
				auxNode->setNext(nullptr);
				auxNode->setPrevious(nullptr);
				return auxNode;
			}
			currentNode = currentNode->getNext();
		}
		if (currentNode->getData() == data) {
			if(currentNode !=head){
				currentNode->getPrevious()->setNext(nullptr);
			}
			currentNode->setPrevious(nullptr);
			return currentNode;
		}
	}
	void deleteData(T* data) {
		if (head != nullptr) {
			DoubleNode<T>* currentNode = head;

			while (currentNode) {
				if ((currentNode == head) && (currentNode->getData() == data)) {
					head = currentNode->getNext();
					head->setPrevious(nullptr);
					currentNode->setNext(nullptr);
					delete currentNode;
					break;
				}
				else if (currentNode->getData() == data) {
					currentNode->getNext()->setPrevious(currentNode->getPrevious());
					currentNode->getPrevious()->setNext(currentNode->getNext()) ;
					currentNode->setNext(nullptr);
					currentNode->setPrevious(nullptr);
					delete currentNode;
					break;
				}
				currentNode = currentNode->getNext();
			}
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