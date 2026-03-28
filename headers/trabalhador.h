#include <iostream>
#include "pessoa.h"
#include "profissao.h"
#include <list>

using namespace std;

#ifndef TRABALHADOR_H
#define TRABALHADOR_H

class Trabalhador : Pessoa {
    public:
    list<Profissao> profissoes;
    bool estaDisponivel;
    float nota;

    void setNota(float nota) {
      this->nota = nota; // Fazer uma media ponderada talvez igual a 99
    }
};



#endif