#ifndef SERVICO_H
#define SERVICO_H

#include <iostream>
#include <string>
#include "data.h"

using namespace std;

class Servico {
    public:
    int clienteId;
    int trabalhadorId;
    string descricao;
    string habilidade;
    float preco;
    Data data;

    Servico(int clienteId, int trabalhadorId, string descricao, string habilidade, float preco, Data data)
        : clienteId(clienteId), trabalhadorId(trabalhadorId), descricao(descricao), habilidade(habilidade), preco(preco), data(data) {}

    void mostrarServico() {
        cout << "Servico: " << descricao << " | Habilidade: " << habilidade
             << " | Preco: " << preco << " | Data: ";
        data.mostrarData();
    }
};

#endif
