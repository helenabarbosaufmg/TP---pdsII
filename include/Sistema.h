#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include "Hospede.h"
#include "Quartos.h"
#include "Reserva.h"

class Sistema {
private:
    std::vector<Hospede> hospedes;
    std::vector<Quartos> quartos;
    std::vector<Reserva> reservas;

public:
    Sistema(); 

    void cadastrarHospede(Hospede h);
    std::vector<Hospede> listarHospedes() const;

    void cadastrarQuarto(Quartos q);
    std::vector<Quartos> listarQuartos() const;

    void criarReserva(Reserva r);
    std::vector<Reserva> listarReservas() const;

    void fazerCheckIn(int numeroReserva);
    void fazerCheckOut(int numeroReserva);
    void cancelarReserva(int numeroReserva);
};

#endif
 
