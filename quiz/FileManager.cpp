#include "FileManager.h"

FileManager::FileManager()
{
}

GeneralList<Student>*FileManager::uploadFileInformation(string path)
{
    GeneralList<Student>* listStudent =new GeneralList<Student>;
    string auxiliary = "";
    Student* student;
    saveEverythingFile(path);

    ifstream file;
    file.open(NAME);
    int pos;
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            pos = line.find(";");
            line = line.substr(pos + 1, line.size() - pos - 1);

            student = new Student;
            pos = line.find(",");
            auxiliary = line.substr(0, pos);
            line = line.substr(pos + 1, line.size() - pos - 1);
            student->setHeadquarters(auxiliary);

            pos = line.find(",");
            auxiliary = line.substr(0, pos);
            line = line.substr(pos + 1, line.size() - pos - 1);
            student->setId(auxiliary);

            pos = line.find(",");
            auxiliary = line.substr(0, pos);
            line = line.substr(pos + 1, line.size() - pos - 1);
            student->setName(auxiliary);

            pos = line.find(",");
            auxiliary = line.substr(0, pos);
            line = line.substr(pos + 1, line.size() - pos - 1);
            student->setSurname(auxiliary);

            pos = line.find(",");
            auxiliary = line.substr(0, pos);
            line = line.substr(pos + 1, line.size() - pos - 1);
            student->setCourse(auxiliary);

            pos = line.find(",");
            auxiliary = line.substr(0, pos);
            line = line.substr(pos + 1, line.size() - pos - 1);
            student->setGrade(stoi(auxiliary));

            pos = line.find(",");
            auxiliary = line.substr(0, pos);
            line = line.substr(pos + 1, line.size() - pos - 1);
            student->setStatus(auxiliary);

            pos = line.find(",");
            auxiliary = line.substr(0, pos);
            line = line.substr(pos + 1, line.size() - pos - 1);
            student->setPointsObtained(stoi(auxiliary));

            auxiliary = line.substr(0, line.size());
            student->setTotalPoints(stoi(auxiliary));

            student->calculateGrade();
            listStudent->insertEnd(student);
        }
    }

    return listStudent;
}

string FileManager::loadFileNames(string path)
{
    string nameList = " ";
    DIR* dir = opendir(path.c_str());
    if (!dir) {
        throw 1;
    }

    dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                string subdirectoryPath = path + "/" + entry->d_name;
                loadFileNames(subdirectoryPath);
            }
        }
        else {
            string fileName(entry->d_name);
            if (fileName.find(".txt") == string::npos) {
                nameList += path + "/" + entry->d_name + ";" ;
            }
        }
    }
    nameList += "end;";
    closedir(dir);
    return nameList;
}

string FileManager::loadFileCollection(string name)
{
    string fileText;
    ifstream file;
    file.open(name);
    string line;
    while (getline(file,line)) {
        if ((line.find("sede") == string::npos)) {
            fileText += "\n" + line;
        }
    }
    
    return fileText;
}

void FileManager::saveEverythingFile(string path)
{
    string nameList="";
    ofstream file(NAME);
    if (!file.is_open()) {
        throw 2;
    }
    if (file.is_open()) {
        nameList = loadFileNames(path);
        bool hasNameFile = true;
        string nameFile = "";
        int pos;
        while (hasNameFile) {
            pos = nameList.find(";");
            nameFile= nameList.substr(0,pos);
            nameList = nameList.substr(pos+1,nameList.size()-pos-1);
            if (nameFile == "end") {
                hasNameFile = false;
            }
            else {
                file << loadFileCollection(nameFile);
            }
        }
    }
}

void FileManager::imprimir(string path)
{
    saveEverythingFile(path);

    ifstream file;
    file.open(NAME);
    string line = "";

    while (getline(file, line)) {
        cout << line;
    }
}
