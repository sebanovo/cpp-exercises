#include <iostream>
#include <fstream>
#include <string>
#include "../estructuras.h"

using namespace std;

void pregunta2(string ArchivoAlumnos) {
    string temp = "Alumnos.tmp";

    RegistroAlumno registroAlumno;

    // copiar archivo1 en archivo2
    fstream file1(ArchivoAlumnos.c_str(), ios::in | ios::binary);
    fstream file2(temp.c_str(), ios::out | ios::binary);

    while (file1.read((char*)&registroAlumno, sizeof(registroAlumno))) {
        file2.write((char*)&registroAlumno, sizeof(registroAlumno));
    }
    file1.close();
    file2.flush();
    file2.close();
    // ----------------------------------------------------------------
    // ORDENAR EL ARCHIVO 2 (temporal)
    Cardinal p, i, pm, z;
    RegistroAlumno reg1, reg2;
    bool fin = false;
    file2.open(temp.c_str(), ios::in | ios::out | ios::binary);
    if (!file2.is_open()) {
        file2.close();
        return;
    }

    p = 0;
    while (!fin) {
        i = 0;
        pm = p;
        file2.seekg(p);
        while (!file2.eof()) {
            if (p == file2.tellp()) {
                file2.read((char*)&reg1, sizeof(reg1));
                reg2 = reg1;
                z = file2.tellp();
            }
            else {
                file2.read((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
            }
            if (!file2.eof()) {
                i++;
                if (reg1.fechaNacimiento.mes > reg2.fechaNacimiento.mes) {
                    reg2 = reg1;
                    pm = static_cast<std::streamoff>(file2.tellg()) -
                        static_cast<std::streamoff>(sizeof(reg1)); // añadido
                }
            }
        }
        fin = i <= 1;
        if (!fin) {
            file2.close();
            file2.open(temp.c_str(), ios::in | ios::out | ios::binary);
            file2.seekg(p);
            file2.seekp(p);
            z = file2.tellp();

            if (p != pm) {
                file2.read((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
                file2.seekp(p);
                z = file2.tellp();
                file2.write((char*)&reg2, sizeof(reg1));
                z = file2.tellp();
                file2.seekp(pm);
                z = file2.tellp();
                file2.write((char*)&reg1, sizeof(reg1));
                z = file2.tellp();
            }
        }
        p = p + sizeof(reg1);
    }

    file2.flush();
    file2.close();
    // TERMINANDO DE ORDENAR
    string listado = "listado.txt";
    fstream fo(listado.c_str(), ios::out);
    file2.open(temp.c_str(), ios::in | ios::binary);
    while (file2.read((char*)&registroAlumno, sizeof(registroAlumno))) {
        fo << registroAlumno.codigo << ',' << registroAlumno.nombre << ',' << (int)registroAlumno.fechaNacimiento.dia << '/' << (int)registroAlumno.fechaNacimiento.mes << '/' << (int)registroAlumno.fechaNacimiento.anio << '\n';
    }

    file2.close();
    fo.flush();
    fo.close();
    remove(temp.c_str());
}
