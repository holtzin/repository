#include <iostream>
#include <list>
#include <string>
#include <limits>
#include "../headers/sistema.h"
#include "../headers/profissao.h"

using namespace std;

int lerInteiro(string mensagem)
{
    int valor;
    cout << mensagem;
    cin >> valor;
    return valor;
}

string lerTexto(string mensagem)
{
    string texto;
    cout << mensagem;
    cin >> texto;
    return texto;
}

Data lerData()
{
    int dia = lerInteiro("Digite o dia: ");
    int mes = lerInteiro("Digite o mes: ");
    int ano = lerInteiro("Digite o ano: ");
    return Data(dia, mes, ano);
}

void mostrarTrabalhadores(Sistema &sistema)
{
    cout << "Lista de trabalhadores: " << endl;
    for (auto &trabalhador : sistema.trabalhadores)
    {
        cout << "Id: " << trabalhador.getId() << ": " << trabalhador.getNome() << endl;
    }
}

void mostrarNotasTrabalhadores(Sistema &sistema)
{
    cout << "Notas medias dos trabalhadores:" << endl;
    for (auto &trabalhador : sistema.trabalhadores)
    {
        cout << "Id: " << trabalhador.getId() << ": " << trabalhador.getNome()
             << " - Nota média: " << trabalhador.getNota() << endl;
    }
}

void mostrarContratos(Sistema &sistema)
{
    cout << "Contratos cadastrados:" << endl;
    for (auto &contrato : sistema.contratos)
    {
        contrato.mostrarContrato();
        cout << "----------------------" << endl;
    }
}

void menu()
{
    cout << endl;
    cout << "=== Sistema de Contratação de Trabalhadores ===" << endl;
    cout << "1 - Cadastrar cliente" << endl;
    cout << "2 - Cadastrar trabalhador" << endl;
    cout << "3 - Buscar trabalhador disponível" << endl;
    cout << "4 - Contratar trabalhador" << endl;
    cout << "5 - Pagar contrato" << endl;
    cout << "6 - Avaliar trabalhador" << endl;
    cout << "7 - Mostrar nota média dos trabalhadores" << endl;
    cout << "8 - Mostrar contratos" << endl;
    cout << "9 - Sair" << endl;
}

int main()
{
    Sistema sistema;

    while (true)
    {
        menu();
        int opcao = lerInteiro("Opcao: ");

        if (opcao == 1)
        {
            string nome = lerTexto("Nome cliente: ");
            string cpf = lerTexto("CPF: ");
            int idade = lerInteiro("Idade: ");
            string telefone = lerTexto("Telefone: ");
            string generoTexto = lerTexto("Genero (Masculino M ou Feminino F: ");
            bool genero = (generoTexto.size() > 0 && (generoTexto[0] == 'M' || generoTexto[0] == 'm'));
            string email = lerTexto("Email: ");
            string endereco = lerTexto("Endereco: ");

            Cliente cliente(nome, cpf, idade, telefone, genero, email, endereco);
            sistema.cadastrarCliente(cliente);
            cout << "Cliente cadastrado, id: " << cliente.getId() << "." << endl;
        }
        else if (opcao == 2)
        {
            string nome = lerTexto("Nome do trabalhador: ");
            string cpf = lerTexto("CPF: ");
            int idade = lerInteiro("Idade: ");
            string telefone = lerTexto("Telefone: ");
        
            Trabalhador trabalhador(nome, cpf, idade, telefone, true); // apenas trabalhador masculino
            while (true)
            {
                string profissao = lerTexto("Digite uma profissso do trabalhador, ou aperte enter pra sair: ");
                if (profissao.empty())
                {
                    break;
                }
                int salario = lerInteiro("Salario para essa profissao: ");
                trabalhador.adicionarProfissao(Profissao(profissao, salario));
            }

            sistema.cadastrarTrabalhador(trabalhador);
            cout << "Trabalhador cadastrado com id: " << trabalhador.getId() << "." << endl;
        }
        else if (opcao == 3)
        {
            string habilidade = lerTexto("Habilidade: ");
            cout << "Data do serviço: " << endl;
            Data data = lerData();
            list<int> candidatos = sistema.buscarTrabalhadores(habilidade, data);

            if (candidatos.empty())
            {
                cout << "Nenhum trabalhador disponivel para essa habilidade e data." << endl;
            }
            else
            {
                cout << "Trabalhadores disponiveis:" << endl;
                for (int id : candidatos)
                {
                    Trabalhador *trabalhador = sistema.buscarTrabalhador(id);
                    if (trabalhador != nullptr)
                    {
                        cout << "ID " << trabalhador->getId() << ": " << trabalhador->getNome() << endl;
                    }
                }
            }
        }
        else if (opcao == 4)
        {
            int clienteId = lerInteiro("id do cliente: ");
            int trabalhadorId = lerInteiro("id do trabalhador: ");
            string descricao = lerTexto("Descrição do servico: ");
            string habilidade = lerTexto("Habilidade necessaria: ");
            float preco = 0;
            cout << "Preco do serviço: ";
            cin >> preco; // nao podemos usar ler inteiro aq

            cout << "Data do servico:" << endl;
            Data data = lerData();

            bool contratado = sistema.contratar(clienteId, trabalhadorId, descricao, habilidade, preco, data);
            if (contratado)
            {
                cout << "Contrato criado e servico feito" << endl;
            }
            else
            {
                cout << "Erro ao criar contrato" << endl;
            }
        }
        else if (opcao == 5)
        {
            int contratoId = lerInteiro("id do contrato: ");
            float valor = 0;
            cout << "Valor do pagamento: ";
            cin >> valor;

            bool pago = sistema.pagarContrato(contratoId, valor);
            if (pago)
            {
                cout << "Contrato pago" << endl;
            }
            else
            {
                cout << "Pagamento nao foi feito" << endl;
            }
        }
        else if (opcao == 6)
        {
            int clienteId = lerInteiro("Id do cliente que avalia: ");
            int trabalhadorId = lerInteiro("Id do trabalhador a avaliar: ");
            float nota = 0;
            cout << "Nota de 0 a 5: ";
            cin >> nota;

            Cliente *cliente = sistema.buscarCliente(clienteId);
            Trabalhador *trabalhador = sistema.buscarTrabalhador(trabalhadorId);
            if (cliente != nullptr && trabalhador != nullptr)
            {
                cliente->avaliar(*trabalhador, nota);
                cout << "Trabalhador avaliado, nota atual: " << trabalhador->getNota() << endl;
            }
            else
            {
                cout << "Nao encontramos os clientes ou traalhador " << endl;
            }
        }
        else if (opcao == 7)
        {
            mostrarNotasTrabalhadores(sistema);
        }
        else if (opcao == 8)
        {
            mostrarContratos(sistema);
        }
        else if (opcao == 9)
        {
            cout << "Saindo " << endl;
            break;
        }
        else
        {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
