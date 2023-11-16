#include <iostream>
#include "ManegerFile.h"
#include "List.h"

int main()
{
    ManegerFile file;
    List list;
    int opcion=0;
    int numero=0;
    while (opcion != 5) {
        cout << "numero"<<endl;
        cin >> numero;
        list.insertOrdered(numero);
        cout << "5.salir" << endl;
        cin >> opcion;
    }
    list.print();

    file.save(list);

    
}
