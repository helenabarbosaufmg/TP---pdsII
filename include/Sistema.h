#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Hospede.h"
#include "Quartos.h"
#include "Reserva.h"

class Sistema {
private:
    std::vector<Hospede> hospedes;
    std::vector<Quartos> quartos;
    std::vector<Reserva> reservas;

    bool hospedeCadastrado(int codigo) const;
    int  posicaoHospede(int codigo) const;

    bool quartoCadastrado(int numero) const;
    int  posicaoQuarto(int numero) const;

    bool reservaSobreposta(int numeroQuarto,
        const std::string& checkIn,
        const std::string& checkOut) const;

public:
    Sistema(); 

    void cadastrarHospede(const Hospede& h);
    const std::vector<Hospede>& listarHospedes() const;
    const Hospede* buscarHospedePorCodigo (int codigo) const;
     

    void cadastrarQuarto(const Quartos& q);
    const std::vector<Quartos>& listarQuartos() const;
    const Quartos* buscarQuartoPorNumero(int numero) const;
    void listarStatusQuartos() const;
    void ocuparQuarto(int numeroQuarto);
    void liberarQuarto(int numeroQuarto);

    void criarReserva(const Reserva& r);
    const std::vector<Reserva>& listarReservas() const;
    const Reserva* buscarReservaPorNumero(int numeroReserva) const;
    void mostrarHospedePorReserva(int numeroReserva) const;
    void mostrarDadosReservaCompleta(int numeroReserva) const;

    void fazerCheckIn(int numeroReserva);
    void fazerCheckOut(int numeroReserva);
    void cancelarReserva(int numeroReserva);
};

#endif
 
