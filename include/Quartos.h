#ifndef QUARTOS_H
#define QUARTOS_H

#include <string>

class Quartos {
private:
    int numero;
    std::string tipo;
    double preco;
    bool ocupado;

public:
    // 🔹 Construtor padrão (resolve seu erro)
    Quartos() : numero(0), tipo("Indefinido"), preco(0.0), ocupado(false) {}

    // 🔹 Construtor completo (o que já existia)
    Quartos(int numero, std::string tipo, double preco);

    int QNumero() const;
    std::string QTipo() const;
    double QPreco() const;
    bool estaOcupado() const;
    void ocupar();
    void liberar();
};

 #endif
