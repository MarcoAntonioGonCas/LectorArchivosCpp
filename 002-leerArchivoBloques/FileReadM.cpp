#include "FileReadM.h"
#include <fstream>
#include <math.h>
void FileReadM::mostrarBoque(long numBytes)
{
	
	for (long i = 0; i < numBytes;i++) {
		cout << (int)this->buffer[i];
		if (i = numBytes - 1)
		{
			cout << " , ";
		}
	}
}
void FileReadM::leer(string ruta){
	fstream archivo(ruta.c_str(), ios_base::in | ios_base::binary);
	if (!archivo) {
		cout << "Error al abrir el archivo"<< endl;
		return;
	}
	int64_t tamanio = obtieneLongitud(&archivo);

	cout <<"Tamanio en bytes: " <<tamanio << endl;

	int64_t vueltas = (int64_t) ceil(tamanio / (double)this->bloque);
	int64_t restante = tamanio % this->bloque;
	
	int64_t lecturaBytes = this->bloque;

	for (int i = 0;i < vueltas;i++) {
		
		if (restante != 0 and i+1 == vueltas) {
			lecturaBytes = restante;
		}


		archivo.read(buffer, lecturaBytes);
		mostrarBoque(lecturaBytes);
	}
}

int64_t FileReadM::obtieneLongitud(fstream* archivo)
{
	if (archivo == nullptr) {
		throw new invalid_argument("archivo es nulo");
	}

	
	streampos posAux =archivo->tellg();

	archivo->seekg(0, ios::end);



	streampos tamanio = archivo->tellg();

	archivo->seekg(posAux);

	return static_cast<int64_t>(tamanio);

}
