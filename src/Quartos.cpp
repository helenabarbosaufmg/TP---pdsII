#include <iostream>
#include "Quartos.h"

Quartos::Quartos(int numero, std::string tipo, double preco)
    : numero(numero), tipo(tipo), preco(preco), ocupado(false) {}

int Quartos::getNumero() const {
    return numero;
}

std::string Quartos::getTipo() const {
    return tipo;
}

double Quartos::getPreco() const {
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