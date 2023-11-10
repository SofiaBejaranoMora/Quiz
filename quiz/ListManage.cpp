#include "ListManage.h"

ListManage::ListManage()
{
	ListCourse = new GeneralList<Course>;
	ListStudient = new GeneralList<Student>;
	fileManager = new FileManager;
}

void ListManage::createStudentList()
{
	fileManager->saveEverythingFile(NAMEARCHIVE);
	ListStudient = fileManager->uploadFileInformation(NAMEARCHIVE);
}

void ListManage::showStudentList()
{
	ListStudient->printList();
}

void ListManage::distributeStudenCourses()
{
	GeneralList<Student>* auxListStudient = ListStudient;

}

string ListManage::getNAMEARCHIVE()
{
	return NAMEARCHIVE;
}
