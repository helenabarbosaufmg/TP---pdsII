# TP---pdsII

## 1. Tema do Projeto
**Título:** Sistema de Gerenciamento de Reserva de Hotel  

**Descrição:**  
O projeto consiste no desenvolvimento de um sistema em C++ voltado para o gerenciamento de reservas de um hotel. O sistema permitirá o cadastro de hóspedes, a reserva e cancelamento de quartos, além do controle de disponibilidade das acomodações.  
O objetivo é criar uma aplicação simples, mas funcional, que auxilie o gerenciamento de um hotel de pequeno porte, permitindo maior organização e controle sobre o fluxo de reservas.

## 2. Problema a Ser Resolvido
Atualmente, muitos hotéis de pequeno e médio porte ainda realizam o controle de reservas de forma manual, utilizando planilhas ou registros em papel. Esse método aumenta as chances de erro, como **duplicidade de reservas**, **perda de informações** e **falta de visão geral sobre a ocupação dos quartos**.  
O sistema proposto busca solucionar esses problemas ao **automatizar o processo de reserva**, centralizando as informações de hóspedes, quartos e períodos reservados, garantindo **maior precisão, agilidade e confiabilidade** no gerenciamento.

## 3. Objetivos do Projeto
- Desenvolver um sistema que permita o **cadastro, consulta, edição e exclusão** de reservas de hóspedes.  
- Implementar funcionalidades para **verificação de disponibilidade** de quartos e **controle de check-in e check-out**.  
- Registrar e armazenar as informações em **arquivos locais**, garantindo a persistência dos dados.  
- Aplicar conceitos de **programação orientada a objetos (POO)**, **tratamento de exceções** e **uso de estruturas de dados** (como listas, vetores e structs).  
- Utilizar **Git e GitHub** para controle de versão e colaboração entre os integrantes do grupo.

## 4. Ferramentas e Linguagem
- **Linguagem:** C++  
- **Controle de versão:** Git e GitHub  
- **Ambiente de desenvolvimento:** Visual Studio Code  
- **Bibliotecas:** iostream, fstream, string, vector e outras da biblioteca padrão do C++  


## 5. Grupo
- Helena de Oliveira Barbosa  
- Lilla de Lucas Xavier de Oliveira 
- Maria Luisa Braga
- Livia Viana

## 6. Como Compilar e Executar 
O projeto utiliza o Makefile para compilação e execução e como pré-requisitos tem: 
- Compilador C++ (g++ ou equivalente) com suporte a C++11 ou superior;
- make.
Comandos a serem utilizados (dentro da pasta do projeto):
- make (compila o projeto);
- make run (executa o sistema);
- make clean (limpa arquivos).
Observação: caso o projeto seja testado manualmente (sem make), é necessário saber o sistema operacional utilizado (Linux, macOS, Windows etc).

## 7. Organização do Projeto 
  A estrutura de diretórios do projeto consiste em: 
**SRC:** 

- main.cpp
- Hospede.cpp
- Quartos.cpp
- Reserva.cpp
- Sistema.cpp
  
**Include:**
  
- Hospede.h
- Quartos.h
- Reserva.h
- Sistema.h
  
**OUTROS:**

- Documentação gerada pelo Doxygen (docs/)
- Makefile
- README.md
  Os módulos principais, ou seja, os conjuntos de código com uma função específica no programa são:
- Hospede: gerencia os dados dos hóspedes do hotel (nomes, CPF's, contato, check-in, check-out);
- Quartos: armazena informações das acomodações do hotel (número, tipo, status);
- Reserva: armazena informações e estabelece um número para cada reserva feita;
- Sistema: integra os outros módulos e apresenta o menu principal ao usuário.

## 8. Funcionalidades

O sistema de gerenciamento de hotel tem como funções: 
  - Cadastro de hóspedes;
  - Cadastro de quartos;
  - Registro de reservas vinculando hóspedes e quartos;
  - Verificação da disponibilidade do quarto;
  - Cancelamento de reserva;
  - Listagem do status do quarto;
  - (...)


## 9. Itens Fora do Escopo

(...) 

## 10. Instruções de Uso 
- **Para Linux:**
Compilar com MakeFile:
`make run`
`make`

- **Para MacOS:**
Compilar no terminal com g++: 
```text
g++ main.cpp src/Hospede.cpp src/Quartos.cpp src/Reserva.cpp src/Sistema.cpp -I include -std=c++17 -o main
```
`./main`
- **Para Windows:**
Compilar com MakeFile:
`make run`
`make`
OBS: make clean não funciona no Windows. 

## 11. Exemplos de Uso (Entradas e Saídas)

### **Opção 1 (cadastrar novo quarto)**
Entrada:
```
1
```
Saída: 
```
Cadastro de Quarto
Número do quarto: 01
Tipo (ex: Solteiro, Casal, Luxo): Casal
Preço da diaria: 120
Quarto cadastrado com sucesso!
```

### **Opção 2 (Cadastrar novo hospede no quarto previamente cadastrado)**
Entrada: 
```
2
```
Saída: 
```
Quartos cadastrados:
Quarto 1 - Tipo: Solteiro - Preco: R$ 120 - Status: DISPONIVEL

Digite o número do quarto para este hóspede:
```
Entrada:
```
1
```
Saída:
```
Dados do Hóspede
Código do hóspede: 01
Nome: Joao Silva
RG: 12345678990
Telefone: 31912345678
Email: joaosilva@gmail.com
Hóspede cadastrado com sucesso.
```
Saída:
```
Data de check-in: 12/11/2025
Data de check-out: 15/11/2025
Reserva criada com sucesso!
```

### **Opção 3 (Pesquisar número de reserva)**
Entrada:
```
3
```
Saída:
```
Digite o número da reserva: 01
```
Saída:
```
Dados da Reserva
Número da reserva: 1
Status: Agendada
Check-in: 12/11/2025
Check-out: 15/11/2025

Hóspede:
Nome: Joao Silva
RG: 12345678990
Telefone: 31912345678
Email: joaosilva@gmail.com

Quarto:
Número: 1
Tipo: Solteiro
Preço diária: R$ 120
```

### **Opção 4 (Cadastrar nova reserva de hóspede já previamente cadastrado)**
Entrada:
```
4
```
Saída:
```
Código do hóspede (já cadastrado):
```
Entrada: 
```
1
```
Saída:
```
Dados do Hóspede:
Codigo: 1
Nome: Joao Silva
RG: 12345678990
Telefone: 31912345678
Email: joaosilva@gmail.com

Quartos cadastrados:
Quarto 1 - Tipo: Solteiro - Preço: R$ 120 - Status: OCUPADO

Digite o número do quarto para nova reserva (ou 0 para cadastrar um novo quarto):
```
Entrada:
``` 
0
```
Saída:
```
Cadastro de Novo Quarto
Número do quarto: 02
Tipo (ex: Solteiro, Casal, Luxo): Casal
Preço da diária: 350
Quarto cadastrado com sucesso!
Data de check-in: 12/11/2025
Data de check-out: 15/11/2025
Reserva criada com sucesso!
```

### **Opção 5 (Status de reservas(Listas quartos))**
Entrada:
```
5
```
Saída:
```
Status de Reservas (Lista de Quartos)
Quarto 1 - Tipo: Solteiro - Preço: R$ 120 - Status: OCUPADO
``` 
### **Opção 6 (Ocupar quarto)**
Entrada:
```
6
```
Saída:
```
Número do quarto a ocupar: 
```
Entrada:
```
1
```
Saída: 
```
Quarto 1 já esta OCUPADO.
```

### **Opção 7 (Liberar quarto)**
Entrada:
```
7
```
Saída:
```
Número do quarto a liberar:
```
Entrada:
```
1
```
Saída:
```
Quarto 1 agora esta DISPONIVEL.
```

### **Opção 0 (Sair)**
Entrada:
```
0
```
Saída:
```
Saindo do sistema...
```


## 12. Programação Defensiva 
- **Em Quartos.cpp:**
```text
#include <iostream>
#include <stdexcept>
#include "Quartos.h"
Quartos::Quartos(int numero, std::string tipo, double preco)
: numero(numero), tipo(tipo), preco(preco), ocupado(false) {
if (numero <= 0) throw std::invalid_argument("Erro: número do quarto de
ve ser positivo.");
if (tipo != "Solteiro" && tipo != "Casal" && tipo != "Luxo")
throw std::invalid_argument("Erro: tipo inválido. Use Solteiro, Casal ou
Luxo.");
if (preco <= 0)
throw std::invalid_argument("Erro: preço deve ser maior que zero.");
}
```
- **Em Hospede.cpp:**
```text
#include "Hospede.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cctype>
using namespace std;
static bool somenteNumeros(const string& str) {
return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}
Hospede::Hospede() {
codigo = 0;
nome = "";
rg = "";
telefone = "";
email = "";
}
Hospede::Hospede(int codigo, const string& nome, const string& rg, const
string& telefone, const string& email) {
if (nome.empty()) throw invalid_argument("Erro: nome não pode ser vazi
o.");
if (!somenteNumeros(rg)) throw invalid_argument("Erro: RG deve conter
apenas números.");
if (!somenteNumeros(telefone)) throw invalid_argument("Erro: telefone d
eve conter apenas números.");
if (email.find('@') == string::npos) throw invalid_argument("Erro: e-mail i
nválido.");
this→codigo = codigo;
this→nome = nome;
this→rg = rg;
this→telefone = telefone;
this→email = email;
}
void Hospede::H_RG(const string& rg) {
if (!somenteNumeros(rg)) throw invalid_argument("Erro: RG inválido — us
e apenas números.");
this→rg = rg;
}
void Hospede::H_Telefone(const string& telefone) {
if (!somenteNumeros(telefone)) throw invalid_argument("Erro: telefone in
válido — use apenas números.");
this→telefone = telefone;
}
```
- **Em Reserva.cpp:**
```text
#include "Reserva.h"
#include <stdexcept>
#include <cctype>
static bool dataValida(const std::string& data) {
if (data.size() != 10 || data[2] != '/' || data[5] != '/') return false;
for (size_t i = 0; i < data.size(); ++i) {
if (i != 2 && i != 5 && !isdigit(data[i])) return false;
}
return true;
}
Reserva::Reserva(int numeroReserva, Hospede h, Quartos q, std::string ch
eckIn, std::string checkOut)
: numeroReserva(numeroReserva), hospede(h), quarto(q), checkIn(chec
kIn), checkOut(checkOut), status("ATIVA") {
if (numeroReserva <= 0) throw std::invalid_argument("Erro: número da re
serva deve ser positivo.");
if (!dataValida(checkIn) || !dataValida(checkOut))
throw std::invalid_argument("Erro: formato de data inválido (use dd/m
m/aaaa).");
}
```
- **Em Sistema.cpp:**
```text
#include <iostream>
#include <stdexcept>
#include "Sistema.h"
#include "Reserva.h"
using namespace std;
Sistema::Sistema(){}
bool Sistema::quartoCadastrado(int numero) const {
for (const Quartos& q : quartos) {
if (q.QNumero() == numero) return true;
}
return false;
}
void Sistema::cadastrarQuarto(const Quartos& q) {
if (quartoCadastrado(q.QNumero())) {
throw invalid_argument("Erro: já existe quarto com este número.");
}
quartos.push_back(q);
cout << "Quarto cadastrado com sucesso!" << endl;
}
void Sistema::cadastrarHospede(const Hospede& h) {
if (hospedeCadastrado(h.HCodigo())) {
throw invalid_argument("Erro: já existe hóspede com este código.");
}
hospedes.push_back(h);
cout << "Hóspede cadastrado com sucesso!" << endl;
}
```
- **Em main.cpp:**
```text
#include <iostream>
#include "Sistema.h"
int main() {
Sistema sistema;
try {
Quartos q1(101, "Casal", 250.0);
sistema.cadastrarQuarto(q1);
Hospede h1(1, "Maria", "123456", "987654321", "maria@email.com");
sistema.cadastrarHospede(h1);
}
catch (const std::exception& e) {
std::cerr << "Erro: " << e.what() << std::endl;
}
return 0;
}
```

## 13. Documentação: Doxygen (Helena) 
(...)
## 14. Link do Vídeo de Execução

## 15. Equipe e Contribuições
- Helena Barbosa: responsável pelo desenvolvimento dos arquivos Reserva.h e Sistema.h, desenvolvimento do arquivo Sistema.cpp e modificações no main.cpp relacionadas a funções correspondentes ao sistema do hotel, desenvolvimento da documentação por meio do Doxygen. 
- Lilla Xavier: responsável pela criação dos arquivos com os cartões CRC e com os requisitos funcionais e não funcionais do código; pelo arquivo Reserva.cpp e por modificar o arquivo main.cpp para que atendesse as funções relacionadas à reserva e pelo desenvolvimento do arquivo README.md. 
- Lívia Viana: responsável pela estruturação inicial dos diretórios do projeto (src, include etc.), pelo desenvolvimento do arquivo Hospede.cpp e do arquivo main.cpp, que posteriormente foi modificado pelos outros membros, desenvolvimento do arquivo makefile para compilação e execução do projeto. 
- Maria Luísa Braga: responsável pelo desenvolvimento dos arquivos Hospede.h e Quartos.h, desenvolvimento do arquivo Quartos.cpp e modificações no main.cpp relacionadas a funções correspondentes aos quartos do hotel, inclusão da programação defensiva no código. 

Observação: todos os integrantes participaram da discussão na escolha do tema, no desenvolvimento inicial do ambiente de programação e em modificações e revisões dos códigos e arquivos para a entrega da saída correta e esperada pelo grupo. 

## 16. Ciclo de Desenvolvimento
- Sprint 1 (05/10 a 09/10): formação da equipe, configuração do GitHub e outros ambientes de desenvolvimento, definição do tema com breve descrição, acesso ao GitHub com um commit teste de cada membro do grupo. 
- Sprint 2 (09/10 a 23/10): organização inicial dos diretórios do código, levantamento dos requisitos funcionais e não funcionais (User Stories), descrição inicial do funcionamento do sistema (Cartões CRC) e criação dos arquivos .h (Hospede.h; Quartos.h; Reserva.h; Sistema.h)
- Sprint 3 (23/10 a 11/10): codificação dos arquivos .cpp (main.cpp; Hospede.cpp; Quartos.cpp; Reserva.cpp; Sistema.cpp), desenvolvimento do README.md e da documentação por meio do Doxygen, inclusão de mecanismos para tratar condições de exceção do sistema, revisão do trabalho e desenvolvimento do vídeo de execução. 
- Sprint 4 (12/11 a 25/11): entrega da apresentação em PDF até dia 12/11 e apresentação em ordem de sorteio dos grupos nos dias 12, 18 e 25 de novembro. 

## 17. Aprendizados: 
- Algumas funcionalidades que gostaríamos de ter adicionado ao sistema não foram possíveis, devido a impedimentos como o tempo e a dificuldade de realizá-las, por exemplo uma interface gráfica para o sistema de gerenciamento de hotéis. 
- Dificuldade inicial com o ambiente de desenvolvimento GitHub, devido aos diversos comandos necessários para commitar updates e pelo fato de que foi necessário grande comunicação entre os membros do grupo para que mudanças por pessoas diferentes não fossem feitas ao mesmo tempo, pois nem sempre eram salvos se feitas no mesmo momento. 
- Retrabalho no desenvolvimento do main.cpp ao perceber que, apesar de estar compilando corretamente, não estava entregando a saída esperada. Assim foram necessárias pequenas mudanças em todo código do main. 

## 18. Evidências no Github: 

- **Commits:**
  * 99de164 Lilla Xavier <2025018341> Tue Nov 11 10:01:48 2025 -0300 mudanca em acentuacao
*   7a60c27 Lilla Xavier <2025018341> Tue Nov 11 09:52:31 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
|\  
| *   4fbd889 liviafviana <liviafvianaa@gmail.com> Tue Nov 11 09:10:24 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
| |\  
| | * cf251c6 Lilla Xavier <lilladelucas25@gmail.com> Tue Nov 11 09:06:09 2025 -0300 Update README.md
| * | 75da6ee liviafviana <liviafvianaa@gmail.com> Tue Nov 11 09:10:14 2025 -0300 correçaõ codigo e numero de reserva
| |/  
| * 9f45937 liviafviana <liviafvianaa@gmail.com> Tue Nov 11 08:34:26 2025 -0300 main
| * 2f2c894 liviafviana <liviafvianaa@gmail.com> Tue Nov 11 08:30:13 2025 -0300 read me atualizado
| * 1291be2 liviafviana <liviafvianaa@gmail.com> Tue Nov 11 08:22:59 2025 -0300 read me teste
| * 3c76de9 liviafviana <liviafvianaa@gmail.com> Tue Nov 11 08:13:43 2025 -0300 codigo -> numero de reserva e read me atalizando
| * a6a3165 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 23:25:42 2025 -0300 doxygen
| * 7561d58 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 22:59:54 2025 -0300 comentarios doxygen
| *   9af6110 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 21:58:50 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
| |\  
| | * 318f13c liviafviana <liviafvianaa@gmail.com> Mon Nov 10 21:54:01 2025 -0300 main atualizado
| * | b1080dd Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 21:53:10 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
| |\| 
| | * f53c960 liviafviana <liviafvianaa@gmail.com> Mon Nov 10 21:49:52 2025 -0300 rascunho
| | * 89aedbe liviafviana <liviafvianaa@gmail.com> Mon Nov 10 21:46:27 2025 -0300 read me teste3
| | * bb645a5 liviafviana <liviafvianaa@gmail.com> Mon Nov 10 21:45:29 2025 -0300 read me teste 2
| | * 2a3b065 liviafviana <liviafvianaa@gmail.com> Mon Nov 10 21:44:33 2025 -0300 readme teste
| | * 335e7bf liviafviana <liviafvianaa@gmail.com> Mon Nov 10 21:43:23 2025 -0300 readme
| * | 57e72e4 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 21:53:01 2025 -0300 sistema.cpp correcao tipo de quarto
| |/  
| * 225adc5 liviafviana <liviafvianaa@gmail.com> Mon Nov 10 21:17:01 2025 -0300 Local do main atualizado
| * 4665e9c liviafviana <liviafvianaa@gmail.com> Mon Nov 10 20:57:15 2025 -0300 Correção de bugs e erros
| *   378e8a1 liviafviana <liviafvianaa@gmail.com> Mon Nov 10 20:24:11 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
| |\  
| | * edc7839 marialuisabraga-ux <marialuisamalubraga@gmail.com> Mon Nov 10 19:35:42 2025 -0300 Atualizações programação defensiva
| | * fe680ec marialuisabraga-ux <marialuisamalubraga@gmail.com> Mon Nov 10 19:23:26 2025 -0300 Remove submódulo antigo e corrige estrutura do projeto
| | * 55e7e3a marialuisabraga-ux <marialuisamalubraga@gmail.com> Mon Nov 10 18:57:41 2025 -0300 Corrigindo estrutura e removendo submódulo duplicado
| | * 0fe0488 marialuisabraga-ux <marialuisamalubraga@gmail.com> Mon Nov 10 18:39:01 2025 -0300 Atualizações programação defensiva
| * | e62a786 marialuisabraga-ux <marialuisamalubraga@gmail.com> Mon Nov 10 18:46:52 2025 -0300 Un-nest project: mover conteúdo de TP---pdsII para root e remover submódulo
| |/  
| * ddff9fe marialuisabraga-ux <marialuisamalubraga@gmail.com> Thu Oct 9 21:13:16 2025 -0300 Adicionando o arquivo teste.txt
| * 2edaa9e marialuisabraga-ux <marialuisamalubraga@gmail.com> Mon Nov 10 17:17:11 2025 -0300 atualiza Hospede.cpp, Quartos.cpp e Reserva.cpp com a programação defensiva
| * 2d34990 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 12:29:16 2025 -0300 atualiza main com integracao do sistema
| * 335a750 Lilla Xavier <lilladelucas25@gmail.com> Mon Nov 10 11:32:51 2025 -0300 Update main.cpp
| *   d1ba0be Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 10:21:05 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
| |\  
| * | 771c519 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 02:01:10 2025 -0300 modificacoes main.cpp
| * | de49e66 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 01:39:25 2025 -0300 compila sistema completa com correcoes reserva sistema
| * |   e01373d Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 01:04:03 2025 -0300 atualiza arquivos
| |\ \  
| * | | d7c3908 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Mon Nov 10 00:49:35 2025 -0300 Implementa sistema e ajustes  reserva
| * | | 75d79c2 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Sun Nov 9 19:03:01 2025 -0300 funcao setStatus em reserva.cpp
* | | | 9130c4e Lilla Xavier <2025018341> Tue Nov 11 09:12:48 2025 -0300 atualizacoes
| |_|/  
|/| |   
* | | 73cd2a6 Lilla Xavier <2025018341> Mon Nov 10 10:12:59 2025 -0300 main.cpp atualizado
* | |   7569754 Lilla Xavier <2025018341> Mon Nov 10 10:02:03 2025 -0300 Bug de commit
|\ \ \  
| | |/  
| |/|   
| * |   9814abb helenabarbosaufmg <helenaobarbosa8@gmail.com> Sun Nov 9 18:48:50 2025 -0300 Merge pull request #1 from helenabarbosaufmg/feature/sistema-cpp
| |\ \  
| | * \   51c05cf helenabarbosaufmg <helenaobarbosa8@gmail.com> Sun Nov 9 18:05:02 2025 -0300 Merge branch 'main' into feature/sistema-cpp
| | |\ \  
| | |/ /  
| |/| /   
| | |/    
| * | b304abd Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 12:57:12 2025 -0300 Update Reserva.h
| * | f70d0e8 Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 12:56:31 2025 -0300 Update Reserva.cpp
| * | 5c8ca29 Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 12:41:00 2025 -0300 Update Reserva.cpp
| * | 9cb5a37 Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 12:40:01 2025 -0300 Update Reserva.h
| * | 39c9260 liviafviana <liviafvianaa@gmail.com> Sun Nov 9 12:24:11 2025 -0300 Correção opções
| * |   ca02c49 liviafviana <liviafvianaa@gmail.com> Sun Nov 9 12:02:22 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
| |\ \  
| | * | cb984d0 Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 11:38:04 2025 -0300 Update README.md
| | * | 5e5b424 Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 11:29:22 2025 -0300 Update README.md
| | * | 00e2e6b Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 11:28:24 2025 -0300 Update README.md
| | * | 80e2f10 Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 11:25:57 2025 -0300 Update README.md
| | * | b14fd2a Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 11:20:34 2025 -0300 Update README.md
| | * | ca15e53 Lilla Xavier <lilladelucas25@gmail.com> Sun Nov 9 11:17:27 2025 -0300 Update README.md
| | * | 1ce8c4b Lilla Xavier <lilladelucas25@gmail.com> Sat Nov 8 17:33:07 2025 -0300 Update README.md
| * | | d80e831 liviafviana <liviafvianaa@gmail.com> Sun Nov 9 12:02:15 2025 -0300 Makefile criado
| |/ /  
| * | 36af5b0 liviafviana <liviafvianaa@gmail.com> Sat Nov 8 16:40:48 2025 -0300 quartos.h
| * | 14293cc Lilla Xavier <lilladelucas25@gmail.com> Sat Nov 8 16:12:40 2025 -0300 Update Quartos.h
| * | dd6b396 Lilla Xavier <lilladelucas25@gmail.com> Sat Nov 8 16:11:24 2025 -0300 Update README.md
| * | 575ce2c liviafviana <liviafvianaa@gmail.com> Fri Nov 7 11:39:20 2025 -0300 main
| * | 978e270 Lilla Xavier <lilladelucas25@gmail.com> Fri Nov 7 10:58:41 2025 -0300 Update main.cpp
| * | 63ca3be Lilla Xavier <lilladelucas25@gmail.com> Fri Nov 7 10:44:37 2025 -0300 Update reserva main.cpp
| | * a55b021 Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Sat Nov 8 19:44:34 2025 -0300 Implementação das funções e ajustes
| | * 281890c Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Wed Nov 5 22:01:39 2025 -0300 Update Sistema.h
| | * a42c26c Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Wed Nov 5 21:57:48 2025 -0300 Correções no sistema.h
* | | 758f320 Lilla Xavier <2025018341> Mon Nov 10 09:51:16 2025 -0300 Atualizacoes
|/ /  
* | 04a6f96 liviafviana <liviafvianaa@gmail.com> Thu Nov 6 13:24:40 2025 -0300 mudança de pasta
* |   27c97c6 liviafviana <liviafvianaa@gmail.com> Thu Nov 6 13:18:05 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
|\ \  
| * \   9dc02a8 marialuisabraga-ux <marialuisamalubraga@gmail.com> Thu Nov 6 12:59:04 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
| |\ \  
| * | | ed750dc marialuisabraga-ux <marialuisamalubraga@gmail.com> Thu Nov 6 12:58:29 2025 -0300 atualizei o main
* | | | a53813c liviafviana <liviafvianaa@gmail.com> Thu Nov 6 13:17:19 2025 -0300 teste
| |/ /  
|/| |   
* | | f1dab41 liviafviana <liviafvianaa@gmail.com> Thu Nov 6 11:26:40 2025 -0300 bug corrigido
* | | 0454d2e Lilla Xavier <lilladelucas25@gmail.com> Wed Nov 5 23:34:14 2025 -0300 Update Reserva.h
* | | 9f0f506 Lilla Xavier <lilladelucas25@gmail.com> Wed Nov 5 23:31:10 2025 -0300 Update Reserva.h
* | | d3456c9 Lilla Xavier <lilladelucas25@gmail.com> Wed Nov 5 23:27:31 2025 -0300 Update Reserva.cpp
* | | f8e0596 marialuisabraga-ux <marialuisamalubraga@gmail.com> Wed Nov 5 20:27:32 2025 -0300 Update Hospede.h
|/ /  
* | f90a999 marialuisabraga-ux <marialuisamalubraga@gmail.com> Wed Nov 5 19:52:07 2025 -0300 Update Hospede.h
* | 8e64897 marialuisabraga-ux <marialuisamalubraga@gmail.com> Wed Nov 5 19:04:58 2025 -0300 Update Quartos.h
* | 1acbf35 Lilla Xavier <lilladelucas25@gmail.com> Wed Nov 5 18:18:46 2025 -0300 Update README.md
|/  
*   cee0c6c liviafviana <liviafvianaa@gmail.com> Wed Nov 5 16:54:26 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
|\  
| * c963b1e liviafviana <liviafvianaa@gmail.com> Wed Nov 5 16:46:48 2025 -0300 Update Hospede.h
* | 05dcf5c liviafviana <liviafvianaa@gmail.com> Wed Nov 5 16:51:38 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
|\| 
| * 7dfac7a helenabarbosaufmg <helenaobarbosa8@gmail.com> Wed Oct 22 22:19:52 2025 -0300 Update Sistema.h
| * 53fcc6e helenabarbosaufmg <helenaobarbosa8@gmail.com> Wed Oct 22 22:19:19 2025 -0300 Update Sistema.h
| * b4d7fed helenabarbosaufmg <helenaobarbosa8@gmail.com> Wed Oct 22 22:14:54 2025 -0300 Reserva.h
| * fa7547a marialuisabraga-ux <marialuisamalubraga@gmail.com> Wed Oct 22 19:09:01 2025 -0300 Update Quartos.h
| * 814d090 marialuisabraga-ux <marialuisamalubraga@gmail.com> Wed Oct 22 19:07:35 2025 -0300 Update Hospede.h
| * 2e4bfc9 Lilla Xavier <lilladelucas25@gmail.com> Tue Oct 21 23:46:49 2025 -0300 Update requisitos.md
| * f419ebd Lilla Xavier <lilladelucas25@gmail.com> Tue Oct 21 23:27:51 2025 -0300 Update cartoes.md
| * e179b7f Lilla Xavier <lilladelucas25@gmail.com> Tue Oct 21 18:45:08 2025 -0300 Update cartoes.md
| * eced6f0 Lilla Xavier <2025018341> Tue Oct 21 18:18:48 2025 -0300 teste
| * 2c3e488 Lilla Xavier <2025018341> Tue Oct 21 13:49:16 2025 -0300 Adiciona pasta com dois arquivos .md
* | e072303 liviafviana <liviafvianaa@gmail.com> Wed Nov 5 16:45:03 2025 -0300 Hospede.h e .cpp
|/  
* d5b8e90 liviafviana <liviafvianaa@gmail.com> Tue Oct 21 13:37:47 2025 -0300 Testes criados
* 7f0daec liviafviana <liviafvianaa@gmail.com> Tue Oct 21 13:29:10 2025 -0300 Arquivos h
* 3a3793f liviafviana <liviafvianaa@gmail.com> Tue Oct 21 13:25:26 2025 -0300 aqruivos .cpp
* af2a8e6 liviafviana <liviafvianaa@gmail.com> Tue Oct 21 10:18:16 2025 -0300 criação pasta src e arquivo main.cpp
* 4202139 liviafviana <liviafvianaa@gmail.com> Tue Oct 21 10:12:42 2025 -0300 mudança nome de arquivo
* c5228a2 liviafviana <liviafvianaa@gmail.com> Thu Oct 9 21:20:21 2025 -0300 Delete livia.txt
* 7ca768f marialuisabraga-ux <marialuisamalubraga@gmail.com> Thu Oct 9 21:08:18 2025 -0300 Update teste_malu.txt
* 4b85b65 Lilla Xavier <2025018341> Thu Oct 9 20:32:26 2025 -0300 lilla.txt
*   dd25cdf liviafviana <liviafvianaa@gmail.com> Thu Oct 9 20:16:58 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
|\  
| * ac829ec Lilla Xavier <lilladelucas25@gmail.com> Thu Oct 9 20:01:32 2025 -0300 Delete commitLILLA
| * 4108f45 marialuisabraga-ux <marialuisamalubraga@gmail.com> Thu Oct 9 19:31:08 2025 -0300 Create teste_malu.txt
* | b490bfb liviafviana <liviafvianaa@gmail.com> Thu Oct 9 20:16:32 2025 -0300 livia.txt
|/  
*   10bd4e9 liviafviana <liviafvianaa@gmail.com> Thu Oct 9 19:17:29 2025 -0300 Merge branch 'main' of https://github.com/helenabarbosaufmg/TP---pdsII
|\  
| * 282577f marialuisabraga-ux <marialuisamalubraga@gmail.com> Thu Oct 9 19:13:53 2025 -0300 Delete teste_malu.txt
* | bc27a6f liviafviana <liviafvianaa@gmail.com> Thu Oct 9 19:15:40 2025 -0300 Teste de commit livia
|/  
* bceec41 Lilla Xavier <lilladelucas25@gmail.com> Thu Oct 9 19:04:18 2025 -0300 Update teste_lilla.txt
* 3750236 Lilla Xavier <lilladelucas25@gmail.com> Thu Oct 9 18:59:16 2025 -0300 Create teste_lilla.txt
* 0c4bc1e Lilla Xavier <lilladelucas25@gmail.com> Thu Oct 9 18:51:29 2025 -0300 Create commitLILLA
* d7970e6 marialuisabraga-ux <marialuisamalubraga@gmail.com> Thu Oct 9 18:48:31 2025 -0300 Create teste_malu.txt
* 209d7a6 helenabarbosaufmg <helenaobarbosa8@gmail.com> Thu Oct 9 18:43:39 2025 -0300 README.md
* 9d6b8b4 helenabarbosaufmg <helenaobarbosa8@gmail.com> Thu Oct 9 18:43:01 2025 -0300  README.md
* 6b4db9f Helena de Oliveira Barbosa <helenaobarbosa8@gmail.com> Thu Oct 9 15:55:57 2025 -0300 test: commit de validação do fluxo - Helena
* 4da325a helenabarbosaufmg <helenaobarbosa8@gmail.com> Thu Oct 9 15:07:11 2025 -0300 Initial commit




