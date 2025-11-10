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
<<<<<<< HEAD
    Reserva(int numeroReserva, Hospede hospede, Quartos quarto, const std::string checkIn, const std::string checkOut);

=======
    
    Reserva(int numeroReserva,
            Hospede h,
            Quartos q,
            std::string checkIn,
            std::string checkOut);

   
>>>>>>> main
    int RNumeroReserva() const;
    Hospede RHospede() const;
    Quartos RQuarto() const;
    std::string RCheckIn() const;
    std::string RCheckOut() const;
    std::string RStatus() const;
<<<<<<< HEAD
    double RValorFinal() const;

    void setStatus(const std::string& novoStatus);
    void setValorFinal(double valor);
=======
>>>>>>> main
};

#endif
