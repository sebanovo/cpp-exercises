#ifndef functions_numbersH
#define functions_numbersH

#include <string> 
using namespace std;

int factorial(int x);
int sumar_digitos(int x);
int sumar_digitos_pares(int x);
int sumar_digitos_impares(int x);
int restar_digitos_par_impar(int x);
int restar_digitos_impar_par(int x);
int contar_digitos(int x);
string agregar_coma_digitos(int x);
string agregar_coma_digitos_e_invertir(int x);
int retornar_menor_digito(int x);
int retornar_mayor_digito(int x);
bool verificar_ordenado_ascendente(int x);
bool verificar_ordenado_descendente(int x);
void mover_digito_mayor_al_final(int& x);
void mover_digito_menor_al_final(int& x);
void ordenamiento_ascendente(int& x);
void ordenamiento_descendente(int& x);
void eliminar_digitos_impares(int& x);
void eliminar_digitos_pares(int& x);
void encontrar_digito_mayor_y_menor(int x, int& M, int& m);
// Ejercicio de examen: 
string repetir_numero(int numero, int veces);
string repetir_digitos(int n);
// Ejercicio de practico: 
int contar_digitos_impares_antes_de_uno_par(int x);
#endif