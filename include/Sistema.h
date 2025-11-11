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
    std::vector<Hospede> hospedes;          /**< Lista de hóspedes cadastrados no sistema. */
    std::vector<Quartos> quartos;           /**< Lista de quartos cadastrados no sistema. */
    std::vector<Reserva> reservas;          /**< Lista de reservas registradas no sistema. */

    /**
     * \brief Verifica se um hóspede está cadastrado com base no código.
     * \param codigo Código identificador do hóspede.
     * \return true se o hóspede estiver cadastrado, false caso contrário.
     */
    bool hospedeCadastrado(int codigo) const;

    /**
     * \brief Retorna a posição do hóspede no vetor com base no código.
     * \param codigo Código identificador do hóspede.
     * \return Índice do hóspede no vetor ou -1 se não encontrado.
     */
    int  posicaoHospede(int codigo) const;

    /**
     * \brief Verifica se um quarto está cadastrado com base no número.
     * \param numero Número identificador do quarto.
     * \return true se o quarto estiver cadastrado, false caso contrário.
     */
    bool quartoCadastrado(int numero) const;

    /**
     * \brief Retorna a posição do quarto no vetor com base no número.
     * \param numero Número identificador do quarto.
     * \return Índice do quarto no vetor ou -1 se não encontrado.
     */
    int  posicaoQuarto(int numero) const;

     /**
     * \brief Verifica se já existe uma reserva sobreposta para o mesmo quarto e período.
     * \param numeroQuarto Número do quarto.
     * \param checkIn Data de check-in da nova reserva.
     * \param checkOut Data de check-out da nova reserva.
     * \return true se houver sobreposição de datas, false caso contrário.
     */
    bool reservaSobreposta(int numeroQuarto,
        const std::string& checkIn,
        const std::string& checkOut) const;

public:
/**
     * \brief Construtor padrão da classe Sistema.
     */
    Sistema();

    /**
     * \brief Cadastra um novo hóspede no sistema.
     * \param h Objeto do tipo Hospede a ser adicionado.
     */
    void cadastrarHospede(Hospede h);

    /**
     * \brief Retorna a lista de hóspedes cadastrados.
     * \return Vetor constante de hóspedes.
     */
    const std::vector<Hospede>& listarHospedes() const;

    /**
     * \brief Busca um hóspede pelo código identificador.
     * \param codigo Código do hóspede.
     * \return Ponteiro para o hóspede encontrado, ou nullptr se não existir.
     */
    const Hospede* buscarHospedePorCodigo(int codigo) const;

    /**
     * \brief Cadastra um novo quarto no sistema.
     * \param q Objeto do tipo Quartos a ser adicionado.
     */
    void cadastrarQuarto(Quartos q);

    /**
     * \brief Retorna a lista de quartos cadastrados.
     * \return Vetor constante de quartos.
     */
    const std::vector<Quartos>& listarQuartos() const;

    /**
     * \brief Busca um quarto pelo número.
     * \param numero Número identificador do quarto.
     * \return Ponteiro para o quarto encontrado, ou nullptr se não existir.
     */
    const Quartos* buscarQuartoPorNumero(int numero) const;

    /**
     * \brief Exibe na tela o status (ocupado/disponível) de todos os quartos.
     */
    void listarStatusQuartos() const;

    /**
     * \brief Define um quarto como ocupado.
     * \param numeroQuarto Número do quarto a ser ocupado.
     */
    void ocuparQuarto(int numeroQuarto);

    /**
     * \brief Libera um quarto, tornando-o disponível.
     * \param numeroQuarto Número do quarto a ser liberado.
     */
    void liberarQuarto(int numeroQuarto);
    
    /**
     * \brief Cria uma nova reserva no sistema.
     * \param r Objeto do tipo Reserva a ser adicionado.
     */
    void criarReserva(Reserva r);

    /**
     * \brief Retorna a lista de reservas registradas.
     * \return Vetor constante de reservas.
     */
    const std::vector<Reserva>& listarReservas() const;

    /**
     * \brief Busca uma reserva pelo número identificador.
     * \param numeroReserva Número da reserva.
     * \return Ponteiro para a reserva encontrada, ou nullptr se não existir.
     */
    const Reserva* buscarReservaPorNumero(int numeroReserva) const;

    /**
     * \brief Mostra na tela os dados do hóspede associado a uma reserva.
     * \param numeroReserva Número da reserva.
     */
    void mostrarHospedePorReserva(int numeroReserva) const;

    /**
     * \brief Exibe todas as informações completas de uma reserva específica.
     * \param numeroReserva Número da reserva.
     */
    void mostrarDadosReservaCompleta(int numeroReserva) const;

    /**
     * \brief Realiza o check-in de uma reserva, alterando o status e ocupando o quarto.
     * \param numeroReserva Número da reserva a ser atualizada.
     */
    void fazerCheckIn(int numeroReserva);

    /**
     * \brief Realiza o check-out de uma reserva, liberando o quarto.
     * \param numeroReserva Número da reserva a ser atualizada.
     */
    void fazerCheckOut(int numeroReserva);

    /**
     * \brief Cancela uma reserva existente no sistema.
     * \param numeroReserva Número da reserva a ser cancelada.
     */
    void cancelarReserva(int numeroReserva);
};

#endif
