/**
 * \file main.cpp
 * \brief Ponto de entrada do sistema de gerenciamento de hotel.
 * \details Este programa permite cadastrar quartos, hóspedes e reservas,
 *          além de consultar e atualizar o status de quartos e reservas
 *          por meio de um menu interativo no console.
 */

#include <iostream>
#include <string>
#include <limits>
#include "Hospede.h"
#include "Quartos.h"
#include "Reserva.h"
#include "Sistema.h"

using namespace std;

/**
 * \brief Função principal do sistema de hotel.
 * \details Cria um objeto Sistema e apresenta um menu de operações para o usuário,
 *          como cadastro de quartos e hóspedes, criação de reservas, busca de reservas,
 *          listagem de status de quartos, ocupação e liberação de quartos.
 * \return 0 quando o programa é encerrado com sucesso.
 */
int main() {
    Sistema sistema;
    int opcao;
    int proximaReserva = 1;

    /**
     * \brief Função lambda para limpar o buffer de entrada.
     * \details Descarta caracteres remanescentes no buffer de std::cin,
     *          evitando problemas com leituras subsequentes.
     */
    auto limparEntrada = []() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    do {
        cout << "\n\tSISTEMA DO HOTEL" << endl;
        cout << "1 - Cadastrar novo quarto" << endl;
        cout << "2 - Cadastrar novo hóspede no quarto previamente cadastrado" << endl;
        cout << "3 - Pesquisar número de reserva" << endl;
        cout << "4 - Cadastrar nova reserva de hóspede já cadastrado no sistema" << endl;
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
            sistema.cadastrarQuarto(novo);
        }

        // 2 - Cadastrar novo hospede no quarto previamente cadastrado
        else if (opcao == 2) {
            const auto& quartos = sistema.listarQuartos();
            if (quartos.empty()) {
                cout << "\nNenhum quarto cadastrado. Cadastre um quarto antes.\n";
            } else {
                cout << "\nQuartos cadastrados:\n";
                for (const auto& q : quartos) {
                    cout << "Quarto " << q.QNumero()
                         << " - Tipo: " << q.QTipo()
                         << " - Preço: R$ " << q.QPreco()
                         << " - Status: " << (q.estaOcupado() ? "OCUPADO" : "DISPONÍVEL")
                         << endl;
                }

                int numeroQuarto;
                cout << "\nDigite o número do quarto para este hóspede: ";
                cin >> numeroQuarto;
                limparEntrada();

                const Quartos* quartoSelecionado = sistema.buscarQuartoPorNumero(numeroQuarto);
                if (!quartoSelecionado) {
                    cout << "Quarto não encontrado.\n";
                } else if (quartoSelecionado->estaOcupado()) {
                    cout << "Quarto já esta ocupado. Não é possível alocar novo hóspede.\n";
                } else {
                    string nome, rg, telefone, email;
                    string checkIn, checkOut;

                    cout << "\n\tDados do Hóspede\n";
                    int codigo = proximaReserva;
                    cout << "Número de reserva: ";
                    cout << codigo << endl;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "RG: ";
                    getline(cin, rg);
                    cout << "Telefone: ";
                    getline(cin, telefone);
                    cout << "Email: ";
                    getline(cin, email);

                    Hospede novoHospede(codigo, nome, rg, telefone, email);
                    sistema.cadastrarHospede(novoHospede);

                    cout << "Data de check-in: ";
                    getline(cin, checkIn);
                    cout << "Data de check-out: ";
                    getline(cin, checkOut);

                    Reserva novaReserva(proximaReserva++, novoHospede, *quartoSelecionado,
                                        checkIn, checkOut);
                    sistema.criarReserva(novaReserva);
                }
            }
        }

        // 3 - Pesquisar numero de reserva
        else if (opcao == 3) {
            int numeroReservaBusca;
            cout << "\nDigite o número da reserva: ";
            cin >> numeroReservaBusca;
            limparEntrada();

            sistema.mostrarDadosReservaCompleta(numeroReservaBusca);
        }

    // 4 - Cadastrar nova reserva de hospede ja cadastrado no sistema
else if (opcao == 4) {
    if (sistema.listarQuartos().empty() || sistema.listarHospedes().empty()) {
        cout << "\nÉ preciso ter ao menos um hóspede e um quarto cadastrados.\n";
    } else {
        int codigoHospede;
        cout << "Númedo de reserva do hospede (ja cadastrado): ";
        cin >> codigoHospede;
        limparEntrada();

        const Hospede* h = sistema.buscarHospedePorCodigo(codigoHospede);

        if (!h) {
            cout << "Hóspede não encontrado. Reserva não cadastrada.\n";
        } else {
            // Exibe os dados do hóspede
            cout << "\nDados do Hóspede:\n";
            cout << "Número de reserva: "   << h->HCodigo()   << endl;
            cout << "Nome: "     << h->HNome()     << endl;
            cout << "RG: "       << h->HRG()       << endl;
            cout << "Telefone: " << h->HTelefone() << endl;
            cout << "Email: "    << h->HEmail()    << endl;

            // Lista quartos cadastrados
            const auto& quartos = sistema.listarQuartos();
            cout << "\nQuartos cadastrados:\n";
            for (const auto& q : quartos) {
                cout << "Quarto " << q.QNumero()
                     << " - Tipo: " << q.QTipo()
                     << " - Preço: R$ " << q.QPreco()
                     << " - Status: " << (q.estaOcupado() ? "OCUPADO" : "DISPONÍVEL")
                     << endl;
            }

            int numeroQuarto;
            cout << "\nDigite o número do quarto para nova reserva (ou 0 para cadastrar um novo quarto): ";
            cin >> numeroQuarto;
            limparEntrada();

            const Quartos* q = nullptr;

            // Caso o usuário queira cadastrar um novo quarto
            if (numeroQuarto == 0) {
                int numeroNovo;
                string tipoNovo;
                double precoNovo;

                cout << "\n\tCadastro de Novo Quarto\n";
                cout << "Número do quarto: ";
                cin >> numeroNovo;
                limparEntrada();

                cout << "Tipo (ex: Solteiro, Casal, Luxo): ";
                getline(cin, tipoNovo);

                cout << "Preço da diária: ";
                cin >> precoNovo;
                limparEntrada();

                Quartos novoQuarto(numeroNovo, tipoNovo, precoNovo);
                sistema.cadastrarQuarto(novoQuarto);

                // Recupera o quarto recém-cadastrado
                q = sistema.buscarQuartoPorNumero(numeroNovo);
            } else {
                // Usa quarto existente
                q = sistema.buscarQuartoPorNumero(numeroQuarto);
            }

            if (!q) {
                cout << "Quarto não encontrado. Reserva não cadastrada.\n";
            } else if (q->estaOcupado()) {
                cout << "Quarto selecionado está ocupado. Reserva não cadastrada.\n";
            } else {
                string checkIn, checkOut;
                cout << "Data de check-in: ";
                getline(cin, checkIn);
                cout << "Data de check-out: ";
                getline(cin, checkOut);

                Reserva novaReserva(proximaReserva++, *h, *q, checkIn, checkOut);
                sistema.criarReserva(novaReserva);
            }
        }
    }
}

        // 5 - Status de reservas (listar quartos)
        else if (opcao == 5) {
            sistema.listarStatusQuartos();
        }

        // 6 - Ocupar quarto
        else if (opcao == 6) {
            int numero;
            cout << "\nNúmero do quarto a ocupar: ";
            cin >> numero;
            limparEntrada();
            sistema.ocuparQuarto(numero);
        }

        // 7 - Liberar quarto
        else if (opcao == 7) {
            int numero;
            cout << "\nNúmero do quarto a liberar: ";
            cin >> numero;
            limparEntrada();
            sistema.liberarQuarto(numero);
        }

        else if (opcao != 0) {
            cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    cout << "Saindo do sistema...\n";
    return 0;
}
