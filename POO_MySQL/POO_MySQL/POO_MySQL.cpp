#include <iostream>
#include <string>
#include "cliente.h"

using namespace std;

int main()
{
	
	string nit, nombres, apellidos, direccion, fec_nac;
	int telefono;
	cout << "INGRESE NIT: ";
	getline(cin, nit);
	cout << "INGRESE NOMBRES: ";
	getline(cin, nombres);
	cout << "INGRESE APELLIDOS: ";
	getline(cin, apellidos);
	cout << "INGRESE DIRECCION: ";
	getline(cin, direccion);
	cout << "INGRESE TELEFONO: ";
	cin >> telefono;
	cin.ignore();

	cout << "INGRESE FECHA DE NACIMIENTO: ";
	getline(cin, fec_nac);
	
	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fec_nac, nit);
	c.crear();
	c.leer();
		
	system("pause");
	return 0;
}