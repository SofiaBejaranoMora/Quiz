#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

class ManegerFile
{
private:
	const string NAME = "practica.txt";
public:
	ManegerFile();
	void save(List list);
	string serializar(List list);

	List load();
};

