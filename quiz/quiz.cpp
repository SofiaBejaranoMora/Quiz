#include <iostream>
#include "ListManage.h"

int main()
{
	ListManage listManage;
	int option = 0;
	listManage.createStudentList();
	listManage.distributeStudenCourses();
	GeneralList<Student>* listStudent = listManage.getListStudent()->cloneList();
	listManage.studentAverage();

	while (option != 5) {
		system("cls");
		cout << "----INGRESE LA OPCION DESEADA----" << endl;
		cout << "1.Ver la lista de estudiante" << endl;
		cout << "2.Ver lista de cursos con sus estudiantes" << endl;
		cout << "3.Ver las 15 mejores notas" << endl;
		cout << "5.Salir" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			try {
				listStudent->printList();
				listManage.showStudentList();
			}
			catch (int exceptionId) {
				if (exceptionId == 1) {
					cout << "No se pudo abrir el directorio" << listManage.getNAMEARCHIVE() << endl;
				}
			}
			break;
		case 2:
			listManage.showCourseList();
		case 3:
			listManage.showBetterStudentList();
		default:
			break;
		}
		system("pause");
	}
}