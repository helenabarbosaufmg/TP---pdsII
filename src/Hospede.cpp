#include "Hospede.h"
#include <iostream>
using namespace std;

Hospede::Hospede() {
    codigo = 0;
    nome = "";
    rg = "";
    telefone = "";
    email = "";
} //hospede vazio

Hospede::Hospede(int codigo, const string& nome, const string& rg, const string& telefone, const string& email) {
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
    this->rg = rg;
}

void Hospede::H_Telefone(const string& telefone) {
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
