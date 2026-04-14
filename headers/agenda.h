#ifndef AGENDA_H
#define AGENDA_H

#include <list>
#include "servico.h"

using namespace std;

class Agenda {
    public:
    list<Servico> servicos;

    bool estaOcupado(int trabalhadorId, Data data) {
        for (auto &servico : servicos) {
            if (servico.trabalhadorId == trabalhadorId && servico.data == data) {
                return true;
            }
        }
        return false;
    }

    bool marcarServico(Servico servico) {
        if (estaOcupado(servico.trabalhadorId, servico.data)) {
            return false;
        }
        servicos.push_back(servico);
        return true;
    }
};

#endif
