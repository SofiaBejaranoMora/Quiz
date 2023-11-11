#pragma once
#include<iostream>
#include <iomanip>

using namespace std;

class Student
{
private:
	string headquarters;
	string id;
	string name;
	string surname;
	string course;
	float grade;
	string status;
	float pointsObtained;
	float totalPoints;
	string nameNote;
public:
	Student();
	Student(string headquarters, string id, string name, string surname, string course, float grade, string status, float pointsObtained, float totalPoints);
	
	Student* clone();
	void calculateGrade();
	void toString();
	
	void setHeadquarters(string headquarters);
	void setId(string id);
	void setName(string name);
	void setSurname(string surname);
	void setCourse(string course);
	void setGrade(float grade);
	void setStatus(string status);
	void setPointsObtained(float pointsObtained);
	void setTotalPoints(float totalPoints);
	void setNameNote(string nameNote);
	string getHeadquarters();
	string getId();
	string getName();
	string getSurname();
	string getCourse();
	float getGrade();
	string getStatus();
	int getPointsObtained();
	int getTotalPoints();
};

