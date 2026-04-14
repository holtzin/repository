#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    protected:
    string nome;
    string cpf;
    string fone;
    int idade;
    bool masculino;

    public:
    Pessoa() : nome(""), cpf(""), fone(""), idade(0), masculino(true) {}

    Pessoa(int idade, string telefone, string nome,
           string cpf, bool genero)
        : nome(nome), cpf(cpf), fone(telefone), idade(idade), masculino(genero) {}

    virtual ~Pessoa() {}

    string getNome() {
        return nome;
    }

    string getCpf() {
        return cpf;
    }

    string getFone() {
        return fone;
    }

    int getIdade() {
        return idade;
    }

    bool isMasculino() {
        return masculino;
    }
};

#endif
