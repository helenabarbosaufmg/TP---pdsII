#include "Hospede.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cctype>
using namespace std;

/**
 * \brief Função auxiliar que verifica se uma string contém apenas números.
 * \param str String a ser verificada.
 * \return true se todos os caracteres forem dígitos, false caso contrário.
 */
static bool somenteNumeros(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

/**
 * \brief Construtor padrão da classe Hospede.
 * \details Inicializa um hóspede vazio com código 0 e campos em branco.
 */
Hospede::Hospede() {
    codigo = 0;
    nome = "";
    rg = "";
    telefone = "";
    email = "";
}


/**
 * \brief Construtor que inicializa um hóspede com dados validados.
 * \details Verifica se os campos obrigatórios são válidos antes de armazená-los.
 * \param codigo Código identificador do hóspede.
 * \param nome Nome completo do hóspede.
 * \param rg Documento de identificação (apenas números).
 * \param telefone Telefone de contato (apenas números).
 * \param email Endereço de e-mail (deve conter '@').
 * \throw invalid_argument Caso algum dado seja inválido.
 */
Hospede::Hospede(int codigo, const string& nome, const string& rg, const string& telefone, const string& email) {
    if (nome.empty()) throw invalid_argument("Erro: nome não pode ser vazio.");
    if (!somenteNumeros(rg)) throw invalid_argument("Erro: RG deve conter apenas números.");
    if (!somenteNumeros(telefone)) throw invalid_argument("Erro: telefone deve conter apenas números.");
    if (email.find('@') == string::npos) throw invalid_argument("Erro: e-mail inválido.");

    this->codigo = codigo;
    this->nome = nome;
    this->rg = rg;
    this->telefone = telefone;
    this->email = email;
}

/**
 * \brief Retorna o código identificador do hóspede.
 * \return Código do hóspede.
 */
int Hospede::HCodigo() const {
    return codigo;
}

/**
 * \brief Retorna o nome completo do hóspede.
 * \return Nome do hóspede.
 */
string Hospede::HNome() const {
    return nome;
}

/**
 * \brief Retorna o documento de identificação (RG) do hóspede.
 * \return RG do hóspede.
 */
string Hospede::HRG() const {
    return rg;
}

/**
 * \brief Retorna o telefone do hóspede.
 * \return Número de telefone.
 */
string Hospede::HTelefone() const {
    return telefone;
}

/**
 * \brief Retorna o e-mail do hóspede.
 * \return Endereço de e-mail.
 */
string Hospede::HEmail() const {
    return email;
}

/**
 * \brief Define ou altera o nome do hóspede.
 * \param nome Novo nome a ser atribuído.
 */
void Hospede::H_Nome(const string& nome) {
    this->nome = nome;
}

/**
 * \brief Define ou altera o RG do hóspede.
 * \param rg Novo RG a ser atribuído (apenas números).
 * \throw invalid_argument Caso o RG não contenha apenas números.
 */
void Hospede::H_RG(const string& rg) {
     if (!somenteNumeros(rg)) throw invalid_argument("Erro: RG inválido — use apenas números.");
    this->rg = rg;
    this->rg = rg;
}

/**
 * \brief Define ou altera o telefone do hóspede.
 * \param telefone Novo telefone a ser atribuído (apenas números).
 * \throw invalid_argument Caso o telefone não contenha apenas números.
 */
void Hospede::H_Telefone(const string& telefone) {
    if (!somenteNumeros(telefone)) throw invalid_argument("Erro: telefone inválido — use apenas números.");
    this->telefone = telefone;
    this->telefone = telefone;
}

/**
 * \brief Define ou altera o e-mail do hóspede.
 * \param email Novo e-mail a ser atribuído.
 */
void Hospede::H_Email(const string& email) {
    this->email = email;
}

/**
 * \brief Exibe todas as informações do hóspede no console.
 */
void Hospede::Hospede_info() const {
    cout << "Numero de reserva: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "RG: " << rg << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Email: " << email << endl;
}
