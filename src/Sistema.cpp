#include <iostream>
#include "Sistema.h"
#include "Reserva.h"
using namespace std;

Sistema::Sistema(){}
bool Sistema::hospedeCadastrado(int codigo) const {
    for (const Hospede& h : hospedes) {
        if (h.HCodigo() == codigo) {
            return true;
        }
    }
    return false;
}


int Sistema::posicaoHospede(int codigo) const {
    for (std::size_t i = 0; i < hospedes.size(); ++i) {
        if (hospedes[i].HCodigo() == codigo) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool Sistema::quartoCadastrado(int numero) const {
    for (const Quartos& q : quartos) {
        if (q.QNumero() == numero) {
            return true;
        }
    }
    return false;
}

int Sistema::posicaoQuarto(int numero) const {
    for (std::size_t i = 0; i < quartos.size(); ++i) {
        if (quartos[i].QNumero() == numero) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool Sistema::reservaSobreposta(int numeroQuarto,
                                const string& checkIn,
                                const string& checkOut) const {
    for (const Reserva& r : reservas) {
        if (r.RQuarto().QNumero() == numeroQuarto) {

            const string& inExistente  = r.RCheckIn();
            const string& outExistente = r.RCheckOut();

            bool semConflito = (checkOut <= inExistente) || (checkIn >= outExistente);

            if (!semConflito) {
                return true;
            }
        }
    }
    return false; 
}

// -------------------------------------------------
// Hóspedes
// -------------------------------------------------

void Sistema::cadastrarHospede(Hospede h) {
    if (hospedeCadastrado(h.HCodigo())) {
        cout << "Erro: ja existe hospede com esse codigo." << endl;
        return;
    }
    for (char c : h.HRG()) {
        if (!isdigit(c)) {
            cout << "Erro: RG deve conter apenas numeros." << endl;
            return;
        }
    }

    for (char c : h.HTelefone()) {
        if (!isdigit(c)) {
            cout << "Erro: telefone deve conter apenas numeros." << endl;
            return;
        }
    }

    hospedes.push_back(h);
    cout << "Hospede cadastrado com sucesso." << endl;
}

const vector<Hospede>& Sistema::listarHospedes() const {
    return hospedes;
}

const Hospede* Sistema::buscarHospedePorCodigo(int codigo) const {
    for (const Hospede& h : hospedes) {
        if (h.HCodigo() == codigo) {
            return &h;
        }
    }
    return nullptr;
}

// -------------------------------------------------
// Quartos
// -------------------------------------------------

void Sistema::cadastrarQuarto(Quartos q) {
    if (quartoCadastrado(q.QNumero())) {
        cout << "Erro: ja existe quarto com esse numero." << endl;
        return;
    }
    string tipo = q.QTipo();
    for (char& c : tipo) c = toupper(c);
    if (tipo != "Solteiro" && tipo != "Casal" && tipo != "Luxo") {
        cout << "Erro: tipo de quarto invalido. Use 'Solteiro', 'Casal' ou 'Luxo'." << endl;
        return;
    }

    if (q.QPreco() <= 0) {
        cout << "Erro: preco do quarto deve ser um valor positivo." << endl;
        return;
    }


    quartos.push_back(q);
    cout << "Quarto cadastrado com sucesso!" << endl;
}

const vector<Quartos>& Sistema::listarQuartos() const {
    return quartos;
}

const Quartos* Sistema::buscarQuartoPorNumero(int numero) const {
    for (const Quartos& q : quartos) {
        if (q.QNumero() == numero) {
            return &q;
        }
    }
    return nullptr;
}
void Sistema::listarStatusQuartos() const {
    cout << "\nStatus de Reservas (Lista de Quartos)\n";

    if (quartos.empty()) {
        cout << "Nenhum quarto cadastrado.\n";
        return;
    }

    for (const Quartos& q : quartos) {
        cout << "Quarto " << q.QNumero()
             << " - Tipo: " << q.QTipo()
             << " - Preco: R$ " << q.QPreco()
             << " - Status: " << (q.estaOcupado() ? "OCUPADO" : "DISPONIVEL")
             << endl;
    }
}

void Sistema::ocuparQuarto(int numeroQuarto) {
    int pos = posicaoQuarto(numeroQuarto);
    if (pos == -1) {
        cout << "Quarto nao encontrado.\n";
        return;
    }

    if (quartos[pos].estaOcupado()) {
        cout << "Quarto " << numeroQuarto << " ja esta OCUPADO.\n";
        return;
    }

    quartos[pos].ocupar();
    cout << "Quarto " << numeroQuarto << " agora esta OCUPADO.\n";
}

void Sistema::liberarQuarto(int numeroQuarto) {
    int pos = posicaoQuarto(numeroQuarto);
    if (pos == -1) {
        cout << "Quarto nao encontrado.\n";
        return;
    }

    if (!quartos[pos].estaOcupado()) {
        cout << "Quarto " << numeroQuarto << " ja esta DISPONIVEL.\n";
        return;
    }

    quartos[pos].liberar();
    cout << "Quarto " << numeroQuarto << " agora esta DISPONIVEL.\n";
}

// -------------------------------------------------
// Reservas
// -------------------------------------------------

void Sistema::criarReserva(Reserva r) {
    int codigoHospede = r.RHospede().HCodigo();
    if (!hospedeCadastrado(codigoHospede)) {
        cout << "Erro: hospede nao esta cadastrado." << endl;
        return;
    }

    int numeroQuarto = r.RQuarto().QNumero();
    int posQuarto = posicaoQuarto(numeroQuarto);
    if (posQuarto == -1) {
        cout << "Erro: quarto nao esta cadastrado." << endl;
        return;
    }

    string checkIn = r.RCheckIn();
    string checkOut = r.RCheckOut();
    if (checkIn.size() != 10 || checkOut.size() != 10 || checkIn[2] != '/' || checkIn[5] != '/' ||
        checkOut[2] != '/' || checkOut[5] != '/') {
        cout << "Erro: formato de data invalido (use dd/mm/aaaa)." << endl;
        return;
    }


    if (reservaSobreposta(numeroQuarto, r.RCheckIn(), r.RCheckOut())) {
        cout << "Erro: ja existe reserva nesse periodo para este quarto." << endl;
        return;
    }

    reservas.push_back(r);
    reservas.back().setStatus("Agendada");
    quartos[posQuarto].ocupar();

    cout << "Reserva criada com sucesso!" << endl;
}

const vector<Reserva>& Sistema::listarReservas() const {
    return reservas;
}

const Reserva* Sistema::buscarReservaPorNumero(int numeroReserva) const {
    for (const Reserva& r : reservas) {
        if (r.RNumeroReserva() == numeroReserva) {
            return &r;
        }
    }
    return nullptr;
}

// Opcao 2: pesquisar hospede pelo numero da reserva
void Sistema::mostrarHospedePorReserva(int numeroReserva) const {
    const Reserva* r = buscarReservaPorNumero(numeroReserva);
    if (!r) {
        cout << "Hospede nao encontrado para este numero de reserva." << endl;
        return;
    }

    Hospede h = r->RHospede();

    cout << "\nHospede encontrado:\n";
    cout << "Numero da reserva: " << r->RNumeroReserva() << endl;
    cout << "Nome: " << h.HNome() << endl;
    cout << "RG: " << h.HRG() << endl;
    cout << "Telefone: " << h.HTelefone() << endl;
    cout << "Email: " << h.HEmail() << endl;
}

// Opcao 3: pesquisar dados completos da reserva
void Sistema::mostrarDadosReservaCompleta(int numeroReserva) const {
    const Reserva* r = buscarReservaPorNumero(numeroReserva);
    if (!r) {
        cout << "Reserva nao encontrada." << endl;
        return;
    }

    cout << "\nDados da Reserva\n";
    cout << "Numero da reserva: " << r->RNumeroReserva() << endl;
    cout << "Status: " << r->RStatus() << endl;
    cout << "Check-in: " << r->RCheckIn() << endl;
    cout << "Check-out: " << r->RCheckOut() << endl;

    cout << "\nHospede:\n";
    Hospede h = r->RHospede();
    cout << "Nome: " << h.HNome() << endl;
    cout << "RG: " << h.HRG() << endl;
    cout << "Telefone: " << h.HTelefone() << endl;
    cout << "Email: " << h.HEmail() << endl;

    cout << "\nQuarto:\n";
    Quartos q = r->RQuarto();
    cout << "Numero: " << q.QNumero() << endl;
    cout << "Tipo: " << q.QTipo() << endl;
    cout << "Preco diaria: R$ " << q.QPreco() << endl;
}

// -------------------------------------------------
// Check-in, check-out e cancelamento
// -------------------------------------------------

void Sistema::fazerCheckIn(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.RNumeroReserva() == numeroReserva) {
            r.setStatus("Em andamento");
            cout << "Check-in realizado com sucesso." << endl;
            return;
        }
    }
    cout << "Reserva nao encontrada." << endl;
}

void Sistema::fazerCheckOut(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.RNumeroReserva() == numeroReserva) {
            r.setStatus("Concluida");

            int numeroQuarto = r.RQuarto().QNumero();
            int posQuarto = posicaoQuarto(numeroQuarto);
            if (posQuarto != -1) {
                quartos[posQuarto].liberar();
            }

            cout << "Check-out realizado com sucesso." << endl;
            return;
        }
    }
    cout << "Reserva nao encontrada." << endl;
}

void Sistema::cancelarReserva(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.RNumeroReserva() == numeroReserva) {
            r.setStatus("Cancelada");

            int numeroQuarto = r.RQuarto().QNumero();
            int posQuarto = posicaoQuarto(numeroQuarto);
            if (posQuarto != -1) {
                quartos[posQuarto].liberar();
            }

            cout << "Reserva cancelada." << endl;
            return;
        }
    }
    cout << "Reserva nao encontrada." << endl;
}