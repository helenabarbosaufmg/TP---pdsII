#ifndef HOSPEDE_H
#define HOSPEDE_H

#include <string>


class Hospede {
private:
    std::string nome; 
    std::string cpf;  

public:
   
    Hospede(std::string nome, std::string cpf);
    std::string getNome() const;
    std::string getCpf() const;
};

#endif
