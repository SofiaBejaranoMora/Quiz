#pragma once
#include <iostream>
#include "FileManager.h"
#include "GeneralList.h"
#include "Student.h"
#include "Course.h"

using namespace std;

class ListManage
{
private:
	GeneralList<Course>* listCourse;
	GeneralList<Student>* listStudent;
	FileManager* fileManager;
	const string NAMEARCHIVE = "data";

public:
	ListManage();
	void createStudentList();
	void showStudentList();
	void showCourseList();
	void showBetterStudentList();
	void distributeStudenCourses();
	void studentAverage();
	void searchStudent(string nameStudent, Student* student);
	GeneralList<Student>* betterGrades();
	GeneralList<Student>* searchStudentsCourse(GeneralList<Student>* listStudent, string nameCourse);
	string getNAMEARCHIVE();
	GeneralList<Student>* getListStudent();

};

