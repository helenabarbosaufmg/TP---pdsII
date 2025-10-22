Elaboração da modelagem inicial (Cartões CRC): 
Classes de domínio: 
RESERVA:
- Responsabilidades: guarda dados dos hóspedes, do quarto e das datas; calcula o valor final da reserva; altera o status da reserva (pendente, checked-in, checkout etc);
- Colaboradores: Quarto, Hóspede, Sistema.
HOSPEDE:
- Responsabilidades: armazena quantidade de pessoas, nomes, CPF's, contato(email ou telefone);
- Colaboradores: Reserva.
QUARTO:
- Responsabilidades: armazena número do apartamento, tipo de quarto e dias; verifica a ocupação(está ocupado, não está ocupado)
- Colaboradores: Reserva.
SISTEMA:
- Responsabilidades: cria, cancela e lista reservas; verifica a disponibilidade de quartos;
- Colaboradores: Quarto, Reserva. 

