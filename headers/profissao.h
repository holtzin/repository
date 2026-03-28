#include <iostream>
using namespace std;

class Profissao {
    public:
    string profissao;

    Profissao(string profissao, long int salarioAtual) {
        setProfissao(profissao);
        this->setSalario(salarioAtual);
    }

    void setProfissao(string profissao) {
        this->profissao = profissao;
    } 

    void mostrarProfissao() {
        cout << "|" << "Profissao" << this->profissao << endl;
    }

    private:
    long int salario;

    void setSalario(long int salario) {
        this->salario = salario;
    }

    long int getSalario() {
        return this->salario;
    }
};