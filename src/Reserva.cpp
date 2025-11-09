#include "Reserva.h"

Reserva::Reserva(int numero,
                 Hospede h,
                 Quartos q,
                 std::string ci,
                 std::string co)
    : numeroReserva(numero), 
      hospede(h),
      quarto(q),             
      checkIn(ci),
      checkOut(co),
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
