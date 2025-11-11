#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include "Hospede.h"
#include "Quartos.h"

/**
 * \class Reserva
 * \brief Representa uma reserva de hospedagem no sistema do hotel.
 * \details Contém informações sobre o número da reserva, hóspede associado, quarto reservado,
 *          datas de check-in e check-out e o status atual da reserva.
 */

class Reserva {
private:
    int numeroReserva;          /**< Número identificador da reserva. */
    Hospede hospede;            /**< Hóspede associado à reserva. */
    Quartos quarto;             /**< Quarto reservado pelo hóspede. */
    std::string checkIn;        /**< Data de entrada (check-in) da reserva. */
    std::string checkOut;       /**< Data de saída (check-out) da reserva. */
    std::string status;         /**< Status atual da reserva (ex: ativa, concluída, cancelada). */

public:
/**
     * \brief Construtor que inicializa uma reserva com os dados principais.
     * \param numeroReserva Número identificador da reserva.
     * \param hospede Objeto do tipo Hospede relacionado à reserva.
     * \param quarto Objeto do tipo Quartos associado à reserva.
     * \param checkIn Data de entrada (formato: dd/mm/aaaa).
     * \param checkOut Data de saída (formato: dd/mm/aaaa).
     */
    Reserva(int numeroReserva, Hospede hospede, Quartos quarto, std::string checkIn, std::string checkOut);

    /**
     * \brief Retorna o número identificador da reserva.
     * \return Número da reserva.
     */
   
    int RNumeroReserva() const;

    /**
     * \brief Retorna o hóspede associado à reserva.
     * \return Objeto do tipo Hospede.
     */
    Hospede RHospede() const;

    /**
     * \brief Retorna o quarto reservado.
     * \return Objeto do tipo Quartos.
     */
    Quartos RQuarto() const;

    /**
     * \brief Retorna a data de check-in da reserva.
     * \return Data de entrada como string.
     */
    std::string RCheckIn() const;

    /**
     * \brief Retorna a data de check-out da reserva.
     * \return Data de saída como string.
     */
    std::string RCheckOut() const;
    /**
     * \brief Retorna o status atual da reserva.
     * \return Status da reserva (ativa, concluída ou cancelada).
     */
    std::string RStatus() const;
<<<<<<< HEAD
	void setStatus(const std::string& novoStatus);
    const std::string& getStatus() const;
=======
    
    /**
     * \brief Define ou altera o status da reserva.
     * \param novoStatus Novo status a ser atribuído.
     */

    void setStatus(const std::string& novoStatus);
>>>>>>> 4fbd88908279260944f02bae50c4da46e1ac975e
};

#endif
