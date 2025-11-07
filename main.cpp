#include <iostream>
#include <vector>
#include <string> 
#include "Hospede.h"
#include "Quartos.h"
#include "Reserva.h"
using namespace std;

int main() {
    vector<Hospede> hospedes;
    vector<Quartos> quartos;
    vector<Reserva> reservas; 
    int opcao;
    int proximaReserva = 1; 

    do {
       cout << "\n\tSISTEMA DO HOTEL" << endl;
        cout << "1 - Cadastrar novo hóspede" << endl;
        cout << "2 - Pesquisar hóspede" << endl; 
        cout << "3 - Pesquisar número de reserva" << endl;
        cout << "4 - Cadastrar novo quarto" << endl;
        cout << "5 - Status de reservas (Listar quartos)" << endl;
        cout << "6 - Ocupar quarto" << endl;
        cout << "7 - Liberar quarto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
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
            int codigo;
            cout << "\nDigite o código do hóspede: ";
            cin >> codigo;
            bool encontrado = false;
            for (auto &h : hospedes) {
                if (h.HCodigo() == codigo) { 
                    cout << "\nHóspede encontrado:\n";
                    cout << "Nome: " << h.HNome() << endl;
                    cout << "RG: " << h.HRG() << endl; 
                    cout << "Telefone: " << h.HTelefone() << endl;
                    cout << "Email: " << h.HEmail() << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Hóspede não encontrado.\n";
            }
        }
        else if(opcao == 3){ 
            if(reservas.empty()) {
                cout << "\nNenhuma reserva foi cadastrada ainda" << endl; 
            } else {
                int numeroBusca; 
                cout << "\nDigite o número da reserva: "<< endl; 
                cin >> numeroBusca; 

                bool encontrada = false; 
                for (auto &r : reservas) { 
                    if (r.RNumeroReserva () == numeroBusca) { 
                        Hospede h = r.RHospede(); 
                        Quartos q = r.RQuarto; 

                        cout << "\nDados da Reserva: "<< r.RNumeroReserva() << endl; 
                        cout << "Status: " << r.RStatus() << endl; 
                        cout << "Check-in: " << r.RCheckIn() << endl; 
                        cout << "Check-out: " << r.RCheckOut() << endl; 

                        cout << "\nHóspede:\n";
                        cout << "Código: " << h.HCodigo() << endl;
                        cout << "Nome: " << h.HNome() << endl;
                        cout << "RG: " << h.HRG() << endl;
                        cout << "Telefone: " << h.HTelefone() << endl;
                        cout << "Email: " << h.HEmail() << endl;

                        cout << "\nQuarto:\n";
                        cout << "Número: " << q.QNumero() << endl;
                        cout << "Tipo: " << q.QTipo() << endl;
                        cout << "Preço diária: R$ " << q.QPreco() << endl;

                        encontrada = true; 
                        break; 
                    } 
                } 
                if (!encontrada) { 
                    cout << "Reserva não encontrada. " << endl; 
                }
            }
        } 
    
        } else if (opcao == 4) {
            int numero;
            string tipo;
            double preco;

            cout << "\n\tCadastro de Quarto\n";
            cout << "Número do quarto: ";
            cin >> numero;
            cin.ignore(); 

            cout << "Tipo (ex: Solteiro, Casal, Luxo): ";
            getline(cin, tipo);

            cout << "Preço da diária: ";
            cin >> preco;

            Quartos novo(numero, tipo, preco); 
            quartos.push_back(novo);

            cout << "\nQuarto cadastrado com sucesso!\n";

        }
         else if (opcao == 5) {
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
        
        } else if (opcao == 6) {
            int numero;
            cout << "\nNúmero do quarto a ocupar: ";
            cin >> numero;
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

        } else if (opcao == 7) {
            int numero;
            cout << "\nNúmero do quarto a liberar: ";
            cin >> numero;
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
        
        } else if (opcao != 0) {
            cout << "Opção inválida.\n";
        }

    } while (opcao != 0);
    return 0;
}
