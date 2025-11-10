#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include "Hospede.h"
#include "Quartos.h"

class Reserva {
private:
    int numeroReserva;
    Hospede hospede;
    Quartos quarto;
    std::string checkIn;
    std::string checkOut;
    std::string status;

public:
    Reserva(int numeroReserva, Hospede hospede, Quartos quarto, std::string checkIn, std::string checkOut);

    int RNumeroReserva() const;
    Hospede RHospede() const;
    Quartos RQuarto() const;
    std::string RCheckIn() const;
    std::string RCheckOut() const;
    std::string RStatus() const;
};

#endif
