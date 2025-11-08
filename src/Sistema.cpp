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
        if (q.getNumero() == numero) {
            return true;
        }
    }
    return false;
}

int Sistema::posicaoQuarto(int numero) const {
    for (std::size_t i = 0; i < quartos.size(); ++i) {
        if (quartos[i].getNumero() == numero) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool Sistema::reservaSobreposta(int numeroQuarto,
                                const string& checkIn,
                                const string& checkOut) const {
    for (const Reserva& r : reservas) {
        if (r.getQuarto().getNumero() == numeroQuarto) {

            const string& inExistente  = r.getCheckIn();
            const string& outExistente = r.getCheckOut();

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

void Sistema::cadastrarHospede(const Hospede& h) {
    if (hospedeCadastrado(h.HCodigo())) {
        cout << "Erro: já existe hóspede com esse código." << endl;
        return;
    }

    hospedes.push_back(h);
    cout << "Hóspede cadastrado com sucesso." << endl;
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

void Sistema::cadastrarQuarto(const Quartos& q) {
    if (quartoCadastrado(q.getNumero())) {
        cout << "Erro: já existe quarto com esse número." << endl;
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
        if (q.getNumero() == numero) {
            return &q;
        }
    }
    return nullptr;
}

// -------------------------------------------------
// Reservas
// -------------------------------------------------

void Sistema::criarReserva(const Reserva& r) {
    int codigoHospede = r.getHospede().HCodigo();
    if (!hospedeCadastrado(codigoHospede)) {
        cout << "Erro: hóspede não está cadastrado." << endl;
        return;
    }

    int numeroQuarto = r.getQuarto().getNumero();
    int posQuarto = posicaoQuarto(numeroQuarto);
    if (posQuarto == -1) {
        cout << "Erro: quarto não está cadastrado." << endl;
        return;
    }

    if (reservaSobreposta(numeroQuarto, r.getCheckIn(), r.getCheckOut())) {
        cout << "Erro: já existe reserva nesse período para este quarto." << endl;
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

// -------------------------------------------------
// Check-in, check-out e cancelamento
// -------------------------------------------------

void Sistema::fazerCheckIn(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.getNumeroReserva() == numeroReserva) {
            r.setStatus("Em andamento");
            cout << "Check-in realizado com sucesso." << endl;
            return;
        }
    }
    cout << "Reserva não encontrada." << endl;
}

void Sistema::fazerCheckOut(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.getNumeroReserva() == numeroReserva) {
            r.setStatus("Concluída");

            int numeroQuarto = r.getQuarto().getNumero();
            int posQuarto = posicaoQuarto(numeroQuarto);
            if (posQuarto != -1) {
                quartos[posQuarto].liberar();
            }

            cout << "Check-out realizado com sucesso." << endl;
            return;
        }
    }
    cout << "Reserva não encontrada." << endl;
}

void Sistema::cancelarReserva(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.getNumeroReserva() == numeroReserva) {
            r.setStatus("Cancelada");

            int numeroQuarto = r.getQuarto().getNumero();
            int posQuarto = posicaoQuarto(numeroQuarto);
            if (posQuarto != -1) {
                quartos[posQuarto].liberar();
            }

            cout << "Reserva cancelada." << endl;
            return;
        }
    }
    cout << "Reserva não encontrada." << endl;
}