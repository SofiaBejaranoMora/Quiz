#include "Course.h"

Course::Course()
{
	name = "";
	listStudient = new GeneralList<Student>;
}

Course::Course(string name)
{
	listStudient = new GeneralList<Student>;
	this->name = name;
}

void Course::setListStudient(GeneralList<Student>* ListStudient)
{
	this->listStudient = ListStudient;
}

void Course::setName(string name)
{
	this->name = name;
}

void Course::toString()
{
	listStudient->printList();
}

string Course::getName()
{
	return name;
}

GeneralList<Student>* Course::getListStudient()
{
	return listStudient;
}
