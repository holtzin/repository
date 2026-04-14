#ifndef TRABALHADOR_H
#define TRABALHADOR_H

#include <string>
#include <list>
#include <algorithm>
#include "pessoa.h"
#include "profissao.h"

using namespace std;

class Trabalhador : public Pessoa {
    public:
    static inline int nextId = 1;

    int id;
    list<Profissao> profissoes;
    list<float> avaliacoes;

    Trabalhador()
        : Pessoa(), id(nextId += 1), avaliacoes() {}

    Trabalhador(string nome, string cpf, int idade,
                string telefone, bool genero)
        : Pessoa(idade, telefone, nome, cpf, genero), id(nextId += 1), avaliacoes() {}

    int getId() {
        return id;
    }

    void adicionarProfissao(Profissao profissao) {
        profissoes.push_back(profissao);
    }

    bool temProfissao(string nomeProfissao) {
        for (auto& p : profissoes) {
            if (p.getProfissao() == nomeProfissao) {
                return true;
            }
        }
        return false;
    }

    void receberAvaliacao(float nota) {
        if (nota < 0) {
            nota = 0;
        }
        if (nota > 5) {
            nota = 5;
        }
        avaliacoes.push_back(nota);
        if (avaliacoes.size() > 10) {
            avaliacoes.pop_front();
        }
    }

    float getNota() {
        if (avaliacoes.empty()) {
            return 0;
        }
        int peso = 1;
        float totalPesos = 0;
        float soma = 0;
        for (float avaliacao : avaliacoes) {
            soma += avaliacao * peso;
            totalPesos += peso;
            peso += 1;
        }
        return soma / totalPesos;
    }
};

#endif
