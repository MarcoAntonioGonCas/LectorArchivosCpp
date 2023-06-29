// 002-leerArchivoBloques.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "FileReadM.h"
#include <math.h>

int main()
{
    std::cout << "Rango de char con signo: " << (int)std::numeric_limits<char>::min() << " a "
        << (int)std::numeric_limits<char>::max() << std::endl;

    std::cout << "Rango de unsigned char: " << (int)std::numeric_limits<unsigned char>::min() << " a "
        << (int)std::numeric_limits<unsigned char>::max() << std::endl;
    FileReadM file;
    string ruta;
    cout << "Introduce la ruta del archivo: ";


    //getline(std::cin, ruta);

    file.leer();

    //auto tamanio = ceil( 207062109 / (long double) file.bloque );

    
    
    //cout << tamanio;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
