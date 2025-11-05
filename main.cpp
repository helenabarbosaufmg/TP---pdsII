#include <iostream>
#include <vector>
#include "Hospede.h"
using namespace std;

int main() {
    vector<Hospede> hospedes;
    int opcao;

    do {
        cout << "\tSISTEMA DO HOTEL" << endl;
        cout << "1 - Cadastrar novo hóspede" << endl;
        cout << "2 - Status de reservas" << endl;
        cout << "3 - Pesquisar hóspede" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            int codigo;
            string nome, rg, telefone, email;

            cout << "\tCadastro de Hóspede" << endl;
            cout << "Código: ";
            cin >> codigo;
            cin.ignore();

            cout << "Nome: ";
            getline(cin, nome);

            cout << "RG: ";
            getline(cin, rg);

            cout << "Telefone: ";
            getline(cin, telefone);

            cout << "Email: ";
            getline(cin, email);

            Hospede novo(codigo, nome, rg, telefone, email);
            hospedes.push_back(novo);

            cout << "\n \t Hóspede cadastrado com sucesso!" << endl;

        } else if (opcao == 2) {
           
        } else if (opcao == 3) {

        }

    } while (opcao != 0);
    return 0;
}
