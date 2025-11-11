#include <iostream>
#include <stdexcept>
#include <cctype>
#include "Reserva.h"

using namespace std; 


/**
 * \brief Função auxiliar que valida o formato de uma data.
 * \details Verifica se a data está no formato "dd/mm/aaaa" e contém apenas números e barras.
 * \param data String representando a data.
 * \return true se a data estiver em formato válido, false caso contrário.
 */
static bool dataValida(const std::string& data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/')
        return false;
    for (size_t i = 0; i < data.size(); ++i) {
        if (i != 2 && i != 5 && !isdigit(data[i]))
            return false;
    }
    return true;
}

/**
 * \brief Construtor da classe Reserva.
 * \details Inicializa uma nova reserva com número, hóspede, quarto e datas de check-in e check-out.
 *          O status inicial é definido como "ATIVA". Realiza validações básicas dos dados.
 * \param numero Número identificador da reserva.
 * \param h Objeto do tipo Hospede associado à reserva.
 * \param q Objeto do tipo Quartos reservado.
 * \param checkIn Data de entrada (formato dd/mm/aaaa).
 * \param checkOut Data de saída (formato dd/mm/aaaa).
 * \throw std::invalid_argument Caso o número da reserva seja inválido ou as datas estejam em formato incorreto.
 */
Reserva::Reserva(int numero, Hospede h, Quartos q, std::string checkIn, std::string checkOut)
    : numeroReserva(numero), hospede(h), quarto(q), checkIn(checkIn), checkOut(checkOut), status("ATIVA") 
{
    if (numeroReserva <= 0) throw std::invalid_argument("Erro: número da reserva deve ser positivo.");
    if (!dataValida(checkIn) || !dataValida(checkOut))
        throw std::invalid_argument("Erro: formato de data inválido (use dd/mm/aaaa).");
}
   
/**
 * \brief Retorna o número identificador da reserva.
 * \return Número da reserva.
 */
int Reserva::RNumeroReserva() const {
    return numeroReserva;
}

/**
 * \brief Retorna o hóspede associado à reserva.
 * \return Objeto do tipo Hospede.
 */
Hospede Reserva::RHospede() const {
    return hospede;
}

/**
 * \brief Retorna o quarto reservado.
 * \return Objeto do tipo Quartos.
 */
Quartos Reserva::RQuarto() const {
    return quarto;
}

/**
 * \brief Retorna a data de check-in da reserva.
 * \return Data de entrada (string no formato dd/mm/aaaa).
 */
std::string Reserva::RCheckIn() const {
    return checkIn;
}

/**
 * \brief Retorna a data de check-out da reserva.
 * \return Data de saída (string no formato dd/mm/aaaa).
 */
std::string Reserva::RCheckOut() const {
    return checkOut;
}

/**
 * \brief Retorna o status atual da reserva.
 * \return Status da reserva (ex: "ATIVA", "CONCLUÍDA" ou "CANCELADA").
 */
std::string Reserva::RStatus() const {
    return status;
}

<<<<<<< HEAD
void Reserva::setStatus(const std::string& novoStatus) {
    status = novoStatus;
}

const std::string& Reserva::getStatus() const {
    return status;
=======
/**
 * \brief Define um novo status para a reserva.
 * \param novoStatus Novo status a ser atribuído (ex: "CONCLUÍDA" ou "CANCELADA").
 */
void Reserva::setStatus(const std::string& novoStatus) {
    status = novoStatus;

>>>>>>> 4fbd88908279260944f02bae50c4da46e1ac975e
}
