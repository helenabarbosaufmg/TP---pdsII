#ifndef QUARTOS_H
#define QUARTOS_H

#include <string>

/**
 * \class Quartos
 * \brief Representa um quarto do hotel.
 * \details Armazena as informações do quarto, como número, tipo, preço e status de ocupação.
 */

class Quartos {
private:
    int numero;             /**< Número identificador do quarto. */
    std::string tipo;       /**< Tipo do quarto (ex: solteiro, casal, luxo). */
    double preco;           /**< Preço da diária do quarto. */
    bool ocupado;           /**< Indica se o quarto está ocupado (true) ou disponível (false). */

public:
/**
     * \brief Construtor padrão da classe Quartos.
     * \details Inicializa o quarto com valores padrão: número 0, tipo "Indefinido",
     *          preço 0.0 e status desocupado.
     */
    Quartos() : numero(0), tipo("Indefinido"), preco(0.0), ocupado(false) {}

    /**
     * \brief Construtor que inicializa um quarto com valores específicos.
     * \param numero Número identificador do quarto.
     * \param tipo Tipo do quarto (ex: simples, duplo, suíte).
     * \param preco Preço da diária do quarto.
     */

    Quartos(int numero, std::string tipo, double preco);

    /**
     * \brief Retorna o número identificador do quarto.
     * \return Número do quarto.
     */

    int QNumero() const;
     /**
     * \brief Retorna o tipo do quarto.
     * \return Tipo do quarto (string).
     */

    std::string QTipo() const;

    /**
     * \brief Retorna o preço da diária do quarto.
     * \return Valor da diária.
     */
    double QPreco() const;
    /**
     * \brief Verifica se o quarto está ocupado.
     * \return true se o quarto estiver ocupado, false caso contrário.
     */

    bool estaOcupado() const;
    /**
     * \brief Define o status do quarto como ocupado.
     */

    void ocupar();
    /**
     * \brief Libera o quarto, definindo o status como disponível.
     */

    void liberar();
};

 #endif
