#include "Student.h"

Student::Student()
{
}

Student::Student(string headquarters, string id, string name, string surname, string course, float grade, string status, float pointsObtained, float totalPoints)
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

void Student::calculateGrade()
{
	grade = ((pointsObtained * 100) / totalPoints)/10;
	status = "reviewed";
}

void Student::toString()
{
	cout<<"------------------------------------------------------------------------------"<<endl
		<< "Sede: " << headquarters << endl << "Cedula: " << id << endl << "Nombre: " << name << endl
		<< "Apellido: " << surname << endl << "Curso: " << course << endl << "Nota: " << grade << endl
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
