#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

#include "pessoa.h"
#include "trabalhador.h"

using namespace std;

class Cliente : public Pessoa {
    public:
    static inline int nextId = 1;

    int id;
    string email;
    string endereco;

    Cliente() : Pessoa(), id(nextId++), email(""), endereco("") {}

    Cliente(string nome, string cpf, int idade,
            string telefone, bool genero,
            string email, string endereco)
        : Pessoa(idade, telefone, nome, cpf, genero),
          id(nextId++),
          email(email),
          endereco(endereco) {}

    int getId() {
        return id;
    }

    string getEmail() {
        return email;
    }

    string getEndereco() {
        return endereco;
    }

    void avaliar(Trabalhador &trabalhador, float nota) {
        trabalhador.receberAvaliacao(nota);
    }
};

#endif
