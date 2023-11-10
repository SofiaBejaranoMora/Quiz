#pragma once
#include<iostream>
#include "Student.h"
#include "GeneralList.h"

using namespace std;

class Course
{
private:
	string name;
	GeneralList<Student>* ListStudient;
public:
	Course();
	Course(string name);
	void setListStudient(GeneralList<Student>* ListStudient);
};

