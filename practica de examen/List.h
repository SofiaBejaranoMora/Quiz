#pragma once
#include<iostream>
#include "Node.h"

using namespace std;

class List
{
private:
	Node* head;
public:
	List();
	Node* getHead();
	void insertOrdered(int data);
	void print();
};

