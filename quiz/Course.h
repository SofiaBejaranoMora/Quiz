#pragma once
#include<iostream>
#include "Student.h"
#include "GeneralList.h"

using namespace std;

class Course
{
private:
	string name;
	GeneralList<Student>* listStudient;
public:
	Course();
	Course(string name);
	void setListStudient(GeneralList<Student>* ListStudient);
	void setName(string name);
	void toString();
	string getName();
	GeneralList<Student>* getListStudient();
};

