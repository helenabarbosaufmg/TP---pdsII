#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <string>
#include "Hospede.h"
#include "Quartos.h"
#include "Reserva.h"

/**
 * \class Sistema
 * \brief Gerencia o funcionamento geral do hotel.
 * \details Esta classe centraliza o controle de hóspedes, quartos e reservas,
 *          permitindo o cadastro, busca, listagem e atualização do status das entidades.
 */
class Sistema {
private:
    std::vector<Hospede> hospedes;          
    std::vector<Quartos> quartos;           
    std::vector<Reserva> reservas;          

    bool hospedeCadastrado(int codigo) const;
    int posicaoHospede(int codigo) const;
    bool quartoCadastrado(int numero) const;
    int posicaoQuarto(int numero) const;
    bool reservaSobreposta(int numeroQuarto,
                           const std::string& checkIn,
                           const std::string& checkOut) const;

public:
    Sistema();

    // Hóspedes
    void cadastrarHospede(Hospede h);
    const std::vector<Hospede>& listarHospedes() const;
    const Hospede* buscarHospedePorCodigo(int codigo) const;

    // Quartos
    void cadastrarQuarto(Quartos q);
    const std::vector<Quartos>& listarQuartos() const;
    const Quartos* buscarQuartoPorNumero(int numero) const;
    void listarStatusQuartos() const;
    void ocuparQuarto(int numeroQuarto);
    void liberarQuarto(int numeroQuarto);

    // Reservas
    void criarReserva(Reserva r);
    const std::vector<Reserva>& listarReservas() const;
    const Reserva* buscarReservaPorNumero(int numeroReserva) const;
    void mostrarHospedePorReserva(int numeroReserva) const;
    void mostrarDadosReservaCompleta(int numeroReserva) const;

    // Check-in / Check-out / Cancelamento
    void fazerCheckIn(int numeroReserva);
    void fazerCheckOut(int numeroReserva);
    void cancelarReserva(int numeroReserva);
};

#endif
