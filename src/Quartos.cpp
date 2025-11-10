#include <iostream>
#include "Quartos.h"

Quartos::Quartos(int numero, std::string tipo, double preco)
    : numero(numero), tipo(tipo), preco(preco), ocupado(false) {}

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