#include <iostream>
#include <stdexcept>
#include <cctype>
#include "Reserva.h"

<<<<<<< HEAD
Reserva::Reserva(int numeroReserva,
                 Hospede h,
                 Quartos q,
                 std::string checkIn,
                 std::string checkOut)
    : numeroReserva(numeroReserva),
      hospede(h),
      quarto(q),
      checkIn(checkIn),
      checkOut(checkOut),
      status("ATIVA") {}
=======
using namespace std; 

static bool dataValida(const std::string& data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/')
        return false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (i != 2 && i != 5 && !isdigit(data[i]))
            return false;
    }
    return true;
}
>>>>>>> 09e0472 (Atualizações programação defensiva)



Reserva::Reserva(int numero, Hospede h, Quartos q, std::string checkIn, std::string checkOut)
    : numeroReserva(numero), hospede(h), quarto(q), infoCheckIn(checkIn), infoCheckOut(checkOut), status("ATIVA") 
{
    if (numeroReserva <= 0) throw std::invalid_argument("Erro: número da reserva deve ser positivo.");
    if (!dataValida(checkIn) || !dataValida(checkOut))
        throw std::invalid_argument("Erro: formato de data inválido (use dd/mm/aaaa).");
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

std::string Reserva::RCheckIn() const {
    return checkIn;
}

std::string Reserva::RCheckOut() const {
    return checkOut;
}

std::string Reserva::RStatus() const {
    return status;
}

void Reserva::setStatus(const std::string& novoStatus) {
    status = novoStatus;
}


