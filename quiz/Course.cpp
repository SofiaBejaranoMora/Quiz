#include "Course.h"

Course::Course()
{
	ListStudient = new GeneralList<Student>;
}

Course::Course(string name)
{
	ListStudient = new GeneralList<Student>;
	this->name = name;
}

void Course::setListStudient(GeneralList<Student>* ListStudient)
{
	this->ListStudient = ListStudient;
}
