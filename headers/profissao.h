#ifndef PROFISSAO_H
#define PROFISSAO_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Profissao {
    public:
    string profissao;
    long int salario;

    Profissao() : profissao(""), salario(0) {}

    Profissao(string profissao, long int salarioAtual)
        : profissao(profissao), salario(salarioAtual) {}

    void setProfissao(string profissao) {
        this->profissao = profissao;
    }

    string getProfissao() {
        return profissao;
    }

    long int getSalario() {
        return salario;
    }
};

#endif
