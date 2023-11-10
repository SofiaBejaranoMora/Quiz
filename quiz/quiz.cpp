#include <iostream>
#include "ListManage.h"


int main()
{
	ListManage listManage;

	int option = 0;
	listManage.createStudentList();

	while (option != 5) {

		cout << "----INGRESE LA OPCION DESEADA----" << endl;
		cout << "1.Ver la lista de estudiante" << endl;
		cout << "5.Salir" << endl;
		cin >> option;
		system("cls");
		switch (option)
		{
		case 1:
			try {
				  listManage.showStudentList();
			}
			catch (int exceptionId) {
				if (exceptionId == 1) {
					cout << "No se pudo abrir el directorio" << listManage.getNAMEARCHIVE()<<endl;
				}
			}
		default:
			break;
		}
		system("pause");
	}
}