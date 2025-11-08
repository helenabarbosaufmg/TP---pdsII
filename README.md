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
  
**OUTROS:**:

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

## 10. Instruções de uso 
Ao executar **make run**, será exibido: 
SISTEMA DO HOTEL 
1 - Cadastrar novo hóspede
2 - Pesquisar hóspede
3 - Pesquisar número de reserva
4 - Cadastrar novo quarto
5 - Status de reservas (Listar quartos)
6 - Ocupar quarto
7 - Liberar quarto
0 - Sair
Escolha: 

**CASO 1:** 
Será exibido: 
Cadastro de Hóspede
Código: 
Nome: 
RG: 
Telefone: 
Email: 

O usuário deve completar as informações do hóspede e caso seja feito de forma correta, aparecerá: 
Hóspede cadastrado com sucesso! 

**CASO 2:**
Será exibido: 
Digite o número do código: 

Caso o código seja encontrado, serão exibidas as informações do hóspede correspondente a essa reserva. Caso o código não seja encontrado, será exibido "Hóspede não encontrado". 

**CASO 3:**
Será exibido: 
"Digite o número da reserva: "
Caso a reserva seja encontrada, aparecerá no menu os dados da reserva (status, check-in, check-out), dados do hóspede e os dados do quarto. Caso a reserva não seja encontrada, será exibido: "Reserva não encontrada."

**CASO 4:**
Será exibido: 
Cadastro de Quarto
Número do quarto: 





