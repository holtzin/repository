#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data {
    public:
    int dia;
    int mes;
    int ano;

    Data(int dia, int mes, int ano)
        : dia(dia), mes(mes), ano(ano) {}

    bool setDia(int dia) {
         if (dia < 1 || dia > 31) {
             return false;
         }
         this->dia = dia;
         return true;
    }

    bool setMes(int mes) {
        if (mes < 1 || mes > 12) {
            return false;
        }
        this->mes = mes;
        return true;
    }

    bool setAno(int ano) {
        if (ano < 1900) {
            return false;
        }
        this->ano = ano;
        return true;
    }

    void mostrarData() {
        cout << "|Dia: " << dia << " | Mes: " << mes << " | Ano: " << ano << "|" << endl;
    }

    bool operator==(Data other) {
        return dia == other.dia && mes == other.mes && ano == other.ano;
    }
};

#endif
