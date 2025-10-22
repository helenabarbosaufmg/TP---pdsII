Requisitos: funcionais e não funcionais.
- Escopo: analisar disponibilidade, criar/cancelar/alterar reservas, adquirir dados do hóspede, verificar reservas.
- Atores: hóspede, sistema, operador (caso a reserva seja feita por algum funcionário do hotel).
- Classes de domínio: Quarto, Hospede, Reserva e Sistema.
  
Requisitos funcionais:
* Cadastrar quartos (número, data e tipo de apartamento);
* Cadastrar hóspedes (nome, CPF, quantidade de pessoas, informação para contato);
* Criar reservas, associando quartos a hóspedes;
* Fazer check-in e check-out;
* Calcular valor final da reserva.

Requisitos não funcionais: 
* Sistema compilável em C++17+, em Windows e Linux;
* Interface simples e intuitiva;
* Integridade dos dados (não realizar reservas duplas);
* Pastas de build não versionadas (pasta de compilação que existe localmente, mas não é rastreada pelo Git). 
  
