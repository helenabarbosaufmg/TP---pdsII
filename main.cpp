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
    int proximaReserva = 1; // gera números de reserva automaticamente

    do {
        cout << "\n\tSISTEMA DO HOTEL" << endl;
        cout << "1 - Cadastrar novo quarto" << endl;
        cout << "2 - Pesquisar hóspede pelo número de reserva" << endl; 
        cout << "3 - Pesquisar número de reserva" << endl;
        cout << "4 - Cadastrar nova reserva" << endl; 
        cout << "5 - Status de reservas (Listar quartos)" << endl;
        cout << "6 - Ocupar quarto" << endl;
        cout << "7 - Liberar quarto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore();

        // 1 - Cadastrar novo quarto
        if (opcao == 1) {
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
        
        // 2 - Pesquisar hóspede pelo número de reserva
        else if (opcao == 2) {
            int numeroReservaBusca;
            cout << "\nDigite o número da reserva do hóspede: ";
            cin >> numeroReservaBusca;

            bool encontrado = false;
            for (auto &h : hospedes) {
                // Assumindo que HCodigo agora representa o numeroReserva
                if (h.HCodigo() == numeroReservaBusca) {
                    cout << "\nHóspede encontrado:\n";
                    cout << "Número da reserva: " << numeroReservaBusca << endl;
                    cout << "Nome: " << h.HNome() << endl;
                    cout << "RG: " << h.HRG() << endl; 
                    cout << "Telefone: " << h.HTelefone() << endl;
                    cout << "Email: " << h.HEmail() << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Hóspede não encontrado para este número de reserva.\n";
            }
        }

        // 3 - Pesquisar número de reserva (detalhes completos da reserva)
        else if (opcao == 3) { 
            if (reservas.empty()) {
                cout << "\nNenhuma reserva foi cadastrada ainda.\n"; 
            } else {
                int numeroReservaBusca; 
                cout << "\nDigite o número da reserva: ";
                cin >> numeroReservaBusca; 

                bool encontrada = false; 
                for (auto &r : reservas) { 
                    if (r.RNumeroReserva() == numeroReservaBusca) { 
                        Hospede h = r.RHospede(); 
                        Quartos q = r.RQuarto(); 

                        cout << "\nDados da Reserva\n";
                        cout << "Número da reserva: " << r.RNumeroReserva() << endl; 
                        cout << "Status: " << r.RStatus() << endl; 
                        cout << "Check-in: " << r.RCheckIn() << endl; 
                        cout << "Check-out: " << r.RCheckOut() << endl; 

                        cout << "\nHóspede:\n";
                        cout << "Número de reserva (ID do hóspede): " << h.HCodigo() << endl;
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
                    cout << "Reserva não encontrada.\n"; 
                }
            }
        }
        
        // 4 - Cadastrar nova reserva (gera numeroReserva automaticamente)
        else if (opcao == 4) {
            int numeroReserva = proximaReserva++;
            string nome, rg, telefone, email;
            int numeroQuarto;
            string checkIn, checkOut;

            cout << "\n\tCadastro de Reserva" << endl;
            cout << "Número da reserva (gerado automaticamente): " << numeroReserva << endl;

            // Dados do hóspede
            cout << "Nome: ";
            getline(cin, nome);

            cout << "RG: ";
            getline(cin, rg);

            cout << "Telefone: ";
            getline(cin, telefone);

            cout << "Email: ";
            getline(cin, email);

            // Escolha do quarto
            if (quartos.empty()) {
                cout << "\nNenhum quarto cadastrado. Cadastre um quarto antes de criar reservas.\n";
            } else {
                cout << "\nDigite o número do quarto para esta reserva: ";
                cin >> numeroQuarto;
                cin.ignore();

                Quartos* quartoSelecionado = nullptr;

                for (auto &q : quartos) {
                    if (q.QNumero() == numeroQuarto) {
                        quartoSelecionado = &q;
                        break;
                    }
                }

                if (!quartoSelecionado) {
                    cout << "Quarto não encontrado. Reserva não cadastrada.\n";
                } else if (quartoSelecionado->estaOcupado()) {
                    cout << "Quarto já está ocupado. Reserva não cadastrada.\n";
                } else {
                    cout << "Data de check-in: ";
                    getline(cin, checkIn);

                    cout << "Data de check-out: ";
                    getline(cin, checkOut);

                    // Cria hóspede vinculado ao número de reserva
                    Hospede novoHospede(numeroReserva, nome, rg, telefone, email);
                    hospedes.push_back(novoHospede);

                    // Ocupa o quarto e cria reserva
                    quartoSelecionado->ocupar();
                    Reserva novaReserva(numeroReserva, novoHospede, *quartoSelecionado, checkIn, checkOut);
                    reservas.push_back(novaReserva);

                    cout << "\nReserva cadastrada com sucesso!" << endl;
                    cout << "Número da reserva: " << numeroReserva << endl;
                    cout << "Quarto: " << quartoSelecionado->QNumero() << endl;
                }
            }
        }        

        // 5 - Status de reservas (listar quartos)
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
        }

        // 6 - Ocupar quarto (manual)
        else if (opcao == 6) {
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
        }

        // 7 - Liberar quarto
        else if (opcao == 7) {
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
        }

        else if (opcao != 0) {
            cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}