#pragma once
class Node
{
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node() {}
	Node(int data) { this->data = data;}
	void setData(int data) { this->data = data; }
	void setNext(Node* next) { this->next = next; }
	void setPrev(Node* prev) { this->prev = prev; }
	int getData() { return data; }
	Node* getNext() { return next; }
	Node* getPrev() { return prev; }
};

