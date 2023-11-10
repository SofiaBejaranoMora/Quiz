#pragma once
#include <iostream>
#include "FileManager.h"
#include "GeneralList.h"
#include "Student.h"
#include "Course.h"

class ListManage
{
private:
	GeneralList<Course>* ListCourse;
	GeneralList<Student>* ListStudient;
	FileManager* fileManager;
	const string NAMEARCHIVE = "data";

public:
	ListManage();
	void createStudentList();
	void showStudentList();
	void distributeStudenCourses();
	string getNAMEARCHIVE();
};

