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
    std::string dataCheckIn;
    std::string dataCheckOut;
    std::string status;
    double valorFinal;

public:
    Reserva(int numeroReserva, Hospede hospede, Quartos quarto, std::string checkIn, std::string checkOut);

    int getNumeroReserva() const;
    Hospede getHospede() const;
    Quartos getQuarto() const;
    std::string getCheckIn() const;
    std::string getCheckOut() const;
    std::string getStatus() const;
    double getValorFinal() const;

    void setStatus(std::string novoStatus);
    void setValorFinal(double valor);
};

#endif

 
