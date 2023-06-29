#include "FileReadM.h"
#include <fstream>
#include <math.h>

//Convierte el buffer char con signo a buffer char sin signo
void FileReadM::fixBytes(long numBytes)
{
	for (long i = 0; i < numBytes;i++) {
		
		this->bufferBytes[i] = static_cast<unsigned char>(buffer[i]);
	}

}

//Muestra un bloque de bytes
void FileReadM::mostrarBoque(long numBytes)
{
	
	for (long i = 0; i < numBytes;i++) {
		cout << (int)this->bufferBytes[i];
		if (i != (numBytes - 1))
		{
			cout << " , ";
		}
	}
}


//Lee un archivo en bloques
void FileReadM::leer(string ruta) {

	cout << ruta<<endl;

	fstream archivo(ruta.c_str(), ios_base::in | ios_base::binary);
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo"<< endl;
		return;
	}



	int64_t tamanioArchivo = obtieneLongitud(&archivo);
	int64_t vueltas = static_cast<long long>( ceill(tamanioArchivo / (long double)this->bloque));


	int64_t restante = tamanioArchivo % this->bloque;
	int64_t lecturaBytes = this->bloque;

	for (int i = 0;i < vueltas;i++) {
		
		if (restante != 0 and i+1 == vueltas) {
			lecturaBytes = restante;
		}

		cout << lecturaBytes << "**" << endl;

		archivo.read(buffer, lecturaBytes);

		fixBytes(lecturaBytes);
		mostrarBoque(lecturaBytes);
	}
	archivo.close();
}


/// <summary>
/// Obtiene el tamaño del archivo en bytes
/// </summary>
/// <param name="archivo">Archivo a calcular la longitud</param>
/// <returns></returns>
int64_t FileReadM::obtieneLongitud(fstream* archivo)
{
	if (archivo == nullptr) {
		throw new invalid_argument("archivo es nulo");
	}

	
	streampos posAux = archivo->tellp();

	archivo->seekp(0, ios::end);



	streampos tamanio = archivo->tellp();

	archivo->seekp(posAux);

	return static_cast<int64_t>(tamanio);

}
