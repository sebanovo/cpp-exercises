#pragma hdrstop

#include <string>
#include <cmath>
#include "numero.h"

#pragma package(smart_init)
using namespace std;

int factorial(int x) {
    int f;
    if (x < 2) {
        f = 1;
    }
    else {
        f = x * factorial(x - 1);
    }
    return f;
}

int sumar_digitos(int x) {
    int s;
    if (x < 10) {
        s = x;
    }
    else {
        s = sumar_digitos(x / 10) + x % 10;
    }
    return s;
}

int sumar_digitos_pares(int x) {
    int s;
    if (x < 10) {
        if (x % 2 == 0)
            s = x;
        else
            s = 0;
    }
    else {
        s = sumar_digitos_pares(x / 10);
        if (x % 2 == 0)
            s = s + x % 10;
    }
    return s;
}

int sumar_digitos_impares(int x) {
    int s;
    if (x < 10) {
        if (x % 2 == 1)
            s = x;
        else
            s = 0;
    }
    else {
        s = sumar_digitos_impares(x / 10);
        if (x % 2 == 1)
            s = s + x % 10;
    }
    return s;
}

int restar_digitos_par_impar(int x) {
    int s;
    if (x < 10) {
        if (x % 2 == 0)
            s = x;
        else
            s = -x;
    }
    else {
        if (x % 2 == 0)
            s = x % 10;
        else
            s = -x % 10;
        s = restar_digitos_par_impar(x / 10) + s;
    }
    return s;
}

int restar_digitos_impar_par(int x) {
    int s;
    if (x < 10) {
        if (x % 2 == 1)
            s = x;
        else
            s = -x;
    }
    else {
        if (x % 2 == 1)
            s = x % 10;
        else
            s = -x % 10;
        s = restar_digitos_impar_par(x / 10) + s;
    }
    return s;
}


int contar_digitos(int x) {
    int c;
    if (x < 10) {
        c = 1;
    }
    else {
        c = contar_digitos(x / 10) + 1;
    }
    return c;
}

string agregar_coma_digitos(int x) {
    string s;
    if (x < 10) {
        s = to_string(x);
    }
    else {
        s = agregar_coma_digitos(x / 10) + ',' + to_string(x % 10);
    }
    return s;
}

string agregar_coma_digitos_e_invertir(int x) {
    string s;
    if (x < 10) {
        s = to_string(x);
    }
    else {
        s = to_string(x % 10) + ',' + agregar_coma_digitos_e_invertir(x / 10);
    }
    return s;
}

int retornar_menor_digito(int x) {
    int m;
    if (x < 10) {
        m = x;
    }
    else {
        m = retornar_menor_digito(x / 10);
        if (x % 10 < m) {
            m = x % 10;
        }
    }
    return m;
}

int retornar_mayor_digito(int x) {
    int m;
    if (x < 10) {
        m = x;
    }
    else {
        m = retornar_mayor_digito(x / 10);
        if (x % 10 > m) {
            m = x % 10;
        }
    }
    return m;
}

bool verificar_ordenado_ascendente(int x) {
    bool b;
    if (x < 10) {
        b = true;
    }
    else {
        b = verificar_ordenado_ascendente(x / 10) && (x / 10 % 10 <= x % 10);
    }
    return b;
}

bool verificar_ordenado_descendente(int x) {
    bool b;
    if (x < 10) {
        b = true;
    }
    else {
        b = verificar_ordenado_descendente(x / 10) && (x / 10 % 10 >= x % 10);
    }
    return b;
}

void mover_digito_mayor_al_final(int& x) {
    if (x < 10) {
        // nada
    }
    else {
        int d = x % 10;
        x = x / 10;
        mover_digito_mayor_al_final(x);
        if (x % 10 <= d) {
            x = x * 10 + d;
        }
        else {
            int z = x % 10;
            x = x / 10;
            x = (x * 10 + d) * 10 + z;
        }
    }
}

void mover_digito_menor_al_final(int& x) {
    if (x < 10) {
        // nada
    }
    else {
        int d = x % 10;
        x = x / 10;
        mover_digito_menor_al_final(x);
        if (x % 10 >= d) {
            x = x * 10 + d;
        }
        else {
            int z = x % 10;
            x = x / 10;
            x = (x * 10 + d) * 10 + z;
        }
    }
}

void ordenamiento_ascendente(int& x) {
    if (x < 10) {
        // nada
    }
    else {
        mover_digito_mayor_al_final(x);
        int ultimoDigito = x % 10;
        x = x / 10;
        ordenamiento_ascendente(x);
        x = x * 10 + ultimoDigito;
    }
}

void ordenamiento_descendente(int& x) {
    if (x < 10) {
        // nada
    }
    else {
        mover_digito_menor_al_final(x);
        int ultimoDigito = x % 10;
        x = x / 10;
        ordenamiento_descendente(x);
        x = x * 10 + ultimoDigito;
    }
}

void eliminar_digitos_impares(int& x) {
    if (x < 10) { // caso base
        if (x % 2 == 0) {
            // nada 
        }if (x % 2 == 1) {
            x = 0;
        }
    }
    else { // caso general
        int ultimoDigito = x % 10;
        x = x / 10;
        eliminar_digitos_impares(x);
        if (ultimoDigito % 2 == 0) {
            x = x * 10 + ultimoDigito;
        }
        if (ultimoDigito % 2 == 1) {
            // nada
        }
    }
}

void eliminar_digitos_pares(int& x) {
    if (x < 10) { // caso base
        if (x % 2 == 1) {
            // nada 
        }if (x % 2 == 0) {
            x = 0;
        }
    }
    else { // caso general
        int ultimoDigito = x % 10;
        x = x / 10;
        eliminar_digitos_pares(x);
        if (ultimoDigito % 2 == 1) {
            x = x * 10 + ultimoDigito;
        }
        if (ultimoDigito % 2 == 0) {
            // nada
        }
    }
}

void encontrar_digito_mayor_y_menor(int x, int& M, int& m) {
    if (x < 10) { // caso base
        M = x;
        m = x;
    }
    else { // caso general
        int ultimoDigito = x % 10;
        x = x / 10;
        encontrar_digito_mayor_y_menor(x, M, m);
        if (M < ultimoDigito) {
            M = ultimoDigito;
        }
        if (m > ultimoDigito) {
            m = ultimoDigito;
        }
    }
}

// ejercicio de examen
string repetir_numero(int numero, int veces)
{
    string cad;
    if (veces == 0)
        cad = "";
    else
        cad = repetir_numero(numero, veces - 1) + to_string(numero);
    return cad;
}

string repetir_digitos(int n)
{
    string cad;
    if (n < 10)
        cad = repetir_numero(n, n);
    else {
        int dig = n % 10;
        n = n / 10;
        cad = repetir_digitos(n) + repetir_numero(dig, dig);
    }
    return cad;
}

// Ej. CantDigPares(3827435) => 2
int contar_digitos_impares_antes_de_uno_par(int x) {
    int c;
    if (x < 10) {
        c = 0;
    }
    else {
        int ultimoDigito = x % 10;
        int penultimoDigito = x / 10 % 10;
        if (penultimoDigito % 2 == 0 && ultimoDigito % 2 == 1) {
            c = contar_digitos_impares_antes_de_uno_par(x / 10) + 1;
        }
        else {
            c = contar_digitos_impares_antes_de_uno_par(x / 10);
        }
    }
    return c;
}

