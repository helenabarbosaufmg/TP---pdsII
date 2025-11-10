#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Hospede.h"
#include "Quartos.h"
#include "Reserva.h"

using namespace std;

int main() {
    vector<Hospede> hospedes;
    vector<Quartos> quartos;
    vector<Reserva> reservas;

    int opcao;
    int proximaReserva = 1;      // gera números de reserva automaticamente
    int proximoHospedeId = 1;    // gera IDs de hóspede

    auto limparEntrada = []() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    do {
        cout << "\n\tSISTEMA DO HOTEL" << endl;
        cout << "1 - Cadastrar novo quarto" << endl;
        cout << "2 - Cadastrar novo hóspede no quarto previamente cadastrado" << endl;
        cout << "3 - Pesquisar número de reserva" << endl;
        cout << "4 - Cadastrar nova reserva" << endl;
        cout << "5 - Status de reservas (Listar quartos)" << endl;
        cout << "6 - Ocupar quarto" << endl;
        cout << "7 - Liberar quarto" << endl;
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

        // 2 - Cadastrar novo hóspede no quarto previamente cadastrado
        else if (opcao == 2) {
            if (quartos.empty()) {
                cout << "\nNenhum quarto cadastrado. Cadastre um quarto antes.\n";
            } else {
                cout << "\nQuartos cadastrados:\n";
                for (auto &q : quartos) {
                    cout << "Quarto " << q.QNumero()
                         << " - Tipo: " << q.QTipo()
                         << " - Preço: R$" << q.QPreco()
                         << " - Status: " << (q.estaOcupado() ? "OCUPADO" : "DISPONÍVEL")
                         << endl;
                }

                int numeroQuarto;
                cout << "\nDigite o número do quarto para este hóspede: ";
                cin >> numeroQuarto;
                limparEntrada();

                Quartos* quartoSelecionado = nullptr;
                for (auto &q : quartos) {
                    if (q.QNumero() == numeroQuarto) {
                        quartoSelecionado = &q;
                        break;
                    }
                }

                if (!quartoSelecionado) {
                    cout << "Quarto não encontrado.\n";
                } else if (quartoSelecionado->estaOcupado()) {
                    cout << "Quarto já está ocupado. Não é possível alocar novo hóspede.\n";
                } else {
                    string nome, rg, telefone, email;
                    string checkIn, checkOut;

                    cout << "\n\tDados do Hóspede\n";
                    cout << "Nome: ";
                    getline(cin, nome);

                    cout << "RG: ";
                    getline(cin, rg);

                    cout << "Telefone: ";
                    getline(cin, telefone);

                    cout << "Email: ";
                    getline(cin, email);

                    cout << "Data de check-in: ";
                    getline(cin, checkIn);

                    cout << "Data de check-out: ";
                    getline(cin, checkOut);

                    int idHospede = proximoHospedeId++;
                    Hospede novoHospede(idHospede, nome, rg, telefone, email);
                    hospedes.push_back(novoHospede);

                    int numeroReserva = proximaReserva++;
                    quartoSelecionado->ocupar();
                    Reserva novaReserva(numeroReserva, novoHospede, *quartoSelecionado, checkIn, checkOut);
                    reservas.push_back(novaReserva);

                    cout << "\nHóspede cadastrado e alocado com sucesso!" << endl;
                    cout << "ID do hóspede: " << idHospede << endl;
                    cout << "Número da reserva: " << numeroReserva << endl;
                    cout << "Quarto: " << quartoSelecionado->QNumero() << endl;
                }
            }
        }

        // 3 - Pesquisar número de reserva
        else if (opcao == 3) {
            if (reservas.empty()) {
                cout << "\nNenhuma reserva foi cadastrada ainda.\n";
            } else {
                int numeroReservaBusca;
                cout << "\nDigite o número da reserva: ";
                cin >> numeroReservaBusca;
                limparEntrada();

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
                        cout << "ID: " << h.HCodigo() << endl;
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

        // 4 - Cadastrar nova reserva
        else if (opcao == 4) {
            if (quartos.empty()) {
                cout << "\nNenhum quarto cadastrado. Cadastre um quarto antes de criar reservas.\n";
            } else {
                char jaCadastrado;
                cout << "\nHóspede já cadastrado? (s/n): ";
                cin >> jaCadastrado;
                limparEntrada();

                Hospede hospedeEscolhido(0, "", "", "", "");
                bool hospedeValido = false;

                if (jaCadastrado == 's' || jaCadastrado == 'S') {
                    int id;
                    cout << "Informe o ID do hóspede: ";
                    cin >> id;
                    limparEntrada();

                    for (auto &h : hospedes) {
                        if (h.HCodigo() == id) {
                            hospedeEscolhido = h;
                            hospedeValido = true;
                            break;
                        }
                    }

                    if (!hospedeValido) {
                        cout << "Hóspede não encontrado.\n";
                    }
                } else {
                    string nome, rg, telefone, email;
                    cout << "\n\tCadastro de novo hóspede\n";
                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "RG: ";
                    getline(cin, rg);
                    cout << "Telefone: ";
                    getline(cin, telefone);
                    cout << "Email: ";
                    getline(cin, email);

                    int idHospede = proximoHospedeId++;
                    Hospede novoHospede(idHospede, nome, rg, telefone, email);
                    hospedes.push_back(novoHospede);
                    hospedeEscolhido = novoHospede;
                    hospedeValido = true;

                    cout << "Hóspede cadastrado com ID: " << idHospede << endl;
                }

                if (!hospedeValido) {
                    // algo deu errado na seleção/criação
                    // volta ao menu
                } else {
                    cout << "\nQuartos disponíveis:\n";
                    for (auto &q : quartos) {
                        cout << "Quarto " << q.QNumero()
                             << " - Tipo: " << q.QTipo()
                             << " - Preço: R$" << q.QPreco()
                             << " - Status: " << (q.estaOcupado() ? "OCUPADO" : "DISPONÍVEL")
                             << endl;
                    }

                    int numeroQuarto;
                    cout << "\nDigite o número do quarto para a reserva: ";
                    cin >> numeroQuarto;
                    limparEntrada();

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
                        string checkIn, checkOut;
                        cout << "Data de check-in: ";
                        getline(cin, checkIn);
                        cout << "Data de check-out: ";
                        getline(cin, checkOut);

                        int numeroReserva = proximaReserva++;
                        quartoSelecionado->ocupar();
                        Reserva novaReserva(numeroReserva, hospedeEscolhido, *quartoSelecionado, checkIn, checkOut);
                        reservas.push_back(novaReserva);

                        cout << "\nReserva cadastrada com sucesso!" << endl;
                        cout << "Número da reserva: " << numeroReserva << endl;
                        cout << "Quarto: " << quartoSelecionado->QNumero() << endl;
                    }
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
