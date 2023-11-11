#include "Student.h"

Student::Student()
{
	headquarters = "";
	id = "";
	name = "";
	surname = "";
	course = "";
	grade = 0;
	status ="";
	pointsObtained = 0;
	totalPoints = 0;
	nameNote = "Nota: ";
}

Student::Student(string headquarters, string id, string name, string surname, string course,
	float grade, string status, float pointsObtained, float totalPoints)
{
	this->headquarters = headquarters;
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->course = course;
	this->grade = grade;
	this->status = status;
	this->pointsObtained = pointsObtained;
	this->totalPoints = totalPoints;
	calculateGrade();
}

Student* Student::clone()
{
	Student* clone = new Student;
	clone->setHeadquarters(this->headquarters);
	clone->setId(this->id);
	clone->setName(this->name);
	clone->setSurname(this->surname);
	clone->setCourse(this->course);
	clone->setGrade(this->grade);
	clone->setStatus(this->status);
	clone->setPointsObtained(this->pointsObtained);
	clone->setTotalPoints(this->totalPoints);

	return clone;
}

void Student::calculateGrade()
{
	grade = ((pointsObtained * 100) / totalPoints)/10;
	status = "reviewed";
}

void Student::toString()
{ 
	cout<<"------------------------------------------------------------------------------"<<endl
		<< "Sede: " << headquarters << endl << "Cedula: " << id << endl << "Nombre: " << name << endl
		<< "Apellido: " << surname << endl << "Cursos: " << course << endl<< setprecision(3) << nameNote << grade << endl
		<< "Estado: " << status << endl << "Puntos Obtenidos: " << pointsObtained << endl << "Puntos Totales: " << totalPoints << endl
		<< "------------------------------------------------------------------------------" <<endl;
}

void Student::setHeadquarters(string headquarters)
{
	this->headquarters = headquarters;
}

void Student::setId(string id)
{
	this->id = id;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setSurname(string surname)
{
	this->surname = surname;
}

void Student::setCourse(string course)
{
	this->course= course;
}

void Student::setGrade(float grade)
{
	this->grade = grade;
}

void Student::setStatus(string status)
{
	this->status = status;
}

void Student::setPointsObtained(float pointsObtained)
{
	this->pointsObtained = pointsObtained;
}

void Student::setTotalPoints(float totalPoints)
{
	this->totalPoints = totalPoints;
}

void Student::setNameNote(string nameNote)
{
	this->nameNote = nameNote;
}

string Student::getHeadquarters()
{
	return headquarters;
}

string Student::getId()
{
	return id;
}

string Student::getName()
{
	return  name;
}

string Student::getSurname()
{
	return  surname;
}

string Student::getCourse()
{
	return course;
}

float Student::getGrade()
{
	return grade;
}

string Student::getStatus()
{
	return  status;
}

int Student::getPointsObtained()
{
	return  pointsObtained;
}

int Student::getTotalPoints()
{
	return  totalPoints;
}
