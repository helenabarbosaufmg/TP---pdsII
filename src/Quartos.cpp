#include <iostream>
#include <stdexcept>
#include "Quartos.h"

Quartos::Quartos(int numero, std::string tipo, double preco)
    : numero(numero), tipo(tipo), preco(preco), ocupado(false) {
         if (numero <= 0) throw std::invalid_argument("Erro: número do quarto deve ser positivo.");
    if (tipo != "Solteiro" && tipo != "Casal" && tipo != "Luxo")
        throw std::invalid_argument("Erro: tipo inválido. Use Solteiro, Casal ou Luxo.");
    if (preco <= 0)
        throw std::invalid_argument("Erro: preço deve ser maior que zero.");
}
    

int Quartos::QNumero() const {
    return numero;
}

std::string Quartos::QTipo() const {
    return tipo;
}

double Quartos::QPreco() const {
    return preco;
}

bool Quartos::estaOcupado() const {
    return ocupado;
}

void Quartos::ocupar() {
    ocupado = true;
}

void Quartos::liberar() {
    ocupado = false;
}