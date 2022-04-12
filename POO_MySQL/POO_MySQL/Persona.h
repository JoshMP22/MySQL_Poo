#include <iostream>
using namespace std;

class Persona{

protected: string nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono=0;

protected:
	Persona(){}

	Persona(string nom, string ap, string dir, int tel, string fn) {
		nombres = nom;
		apellidos = ap;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;

	}
};

