#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class ConeccionBD {

private: MYSQL* conectar;

public:
	void abrir_coneccion() {

		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "Morataya22", "empresa", 3306, NULL, 0);
	}

	MYSQL* getConectar() {
		return conectar;
	}

	void cerrar_coneccin() {
		mysql_close(conectar);
	}
	
};

