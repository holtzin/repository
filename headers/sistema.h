#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <cstring>
#include <list>

#include "cliente.h"
#include "trabalhador.h"
#include "agenda.h"
#include "servico.h"
#include "contrato.h"

using namespace std;

class Sistema {
    public:
    list<Cliente> clientes;
    list<Trabalhador> trabalhadores;
    list<Contrato> contratos;
    Agenda agenda;

    void cadastrarCliente(Cliente cliente) {
        clientes.push_back(cliente);
    }

    void cadastrarTrabalhador(Trabalhador trabalhador) {
        trabalhadores.push_back(trabalhador);
    }

    Cliente *buscarCliente(int id) {
        for (auto &cliente : clientes) {
            if (cliente.getId() == id) {
                return &cliente;
            }
        }
        return nullptr;
    }

    Trabalhador *buscarTrabalhador(int id) {
        for (auto &trabalhador : trabalhadores) {
            if (trabalhador.getId() == id) {
                return &trabalhador;
            }
        }
        return nullptr;
    }

    list<int> buscarTrabalhadores(string habilidade, Data data) {
        list<int> ids;
        for (auto &trabalhador : trabalhadores) {
            if (trabalhador.temProfissao(habilidade) && !agenda.estaOcupado(trabalhador.getId(), data)) {
                ids.push_back(trabalhador.getId());
            }
        }
        return ids;
    }

    bool contratar(int clienteId, int trabalhadorId, string descricao, string habilidade, float preco, Data data) {
        Cliente *cliente = buscarCliente(clienteId);
        Trabalhador *trabalhador = buscarTrabalhador(trabalhadorId);
        if (cliente == nullptr || trabalhador == nullptr) {
            return false;
        }
        if (!trabalhador->temProfissao(habilidade)) {
            return false;
        }
        if (agenda.estaOcupado(trabalhadorId, data)) {
            return false;
        }
        Servico servico(clienteId, trabalhadorId, descricao, habilidade, preco, data);
        if (!agenda.marcarServico(servico)) {
            return false;
        }
        contratos.push_back(Contrato(clienteId, trabalhadorId, servico, preco));
        return true;
    }

    Contrato *buscarContrato(int id) {
        for (auto &contrato : contratos) {
            if (contrato.id == id) {
                return &contrato;
            }
        }
        return nullptr;
    }

    bool pagarContrato(int contratoId, float valor) {
        Contrato *contrato = buscarContrato(contratoId);
        if (contrato == nullptr) {
            return false;
        }
        contrato->pagar(valor);
        return contrato->pago;
    }
};

#endif
