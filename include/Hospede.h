#include <iostream>

using namespace std;

class Hospede {
private:
    string nome;
    string rg;
    string telefone;
    string email;
    int codigo;

public:
    Hospede();
    Hospede(int codigo, const string& nome, const string& rg, const string& telefone, const string& email);

    int HCodigo() const;
    string HNome() const;
    string HRG() const;
    string HTelefone() const;
    string HEmail() const;

    void H_Nome(const string& nome);
    void H_RG(const string& rg);
    void H_Telefone(const string& telefone);
    void H_Email(const string& email);

    void Hospede_info() const;
};

#endif