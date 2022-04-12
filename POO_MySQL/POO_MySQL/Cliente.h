
#include "Persona.h"
#include "ConeccionBD.h"
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class Cliente : Persona{

private: string nit;

	   //constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ap, string dir, int tel, string fn, string n) : Persona(nom, ap, dir, tel, fn) {
		nit = n;
	}
	//metodos
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ap) { nombres = ap; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_nac(string fn) { fecha_nacimiento = fn; }

	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_nac() { return fecha_nacimiento; }

	void crear() {
		int q_estado;
		ConeccionBD cn = ConeccionBD();
		cn.abrir_coneccion();

		if (cn.getConectar()) {
			string t= to_string(telefono);
			string insert = "INSERT INTO clientes(Nit,Nombre,Apellido,Direccion,Telefono,Fecha_Nacimiento)VALUES('"+nit+"','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		}


	//metodo mos
	void leer() {
		int q_estado;

		ConeccionBD cn = ConeccionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "--------------- CLIENTES -----------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {

					cout << "  " << fila[0] << " --> " << fila[1] << " " << fila[2] << " " << fila[3] << " " << fila[4] << " " << fila[5] << " " << fila[6] << endl;


				}
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}

		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cout << endl;
		cn.cerrar_coneccin();
	}

};
