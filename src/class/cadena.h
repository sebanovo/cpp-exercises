#ifndef functions_stringsH
#define functions_stringsH

#include <string>
using namespace std;

bool es_vocal(char x);
bool es_letra(char x);
int contar_espacios(string x);
int contar_vocales(string x);
int contar_letras_ingles(string x);
void invertir_cadena(string& x);
// ejercicios de examen: 
string filtrar_digitos(string x);
string filtrar_primer_numero(string x);
// --------------------
bool verificar_solo_espacios(string x);
void eliminar_vocales(string& x);
bool verificar_palindromo(string x);
string primer_palabra(string x);
void eliminar_primer_palabra(string& x);
void eliminar_hasta_primer_palabra(string& x);
void eliminar_desde_primer_palabra(string& x);
int contar_palabras(string x);
int numero_mayor(string x);
void invertir_cada_palabra(string& x);
// TODO
// void eliminar_espacios_de_mas(string& str, size_t index);
#endif