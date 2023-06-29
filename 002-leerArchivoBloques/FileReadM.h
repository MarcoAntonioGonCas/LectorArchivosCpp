#pragma once
#include <iostream>
#include <string>
using namespace std;

class FileReadM
{
private:
	typedef unsigned char byte;
	char* buffer = new char[bloque];
	byte* bufferBytes = new byte[bloque];
	//streambuf bu(1000);

public:

	//1MB = 1048576 Bytes

	const long bloque = 1048576;

	inline FileReadM() {
		cout << "Clase creada" << endl;
	}
	void fixBytes(long numBytes);
	void mostrarBoque(long numBytes);
	void leer(string ruta = "D:\\Nueva carpeta\\a.txt");
	static int64_t obtieneLongitud(fstream*);
};

