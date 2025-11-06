#include <iostream>
#include "Reserva.h"

using namespace std; 

Reserva::Reserva(int numero, Hospede h, Quartos q, string checkIn, string checkOut) {
    numeroReserva = numero;
    hospede = h;
    quarto = q;
    infoCheckIn = checkIn;
    infoCheckOut = checkOut;
    status = "Pendente";
    valorFinal = 0.0;
}

int Reserva::RNumeroReserva() const {
    return numeroReserva;
}

Hospede Reserva::RHospede() const {
    return hospede;
}

Quartos Reserva::RQuarto() const {
    return quarto;
}

string Reserva::RCheckIn() const {
    return dataCheckIn;
}

string Reserva::RCheckOut() const {
    return dataCheckOut;
}

string Reserva::RStatus() const {
    return status;
}

double Reserva::RValorFinal() const {
    return valorFinal;
}

void Reserva::StatusFinal(string statusAtualizado) {
    status = statusAtualizado;
}

void Reserva::setValorFinal(double valor) {
    valorFinal = valor;
}
