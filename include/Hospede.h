#ifndef HOSPEDE_H
#define HOSPEDE_H

#include <iostream>

#include <iostream>
#include <string>
using namespace std;

/**
 * \class Hospede
 * \brief Representa um hóspede do sistema de hotel.
 * \details Armazena as informações básicas do hóspede, como nome, RG, telefone, e-mail e código identificador.
 */

class Hospede {
private:
    string nome;        /**< Nome do hóspede. */
    string rg;          /**< Documento de identificação (RG) do hóspede. */
    string telefone;    /**< Número de telefone do hóspede. */
    string email;       /**< Endereço de e-mail do hóspede. */
    int codigo;         /**< Código identificador único do hóspede. */

public:
 /**
     * \brief Construtor padrão da classe Hospede.
     */
    Hospede();

    /**
     * \brief Construtor que inicializa um hóspede com dados completos.
     * \param codigo Código identificador do hóspede.
     * \param nome Nome completo do hóspede.
     * \param rg Documento de identificação (RG) do hóspede.
     * \param telefone Telefone de contato do hóspede.
     * \param email Endereço de e-mail do hóspede.
     */
    Hospede(int codigo, const string& nome, const string& rg, const string& telefone, const string& email);

    /**
     * \brief Retorna o código identificador do hóspede.
     * \return Código do hóspede.
     */

    int HCodigo() const;

     /**
     * \brief Retorna o nome do hóspede.
     * \return Nome do hóspede.
     */

    string HNome() const;

    /**
     * \brief Retorna o documento de identificação (RG) do hóspede.
     * \return RG do hóspede.
     */

    string HRG() const;

    /**
     * \brief Retorna o número de telefone do hóspede.
     * \return Telefone do hóspede.
     */

    string HTelefone() const;

    /**
     * \brief Retorna o endereço de e-mail do hóspede.
     * \return E-mail do hóspede.
     */

    string HEmail() const;

     /**
     * \brief Define ou altera o nome do hóspede.
     * \param nome Novo nome a ser atribuído.
     */

    void H_Nome(const string& nome);

        /**
     * \brief Define ou altera o documento de identificação (RG) do hóspede.
     * \param rg Novo RG a ser atribuído.
     */

    void H_RG(const string& rg);

    /**
     * \brief Define ou altera o número de telefone do hóspede.
     * \param telefone Novo telefone a ser atribuído.
     */

    void H_Telefone(const string& telefone);

    /**
     * \brief Define ou altera o endereço de e-mail do hóspede.
     * \param email Novo e-mail a ser atribuído.
     */

    void H_Email(const string& email);

    /**
     * \brief Exibe na tela todas as informações do hóspede.
     */

    void Hospede_info() const;
};

#endif
