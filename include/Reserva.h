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
    std::string infoCheckIn;
    std::string infoCheckOut;
    std::string status;
    double valorFinal;

public:
    Reserva(int numeroReserva, Hospede hospede, Quartos quarto, std::string checkIn, std::string checkOut);

    int RNumeroReserva() const;
    Hospede RHospede() const;
    Quartos RQuarto() const;
    std::string RCheckIn() const;
    std::string RCheckOut() const;
    std::string StatusFinal() const;
    double RValorFinal() const;

    void Status(std::string novoStatus);
    void setValorFinal(double valor);
};

#endif

 
