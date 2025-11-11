#include "Reserva.h"

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
      status("ATIVA")
{
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

const std::string& Reserva::getStatus() const {
    return status;
}
