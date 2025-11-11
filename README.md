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

## 11. Exemplos de Uso (Entradas e Saídas)

### **Opção 1 (cadastrar novo quarto)**
Entrada:
```
1
```
Saída: 
```
Cadastro de Quarto
Numero do quarto: 01
Tipo (ex: Solteiro, Casal, Luxo): Casal
Preco da diaria: 120
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

Digite o numero do quarto para este hospede:
```
Entrada:
```
1
```
Saída:
```
 Dados do Hospede
Codigo do hospede: 01
Nome: Joao Silva
RG: 12345678990
Telefone: 31912345678
Email: joaosilva@gmail.com
Hospede cadastrado com sucesso.
```
Saída:
```
Data de check-in: 12/11/2025
Data de check-out: 15/11/2025
Reserva criada com sucesso!
```

### **Opção 3 (Pesquisar numero de reserva)**
Entrada:
```
3
```
Saída:
```
Digite o numero da reserva: 01
```
Saída:
```
Dados da Reserva
Numero da reserva: 1
Status: Agendada
Check-in: 12/11/2025
Check-out: 15/11/2025

Hospede:
Nome: Joao Silva
RG: 12345678990
Telefone: 31912345678
Email: joaosilva@gmail.com

Quarto:
Numero: 1
Tipo: Solteiro
Preco diaria: R$ 120
```

### **Opção 4 (Cadastrar nova reserva de hospede ja previamente cadastrado)**
Entrada:
```
4
```
Saída:
```
Codigo do hospede (ja cadastrado):
```
Entrada: 
```
1
```
Saída:
```
Dados do H├│spede:
Codigo: 1
Nome: Joao Silva
RG: 12345678990
Telefone: 31912345678
Email: joaosilva@gmail.com

Quartos cadastrados:
Quarto 1 - Tipo: Solteiro - Preco: R$ 120 - Status: OCUPADO

Digite o numero do quarto para nova reserva (ou 0 para cadastrar um novo quarto):
```
Entrada:
``` 
0
```
Saída:
```
Cadastro de Novo Quarto
Numero do quarto: 02
Tipo (ex: Solteiro, Casal, Luxo): Casal
Preco da diaria: 350
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
Quarto 1 - Tipo: Solteiro - Preco: R$ 120 - Status: OCUPADO
``` 
### **Opção 6 (Ocupar quarto)**
Entrada:
```
6
```
Saída:
```
Numero do quarto a ocupar: 
```
Entrada:
```
1
```
Saída: 
```
Quarto 1 ja esta OCUPADO.
```

### **Opção 7 (Liberar quarto)**
Entrada:
```
7
```
Saída:
```
Numero do quarto a liberar:
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


## 12. Programação Defensiva (Malu) 
(...) 

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

- **Commits:** registro de todas as alterações com autoria individual.
- **Issues:** utilizadas para distribuir tarefas e acompanhar progresso.
- **Milestones:** criadas para organizar entregas por sprint.
- **Pull Requests:** revisões e integração de código entre membros.
- **Release final:** tag `v1.0.0` com código testado, documentação e vídeo de execução.





