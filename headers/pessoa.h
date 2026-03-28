#include <iostream>
using namespace std;

class Pessoa
{
    public:
    string fone;
    int idade;

    Pessoa(int idade, string telefone, string nome, string cpf, bool genero)
    {
        this->idade = idade;
        this->fone = telefone;
        this->setNome(nome);
        this->setCpf(cpf);
        this->setGenero(genero);
    }
 // precisa fazer o destrutor virtual e o construtor default e uma função exibir a pessoa que é virtual tbm pra 
    private:
    string nome, cpf;
    bool masculino;

    string setNome(string nome)
    {
        this->nome = nome;
        return;
    }

    string setCpf(string cpf)
    {
        this->cpf = cpf;
        return;
    }

    bool setGenero(bool genero)
    {
        this->masculino = genero;
        return true;
    }
    

};