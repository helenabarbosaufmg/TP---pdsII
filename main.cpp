#include <iostream>
#include <vector>
#include "Hospede.h"
#include "Quartos.h"
#include "Reserva.h"

using namespace std;

int main() {
    vector<Hospede> hospedes;
    vector<Quartos> quartos;
    int opcao;

    do {
       cout << "\n\tSISTEMA DO HOTEL" << endl;
        cout << "1 - Cadastrar novo hóspede" << endl;
        cout << "2 - Pesquisar hóspede" << endl; 
        cout << "3 - Cadastrar novo quarto" << endl;
        cout << "4 - Status de reservas (Listar quartos)" << endl;
        cout << "5 - Ocupar quarto" << endl;
        cout << "6 - Liberar quarto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        limparEntrada();

        // 1 - Cadastrar novo quarto
        if (opcao == 1) {
            int numero;
            string tipo;
            double preco;

            cout << "\n\tCadastro de Quarto\n";
            cout << "Número do quarto: ";
            cin >> numero;
            limparEntrada();

            cout << "Tipo (ex: Solteiro, Casal, Luxo): ";
            getline(cin, tipo);

            cout << "Preço da diária: ";
            cin >> preco;
            limparEntrada();

            Quartos novo(numero, tipo, preco);
            quartos.push_back(novo);

            cout << "\nQuarto cadastrado com sucesso!\n";

        }
         else if (opcao == 4) {
            cout << "\n\tStatus de Reservas (Lista de Quartos)\n";
            if (quartos.empty()) {
                cout << "Nenhum quarto cadastrado.\n";
            } else {
                for (auto &q : quartos) {
                    cout << "Quarto " << q.QNumero()
                         << " - Tipo: " << q.QTipo()
                         << " - Preço: R$" << q.QPreco()
                         << " - Status: "
                         << (q.estaOcupado() ? "OCUPADO" : "DISPONÍVEL")
                         << endl;
                }
            }
        }

        // 6 - Ocupar quarto (manual)
        else if (opcao == 6) {
            int numero;
            cout << "\nNúmero do quarto a ocupar: ";
            cin >> numero;
            limparEntrada();

            bool encontrado = false;

            for (auto &q : quartos) {
                if (q.QNumero() == numero) {
                    if (q.estaOcupado()) {
                        cout << "Este quarto já está ocupado.\n";
                    } else {
                        q.ocupar();
                        cout << "Quarto " << numero << " agora está ocupado.\n";
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Quarto não encontrado.\n";
        }

        // 7 - Liberar quarto
        else if (opcao == 7) {
            int numero;
            cout << "\nNúmero do quarto a liberar: ";
            cin >> numero;
            limparEntrada();

            bool encontrado = false;

            for (auto &q : quartos) {
                if (q.QNumero() == numero) {
                    if (!q.estaOcupado()) {
                        cout << "Este quarto já está livre.\n";
                    } else {
                        q.liberar();
                        cout << "Quarto " << numero << " foi liberado.\n";
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Quarto não encontrado.\n";
        }

        else if (opcao != 0) {
            cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}