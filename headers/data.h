#include <iostream>

using namespace std;

#ifndef DATA_H
#define DATA_H

class Data {
    public:
    int dia; int mes; int ano;

    Data(int dia, int mes, int ano)  {
        setDia(dia); 
        setMes(mes);
        setAno(ano);
    }

// colocar verificações e bool nesses set ou deixar void igual os outros?
    bool setDia(int dia) {
         this->dia = dia;
         return true;
    }
    bool setMes(int mes) {
        this->mes = mes;
        return true; // Talvez coloar verificações aqui mais é complicado pois se o ano virar o mes pode ser menor que o atual (mes 12 indo pro 1);
    }

    bool setAno(int ano) {
        if (ano < this->ano) {
            return false;
        }
        this->ano = ano;
        return true;
    }

    void mostrarData() {
        cout << "|" << "Dia: " << this->dia << " |" << "Mes: " << this->mes << " |" << "Ano: " << this->ano << "|" << endl;
    }

    int getDia() {
        return this->dia;
    }

    int getMes() {
        return this->mes;
    }
    int getAno() {
        return this->ano;
    }
};

#endif