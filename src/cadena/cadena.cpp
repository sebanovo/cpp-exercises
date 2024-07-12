#pragma hdrstop

#include <iostream>
#include <string>
#include <cmath>
#include "cadena.h"

#pragma package(smart_init)
using namespace std;

bool es_vocal(char c) {
    string vocales = "aeiouAEIOUáéíóúÁÉÍÓÚäëïöüÄËÏÖÜ"; // Todas las vocales
    return vocales.find(c) != string::npos;
}

bool  es_digito(char c) {
    string digitos = "0123456789"; // Todas las letras en español
    return digitos.find(c) != string::npos;
}

bool  es_letra(char c) {
    string vocales = "qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNMáéíóúÁÉÍÓÚäëïöüÄËÏÖÜ"; // Todas las letras en español
    return vocales.find(c) != string::npos;
}

string trim(const string& str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");

    if (first == std::string::npos) // Cadena completamente en blanco
        return "";

    return str.substr(first, last - first + 1);
}

int contar_espacios(string x) {
    int c;
    if (x == "") {
        c = 0;
    }
    else {
        char ultimaLetra = x.back();
        x.pop_back();
        c = contar_espacios(x);
        if (ultimaLetra == ' ') {
            c++;
        }
    }
    return c;
}

// TODO: Arreglar esta función porque esta mal
// esta funcion esta mal aeiouáéíóúäëïöü
int contar_vocales(string x) {
    int c;
    if (x == "") {
        c = 0;
    }
    else {
        char ultimaLetra = x.back();
        x.pop_back();
        c = contar_vocales(x);
        if (es_vocal(ultimaLetra)) {
            c++;
        }
    }
    return c;
}

int contar_letras_ingles(string x) {
    int c;
    if (x == "") {
        c = 0;
    }
    else {
        char a = x.back();
        x.pop_back();
        c = contar_letras_ingles(x);
        if (isalpha(a)) {
            c++;
        }
    }
    return c;
}

void invertir_cadena(string& x) {
    if (x == "") {
        // nada
    }
    else {
        char a = x[0];
        x.erase(0, 1);
        invertir_cadena(x); //  dnum aloH
        x = x + a;
    }
}

string filtrar_digitos(string x)
{
    string s;
    if (x == "") {
        s = "";
    }
    else {
        char a = x.back();
        x.pop_back();
        s = filtrar_digitos(x);
        if (es_digito(a)) {
            s = s + a;
        }
    }
    return s;
}

string filtrar_primer_numero(string x)
{
    string s;
    if (x == "") {
        s = "";
    }
    else {
        char a = x[0];
        x.erase(0, 1);
        if (!es_digito(a) && s == "") {
            s = filtrar_primer_numero(x);
        }
        else {
            if (x != "" && es_digito(x[0])) {
                s = a + filtrar_primer_numero(x);
            }
            else {
                s = a;
            }
        }
    }

    return s;
}

bool verificar_solo_espacios(string x) {
    bool b;
    if (x == " ") {
        b = true;
    }
    else {
        char a = x.back();
        x.pop_back();
        if (a != ' ') {
            b = false;
        }
        else {
            b = verificar_solo_espacios(x);
        }
    }
    return b;
}

void eliminar_vocales(string& x) {
    if (x == "") {
        // nada
    }
    else {
        char  a = x[0];
        x.erase(0, 1);
        eliminar_vocales(x);
        if (!es_vocal(a)) {
            x = a + x;
        }
    }
}

bool verificar_palindromo(string x)
{
    bool b;
    int length = x.length();
    if (length <= 1) {
        b = true;
    }
    else {
        char primero = x[0];
        char ultimo = x[length - 1];

        x.erase(length - 1, 1);
        x.erase(0, 1);
        b = verificar_palindromo(x);
        if (primero != ultimo) {
            b = false;
        }
    }
    return b;
}

string primer_palabra(string x)
{
    string p;
    int c = x.length();
    if (c == 0) {
        p = "";
    }
    else if (c == 1) {
        if (es_letra(x[0])) {
            p = x;
        }
        else {
            p = "";
        }
    }
    else {
        char a = x[0]; // a = h
        x.erase(0, 1);
        p = primer_palabra(x); // n-1 => hola mundo -> ola
        if (es_letra(a) && es_letra(x[0])) {
            p = a + p;
        }
        else if (es_letra(a) && !es_letra(x[0])) {
            p = a;
        }
        else if (!es_letra(a) && es_letra(x[0])) {
            // nada
        }
        else if (!es_letra(a) && !es_letra(x[0])) {
            // nada
        }
    }
    return p;
}

void eliminar_primer_palabra(string& x)
{
    int c = x.length();
    if (c == 0) {
        // nada
    }
    else if (c == 1) {
        if (es_letra(x[0])) {
            x = "";
        }
        else {
            // nada
        }
    }
    else {
        char a = x[0];
        x.erase(0, 1);
        if (es_letra(a) && es_letra(x[0])) {
            eliminar_primer_palabra(x);
        }
        else if (es_letra(a) && !es_letra(x[0])) {
            // nada
        }
        else if (!es_letra(a) && es_letra(x[0])) {
            eliminar_primer_palabra(x);
            x = a + x;
        }
        else if (!es_letra(a) && !es_letra(x[0])) {
            eliminar_primer_palabra(x);
            x = a + x;
        }
    }
}

// Ej1 x = "hola a todos" => " a todos"
// Ej2 x = "123hola a todos" => " a todos"
void eliminar_hasta_primer_palabra(string& x)
{
    if (x == "") {
        // nada
    }
    else {
        char a = x[0];
        // a1
        x.erase(0, 1);
        if (!es_letra(a)) {
            eliminar_hasta_primer_palabra(x);
        }
        else {
            if (x != "" && es_letra(x[0])) {
                eliminar_hasta_primer_palabra(x);
            }
        }
    }
}

// Ej x = "hola a todos *123" => "hola a "
void eliminar_desde_primer_palabra(string& x)
{
    if (x == "") {
        // nada
    }
    else {
        char a = x[x.length() - 1];
        x.erase(x.length() - 1, 1);

        if (!es_letra(a)) {
            eliminar_desde_primer_palabra(x);
        }
        else {
            if (x != "" && es_letra(x[x.length() - 1])) {
                eliminar_desde_primer_palabra(x);
            }
        }
    }
}

int contar_palabras(string x)
{
    int c;
    int length = x.length();
    if (length == 0) {
        c = 0;
    }
    else if (length == 1) {
        if (es_letra(x[0])) {
            c = 1;
        }
        else {
            c = 0;
        }
    }
    else {
        char a = x[0];
        x.erase(0, 1);
        c = contar_palabras(x);
        if (es_letra(a) && !es_letra(x[0])) {
            c++;
        }
    }

    return c;
}

// EJERCICIO MÁS DIFICIL
// -------------------------------------------------------------
// Ej1: x = "hola104 mundo54 como1 estan" => 104
// Ej2: x = "Hola mundo" => 0
int posNum(string cad, bool num)
{
    int pos;
    if (cad.length() == 0)
        pos = 0;
    else {
        char c = cad[cad.length() - 1];
        cad.erase(cad.length() - 1, 1);
        pos = posNum(cad, num);
        if (pos == 0) {
            if (num) {
                if (es_digito(c))
                    pos = cad.length() + 1;
            }
            else {
                if (!es_digito(c))
                    pos = cad.length() + 1;
            }
        }
    }
    return pos;
}

int mayor(string cad)
{
    int may;
    if (cad.length() == 0)
        may = 0;
    else {
        int posA = posNum(cad, true);
        int num;
        if (posA > 0) {
            cad.erase(0, posA - 1);
            int posB = posNum(cad, false);
            if (posB == 0)
                posB = cad.length() + 1;
            num = stoi(cad.substr(0, posB));
            cad.erase(0, posB - 1);
        }
        else {
            num = 0;
            cad = "";
        }
        may = mayor(cad);
        if (num > may)
            may = num;
    }
    return may;
}

int numero_mayor(string x)
{
    int may;
    if (x.length() == 0)
        may = 0;
    else {
        int pos = x.find(" ");
        if (pos == 0)
            pos = x.length() + 1;
        string pal = x.substr(0, pos);
        x.erase(0, pos);
        may = numero_mayor(x);
        int num = mayor(pal);
        if (num > may)
            may = num;
    }
    return may;
}
// ---------------------------------FIN MAS DIFICIL ---------------------------
int lastDelimiter(string& str, string delimiters)
{
    int found = str.find_last_of(delimiters);
    return found;
}

void invertir_cada_palabra(string& x) {
    // nada
}
