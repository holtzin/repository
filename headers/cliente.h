#include <iostream>
#include "pessoa.h" 
#include "trabalhador.h"

using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H

int idTotal = 0;

class Cliente : Pessoa { // Cliente também é uma pessoa com capacidades de alugar um trabalhador -> marido.

    public:
    string email, endereco;
    int id;
    
    Cliente(string email, string endereco)
    {
        this->email = email;
        this->endereco = endereco;
        this->id = idTotal++;
    }

    void avaliar(Trabalhador trabalhador, float nota)
    {
        trabalhador.setNota(nota);
    }
    
    string getEmail()
    {
        return this->email;
    }

    string getEndereco()
    {
        return this->endereco;
    }
};

#endif