#include <iostream>
#include "Sistema.h"
#include "Reserva.h"
using namespace std;

/**
 * \brief Construtor padrão da classe Sistema.
 * \details Inicializa o sistema com vetores vazios de hóspedes, quartos e reservas.
 */
Sistema::Sistema(){}

/**
 * \brief Verifica se existe um hóspede cadastrado com o código informado.
 * \param codigo Código identificador do hóspede.
 * \return true se o hóspede estiver cadastrado, false caso contrário.
 */
bool Sistema::hospedeCadastrado(int codigo) const {
    for (const Hospede& h : hospedes) {
        if (h.HCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

/**
 * \brief Retorna a posição de um hóspede no vetor com base no código.
 * \param codigo Código identificador do hóspede.
 * \return Índice do hóspede no vetor, ou -1 se não encontrado.
 */
int Sistema::posicaoHospede(int codigo) const {
    for (std::size_t i = 0; i < hospedes.size(); ++i) {
        if (hospedes[i].HCodigo() == codigo) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

/**
 * \brief Verifica se existe um quarto cadastrado com o número informado.
 * \param numero Número identificador do quarto.
 * \return true se o quarto estiver cadastrado, false caso contrário.
 */
bool Sistema::quartoCadastrado(int numero) const {
    for (const Quartos& q : quartos) {
        if (q.QNumero() == numero) {
            return true;
        }
    }
    return false;
}

/**
 * \brief Retorna a posição de um quarto no vetor com base no número.
 * \param numero Número identificador do quarto.
 * \return Índice do quarto no vetor, ou -1 se não encontrado.
 */
int Sistema::posicaoQuarto(int numero) const {
    for (std::size_t i = 0; i < quartos.size(); ++i) {
        if (quartos[i].QNumero() == numero) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

/**
 * \brief Verifica se há sobreposição de datas para uma reserva em um mesmo quarto.
 * \details Compara o intervalo de datas informado com as reservas já existentes
 *          para o mesmo quarto, considerando conflitos de período.
 * \param numeroQuarto Número do quarto a ser verificado.
 * \param checkIn Data de check-in da nova reserva.
 * \param checkOut Data de check-out da nova reserva.
 * \return true se houver sobreposição de datas, false se não houver conflito.
 */
bool Sistema::reservaSobreposta(int numeroQuarto,
                                const string& checkIn,
                                const string& checkOut) const {
    for (const Reserva& r : reservas) {
        if (r.RQuarto().QNumero() == numeroQuarto) {

            const string& inExistente  = r.RCheckIn();
            const string& outExistente = r.RCheckOut();

            bool semConflito = (checkOut <= inExistente) || (checkIn >= outExistente);

            if (!semConflito) {
                return true;
            }
        }
    }
    return false; 
}

// -------------------------------------------------
// Hóspedes
// -------------------------------------------------

/**
 * \brief Cadastra um novo hóspede no sistema.
 * \details Verifica se já existe hóspede com o mesmo código e se RG e telefone
 *          contêm apenas números antes de adicionar.
 * \param h Objeto do tipo Hospede a ser cadastrado.
 */
void Sistema::cadastrarHospede(Hospede h) {
    if (hospedeCadastrado(h.HCodigo())) {
        cout << "Erro: ja existe hospede com esse codigo." << endl;
        return;
    }
    for (char c : h.HRG()) {
        if (!isdigit(c)) {
            cout << "Erro: RG deve conter apenas numeros." << endl;
            return;
        }
    }

    for (char c : h.HTelefone()) {
        if (!isdigit(c)) {
            cout << "Erro: telefone deve conter apenas numeros." << endl;
            return;
        }
    }

    hospedes.push_back(h);
    cout << "Hospede cadastrado com sucesso." << endl;
}

/**
 * \brief Retorna a lista de hóspedes cadastrados.
 * \return Referência constante para o vetor de hóspedes.
 */
const vector<Hospede>& Sistema::listarHospedes() const {
    return hospedes;
}


/**
 * \brief Busca um hóspede pelo código identificador.
 * \param codigo Código do hóspede.
 * \return Ponteiro constante para o hóspede encontrado, ou nullptr se não existir.
 */
const Hospede* Sistema::buscarHospedePorCodigo(int codigo) const {
    for (const Hospede& h : hospedes) {
        if (h.HCodigo() == codigo) {
            return &h;
        }
    }
    return nullptr;
}

// -------------------------------------------------
// Quartos
// -------------------------------------------------

/**
 * \brief Cadastra um novo quarto no sistema.
 * \details Verifica se já existe quarto com o mesmo número, se o tipo é válido
 *          e se o preço é positivo antes de adicionar.
 * \param q Objeto do tipo Quartos a ser cadastrado.
 */
void Sistema::cadastrarQuarto(Quartos q) {
    if (quartoCadastrado(q.QNumero())) {
        cout << "Erro: ja existe quarto com esse numero." << endl;
        return;
    }
    string tipo = q.QTipo();
    for (char& c : tipo) c = toupper(c);
    if (tipo != "SOLTEIRO" && tipo != "CASAL" && tipo != "LUXO") {
        cout << "Erro: tipo de quarto invalido. Use 'Solteiro', 'Casal' ou 'Luxo'." << endl;
        return;
    }

    if (q.QPreco() <= 0) {
        cout << "Erro: preco do quarto deve ser um valor positivo." << endl;
        return;
    }


    quartos.push_back(q);
    cout << "Quarto cadastrado com sucesso!" << endl;
}

/**
 * \brief Retorna a lista de quartos cadastrados.
 * \return Referência constante para o vetor de quartos.
 */
const vector<Quartos>& Sistema::listarQuartos() const {
    return quartos;
}

/**
 * \brief Busca um quarto pelo número identificador.
 * \param numero Número do quarto.
 * \return Ponteiro constante para o quarto encontrado, ou nullptr se não existir.
 */
const Quartos* Sistema::buscarQuartoPorNumero(int numero) const {
    for (const Quartos& q : quartos) {
        if (q.QNumero() == numero) {
            return &q;
        }
    }
    return nullptr;
}

/**
 * \brief Lista no console o status de todos os quartos.
 * \details Exibe número, tipo, preço e se o quarto está OCUPADO ou DISPONIVEL.
 */
void Sistema::listarStatusQuartos() const {
    cout << "\nStatus de Reservas (Lista de Quartos)\n";

    if (quartos.empty()) {
        cout << "Nenhum quarto cadastrado.\n";
        return;
    }

    for (const Quartos& q : quartos) {
        cout << "Quarto " << q.QNumero()
             << " - Tipo: " << q.QTipo()
             << " - Preco: R$ " << q.QPreco()
             << " - Status: " << (q.estaOcupado() ? "OCUPADO" : "DISPONIVEL")
             << endl;
    }
}

/**
 * \brief Marca um quarto como ocupado.
 * \param numeroQuarto Número do quarto a ser ocupado.
 */
void Sistema::ocuparQuarto(int numeroQuarto) {
    int pos = posicaoQuarto(numeroQuarto);
    if (pos == -1) {
        cout << "Quarto nao encontrado.\n";
        return;
    }

    if (quartos[pos].estaOcupado()) {
        cout << "Quarto " << numeroQuarto << " ja esta OCUPADO.\n";
        return;
    }

    quartos[pos].ocupar();
    cout << "Quarto " << numeroQuarto << " agora esta OCUPADO.\n";
}

/**
 * \brief Libera um quarto, marcando-o como disponível.
 * \param numeroQuarto Número do quarto a ser liberado.
 */
void Sistema::liberarQuarto(int numeroQuarto) {
    int pos = posicaoQuarto(numeroQuarto);
    if (pos == -1) {
        cout << "Quarto nao encontrado.\n";
        return;
    }

    if (!quartos[pos].estaOcupado()) {
        cout << "Quarto " << numeroQuarto << " ja esta DISPONIVEL.\n";
        return;
    }

    quartos[pos].liberar();
    cout << "Quarto " << numeroQuarto << " agora esta DISPONIVEL.\n";
}

// -------------------------------------------------
// Reservas
// -------------------------------------------------

/**
 * \brief Cria uma nova reserva no sistema.
 * \details Verifica se o hóspede e o quarto estão cadastrados, valida o formato das datas
 *          e checa se não há sobreposição com outras reservas para o mesmo quarto.
 * \param r Objeto do tipo Reserva a ser criado.
 */
void Sistema::criarReserva(Reserva r) {
    int codigoHospede = r.RHospede().HCodigo();
    if (!hospedeCadastrado(codigoHospede)) {
        cout << "Erro: hospede nao esta cadastrado." << endl;
        return;
    }

    int numeroQuarto = r.RQuarto().QNumero();
    int posQuarto = posicaoQuarto(numeroQuarto);
    if (posQuarto == -1) {
        cout << "Erro: quarto nao esta cadastrado." << endl;
        return;
    }

    string checkIn = r.RCheckIn();
    string checkOut = r.RCheckOut();
    if (checkIn.size() != 10 || checkOut.size() != 10 || checkIn[2] != '/' || checkIn[5] != '/' ||
        checkOut[2] != '/' || checkOut[5] != '/') {
        cout << "Erro: formato de data invalido (use dd/mm/aaaa)." << endl;
        return;
    }


    if (reservaSobreposta(numeroQuarto, r.RCheckIn(), r.RCheckOut())) {
        cout << "Erro: ja existe reserva nesse periodo para este quarto." << endl;
        return;
    }

    reservas.push_back(r);
    reservas.back().setStatus("Agendada");
    quartos[posQuarto].ocupar();

    cout << "Reserva criada com sucesso!" << endl;
}

/**
 * \brief Retorna a lista de reservas cadastradas.
 * \return Referência constante para o vetor de reservas.
 */
const vector<Reserva>& Sistema::listarReservas() const {
    return reservas;
}

/**
 * \brief Busca uma reserva pelo número identificador.
 * \param numeroReserva Número da reserva.
 * \return Ponteiro constante para a reserva encontrada, ou nullptr se não existir.
 */
const Reserva* Sistema::buscarReservaPorNumero(int numeroReserva) const {
    for (const Reserva& r : reservas) {
        if (r.RNumeroReserva() == numeroReserva) {
            return &r;
        }
    }
    return nullptr;
}

// Opcao 2: pesquisar hospede pelo numero da reserva
/**
 * \brief Exibe os dados do hóspede associado a uma determinada reserva.
 * \param numeroReserva Número da reserva usada para encontrar o hóspede.
 */
void Sistema::mostrarHospedePorReserva(int numeroReserva) const {
    const Reserva* r = buscarReservaPorNumero(numeroReserva);
    if (!r) {
        cout << "Hospede nao encontrado para este numero de reserva." << endl;
        return;
    }

    Hospede h = r->RHospede();

    cout << "\nHospede encontrado:\n";
    cout << "Numero da reserva: " << r->RNumeroReserva() << endl;
    cout << "Nome: " << h.HNome() << endl;
    cout << "RG: " << h.HRG() << endl;
    cout << "Telefone: " << h.HTelefone() << endl;
    cout << "Email: " << h.HEmail() << endl;
}

// Opcao 3: pesquisar dados completos da reserva
/**
 * \brief Exibe todas as informações completas de uma reserva.
 * \param numeroReserva Número da reserva a ser exibida.
 */
void Sistema::mostrarDadosReservaCompleta(int numeroReserva) const {
    const Reserva* r = buscarReservaPorNumero(numeroReserva);
    if (!r) {
        cout << "Reserva nao encontrada." << endl;
        return;
    }

    cout << "\nDados da Reserva\n";
    cout << "Numero da reserva: " << r->RNumeroReserva() << endl;
    cout << "Status: " << r->RStatus() << endl;
    cout << "Check-in: " << r->RCheckIn() << endl;
    cout << "Check-out: " << r->RCheckOut() << endl;

    cout << "\nHospede:\n";
    Hospede h = r->RHospede();
    cout << "Nome: " << h.HNome() << endl;
    cout << "RG: " << h.HRG() << endl;
    cout << "Telefone: " << h.HTelefone() << endl;
    cout << "Email: " << h.HEmail() << endl;

    cout << "\nQuarto:\n";
    Quartos q = r->RQuarto();
    cout << "Numero: " << q.QNumero() << endl;
    cout << "Tipo: " << q.QTipo() << endl;
    cout << "Preco diaria: R$ " << q.QPreco() << endl;
}

// -------------------------------------------------
// Check-in, check-out e cancelamento
// -------------------------------------------------

/**
 * \brief Realiza o check-in de uma reserva.
 * \details Atualiza o status da reserva para "Em andamento".
 * \param numeroReserva Número da reserva a ser atualizada.
 */
void Sistema::fazerCheckIn(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.RNumeroReserva() == numeroReserva) {
            r.setStatus("Em andamento");
            cout << "Check-in realizado com sucesso." << endl;
            return;
        }
    }
    cout << "Reserva nao encontrada." << endl;
}

/**
 * \brief Realiza o check-out de uma reserva.
 * \details Atualiza o status para "Concluida" e libera o quarto associado.
 * \param numeroReserva Número da reserva a ser encerrada.
 */
void Sistema::fazerCheckOut(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.RNumeroReserva() == numeroReserva) {
            r.setStatus("Concluida");

            int numeroQuarto = r.RQuarto().QNumero();
            int posQuarto = posicaoQuarto(numeroQuarto);
            if (posQuarto != -1) {
                quartos[posQuarto].liberar();
            }

            cout << "Check-out realizado com sucesso." << endl;
            return;
        }
    }
    cout << "Reserva nao encontrada." << endl;
}

/**
 * \brief Cancela uma reserva existente.
 * \details Atualiza o status para "Cancelada" e libera o quarto associado.
 * \param numeroReserva Número da reserva a ser cancelada.
 */
void Sistema::cancelarReserva(int numeroReserva) {
    for (Reserva& r : reservas) {
        if (r.RNumeroReserva() == numeroReserva) {
            r.setStatus("Cancelada");

            int numeroQuarto = r.RQuarto().QNumero();
            int posQuarto = posicaoQuarto(numeroQuarto);
            if (posQuarto != -1) {
                quartos[posQuarto].liberar();
            }

            cout << "Reserva cancelada." << endl;
            return;
        }
    }
    cout << "Reserva nao encontrada." << endl;
}