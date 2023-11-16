#include "ManegerFile.h"

ManegerFile::ManegerFile()
{
}

void ManegerFile::save(List list)
{
	ofstream file (NAME);

	if (!file.is_open()) {
		cout << "no se pudo abrir el archivo" << endl;
	}
	if (file.is_open()) {
		Node* current = list.getHead();
		while (current) {
			file << serializar(list);
		}
	}
	file.close();
}

string ManegerFile::serializar(List list)
{
	string text = " ";
	int num = 0;
	Node* current = list.getHead();
	while (current) {
		text += to_string (current->getData()) + ";";
		current = current->getNext();
	}
	return text;
}

List ManegerFile::load()
{
	return List();
}
