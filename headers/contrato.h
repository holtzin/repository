#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream>
#include <string>
#include "servico.h"

using namespace std;

class Contrato {
    public:
    static inline int nextId = 1;

    int id;
    int clienteId;
    int trabalhadorId;
    Servico servico;
    float valorTotal;
    bool pago;
    string status;

    Contrato(int clienteId, int trabalhadorId, Servico servico, float valorTotal)
        : id(nextId++), clienteId(clienteId), trabalhadorId(trabalhadorId), servico(servico),
          valorTotal(valorTotal), pago(false), status("Aberto") {}

    void pagar(float valor) {
        if (valor >= valorTotal) {
            pago = true;
            status = "Pago";
        } else {
            cout << "Valor insuficiente " << endl;
        }
    }

    void mostrarContrato() {
        cout << "Contrato id: " << id << " Cliente: " << clienteId << " - Trabalhador " << trabalhadorId << " - " << status << endl;
        cout << "Valor total: " << valorTotal << " | Pago: " << (pago ? "Sim" : "Não") << endl;
        servico.mostrarServico();
    }
};

#endif