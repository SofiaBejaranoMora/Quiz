#include "ListManage.h"

ListManage::ListManage()
{
	listCourse = new GeneralList<Course>;
	listStudent = new GeneralList<Student>;
	fileManager = new FileManager;
}

void ListManage::createStudentList()
{
	fileManager->saveEverythingFile(NAMEARCHIVE);
	listStudent = fileManager->uploadFileInformation(NAMEARCHIVE);
}

void ListManage::showStudentList()
{
	listStudent->printList();
}

void ListManage::showCourseList()
{
	DoubleNode<Course>* currentNode = listCourse->getHead();
	while (currentNode) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << currentNode->getData()->getName() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		currentNode->getData()->getListStudient()->printList();
		cout << endl;
		currentNode = currentNode->getNext();
	}
	cout << endl;
}

void ListManage::showBetterStudentList()
{

	betterGrades()->printList();
}

void ListManage::studentAverage()
{
	GeneralList<Student>* auxListStudent = listStudent->cloneList();
	DoubleNode<Student>* currentNodeStudent = listStudent->getHead();
	while (currentNodeStudent) {
		Student* student;
		student = currentNodeStudent->getData()->clone();
		currentNodeStudent = currentNodeStudent->getNext();
		searchStudent(student->getName(), student);
		student->calculateGrade();
		auxListStudent->insertEnd(student);
	}
	listStudent = auxListStudent;
}

void ListManage::searchStudent(string nameStudent, Student* student)
{
	Student* searchedStudent;
	DoubleNode<Student>* currentNodeStudent = listStudent->getHead();
	int pointObtained = 0;
	int totalPoints = 0;
	string courseName = "";
	while (currentNodeStudent->getNext()) {
		if (nameStudent == currentNodeStudent->getData()->getName()) {
			currentNodeStudent = currentNodeStudent->getNext();
			searchedStudent = listStudent->getNodeData(currentNodeStudent->getPrevious()->getData())->getData();
			pointObtained += searchedStudent->getPointsObtained();
			totalPoints += searchedStudent->getTotalPoints();
			courseName += searchedStudent->getCourse()+",";
		}
		else {
			currentNodeStudent = currentNodeStudent->getNext();
		}
	}
	if (nameStudent == currentNodeStudent->getData()->getCourse()) {
		currentNodeStudent = currentNodeStudent->getNext();
		searchedStudent = listStudent->getNodeData(currentNodeStudent->getPrevious()->getData())->getData();
		pointObtained += searchedStudent->getPointsObtained();
		totalPoints += searchedStudent->getTotalPoints();
		courseName += searchedStudent->getCourse() + ",";
	}
	student->setPointsObtained(pointObtained);
	student->setTotalPoints(totalPoints);
	student->setCourse(courseName);
	student->setNameNote("Ponderado: ");
}

GeneralList<Student>* ListManage::betterGrades()
{
	GeneralList<Student>* betterGradesList = new GeneralList<Student>;
	DoubleNode<Student>* auxNode;
	DoubleNode<Student>* currentNodeStudent;

	for (int i = 0;i < 15;i++) {
		auxNode = listStudent->getHead();
		currentNodeStudent = listStudent->getHead();
		while (currentNodeStudent) {
			if (currentNodeStudent->getData()->getGrade() > auxNode->getData()->getGrade()) {
				auxNode = currentNodeStudent;
			}
			currentNodeStudent = currentNodeStudent->getNext();
		}
		betterGradesList->insertEnd(auxNode->getData()->clone());
		listStudent->deleteData(auxNode->getData());
	}


	return betterGradesList;
}

void ListManage::distributeStudenCourses()
{
	GeneralList<Student>* auxListStudent = listStudent->cloneList();
	Course* course;
	DoubleNode<Student>* currentNodeStudent= auxListStudent->getHead();
	while (currentNodeStudent) {
		course = new Course;
		currentNodeStudent = currentNodeStudent->getNext();
		course->setName(auxListStudent->getHead()->getData()->getCourse());
		course->setListStudient(searchStudentsCourse(auxListStudent, course->getName()));
		listCourse->insertEnd(course);
	}

}

GeneralList<Student>* ListManage::searchStudentsCourse(GeneralList<Student>* listStudent, string nameCourse)
{
	GeneralList<Student>* courseStudentList = new GeneralList<Student>;

	DoubleNode<Student>* currentNodeStudent = listStudent->getHead();
	while (currentNodeStudent->getNext()) {
		if (nameCourse == currentNodeStudent->getData()->getCourse()) {
			currentNodeStudent = currentNodeStudent->getNext();
			courseStudentList->insertEnd((listStudent->getNodeData(currentNodeStudent->getPrevious()->getData()))->getData());
		}
		else {
			currentNodeStudent = currentNodeStudent->getNext();
		}
	}
	if (nameCourse == currentNodeStudent->getData()->getCourse()) {
		courseStudentList->insertEnd((listStudent->getNodeData(currentNodeStudent->getData()))->getData());
	}
	return courseStudentList;
}

string ListManage::getNAMEARCHIVE()
{
	return NAMEARCHIVE;
}

GeneralList<Student>* ListManage::getListStudent()
{
	return listStudent;
}
