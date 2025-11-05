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
    
    Quartos(int numero, std::string tipo, double preco);

    int getNumero() const;
    std::string getTipo() const;
    double getPreco() const;
    bool estaOcupado() const;

    void ocupar();
    void liberar();
};

#endif
 
