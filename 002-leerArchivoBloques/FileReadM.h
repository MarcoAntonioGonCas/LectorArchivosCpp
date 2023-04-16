#pragma once
#include <iostream>
#include <string>
using namespace std;

class FileReadM
{
private:
	typedef  char byte;
	//1MB = 1048576 Bytes
	const long bloque = 1048576;
	byte* buffer = new byte[bloque];
	//streambuf bu(1000);

public:

	inline FileReadM() {
		cout << "Clase creada" << endl;
	}
	void mostrarBoque(long numBytes);
	void leer(string ruta);
	static int64_t obtieneLongitud(fstream*);
};

