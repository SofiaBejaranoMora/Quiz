#pragma once
#include<iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <cstring>
#include "GeneralList.h"
#include "Student.h"

using namespace std;

class FileManager
{
private:
	const string NAME = "data.cvs";
public:
	FileManager();
	GeneralList<Student>* uploadFileInformation(string path);
	string loadFileNames(string path);
	string loadFileCollection(string name);
	void saveEverythingFile(string path);

	void imprimir(string path);
};

