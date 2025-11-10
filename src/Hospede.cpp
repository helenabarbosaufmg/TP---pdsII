#include "Hospede.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cctype>
using namespace std;

static bool somenteNumeros(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}


Hospede::Hospede() {
    codigo = 0;
    nome = "";
    rg = "";
    telefone = "";
    email = "";
} //hospede vazio

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

int Hospede::HCodigo() const {
    return codigo;
}

string Hospede::HNome() const {
    return nome;
}

string Hospede::HRG() const {
    return rg;
}

string Hospede::HTelefone() const {
    return telefone;
}

string Hospede::HEmail() const {
    return email;
}

void Hospede::H_Nome(const string& nome) {
    this->nome = nome;
}

void Hospede::H_RG(const string& rg) {
     if (!somenteNumeros(rg)) throw invalid_argument("Erro: RG inválido — use apenas números.");
    this->rg = rg;
    this->rg = rg;
}

void Hospede::H_Telefone(const string& telefone) {
    if (!somenteNumeros(telefone)) throw invalid_argument("Erro: telefone inválido — use apenas números.");
    this->telefone = telefone;
    this->telefone = telefone;
}

void Hospede::H_Email(const string& email) {
    this->email = email;
}

void Hospede::Hospede_info() const {
    cout << "Código do Hospede: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "RG: " << rg << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Email: " << email << endl;
}
