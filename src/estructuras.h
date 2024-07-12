#ifndef ESTRUCTURAS_H  
#define ESTRUCTURAS_H

#include <iostream> 
#include <fstream>
#include <string>
#include <cstring>

typedef unsigned char Byte;
typedef unsigned short Word;
typedef unsigned int Cardinal;

struct Fecha
{
    Byte dia;
    Byte mes;
    Word anio;
};

struct RegistroAlumno
{
    Byte marca;
    Word codigo;
    char nombre[31];
    char direccion[26];
    Fecha fechaNacimiento;
    Cardinal telefono;
};

#endif
