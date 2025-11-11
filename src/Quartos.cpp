#include <iostream>
#include <stdexcept>
#include "Quartos.h"


/**
 * \brief Construtor que inicializa um quarto com número, tipo e preço.
 * \details Realiza validações para garantir que o número e o preço sejam positivos
 *          e que o tipo seja um dos valores válidos: "Solteiro", "Casal" ou "Luxo".
 * \param numero Número identificador do quarto.
 * \param tipo Tipo do quarto (ex: "Solteiro", "Casal" ou "Luxo").
 * \param preco Valor da diária do quarto.
 * \throw std::invalid_argument Caso algum dado seja inválido.
 */
Quartos::Quartos(int numero, std::string tipo, double preco)
    : numero(numero), tipo(tipo), preco(preco), ocupado(false) {
         if (numero <= 0) throw std::invalid_argument("Erro: número do quarto deve ser positivo.");
    if (tipo != "Solteiro" && tipo != "Casal" && tipo != "Luxo")
        throw std::invalid_argument("Erro: tipo inválido. Use Solteiro, Casal ou Luxo.");
    if (preco <= 0)
        throw std::invalid_argument("Erro: preço deve ser maior que zero.");
}
    
/**
 * \brief Retorna o número identificador do quarto.
 * \return Número do quarto.
 */
int Quartos::QNumero() const {
    return numero;
}

/**
 * \brief Retorna o tipo do quarto.
 * \return Tipo do quarto (ex: "Solteiro", "Casal" ou "Luxo").
 */
std::string Quartos::QTipo() const {
    return tipo;
}

/**
 * \brief Retorna o preço da diária do quarto.
 * \return Valor da diária.
 */
double Quartos::QPreco() const {
    return preco;
}

/**
 * \brief Verifica se o quarto está ocupado.
 * \return true se estiver ocupado, false caso contrário.
 */
bool Quartos::estaOcupado() const {
    return ocupado;
}

/**
 * \brief Define o quarto como ocupado.
 */
void Quartos::ocupar() {
    ocupado = true;
}

/**
 * \brief Libera o quarto, marcando-o como disponível.
 */
void Quartos::liberar() {
    ocupado = false;
}