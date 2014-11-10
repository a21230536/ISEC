-- P02
-- b
-- Obtenha o seguinte output: ...

SELECT titulo "Titulo",
  TO_CHAR(preco_tabela) "Preco em euros",
  TO_CHAR(ROUND(preco_tabela*200.42, 2)) "Preco em Escudos"
FROM livros;

/*
Titulo                                             Preco em euros                           Preco em Escudos
-------------------------------------------------- ---------------------------------------- ----------------------------
Microsoft Office 2000 para todos                   28                                       5611,76
Microsoft Office 2000 sem fronteiras               32                                       6413,44
Fundamental do Word 2000                           24                                       4810,08
Domine a 110% Word 2000                            22                                       4409,24
Windows NT Server 4 para profissionais             40                                       8016,8
Windows NT Server 4 Curso Completo                 32                                       6413,44
Tecnologia dos Sistemas Distribuidos               25                                       5010,5
TCP/IP em redes Microsoft para profissionais       33                                       6613,86
Redes Locais em Windows 98 e 95                    22                                       4409,24
Tecnologia de Base de Dados                        25                                       5010,5
O mistério da porta trancada                       29                                       5812,18
Os cinco na praia                                  10                                       2004,2
A outra cara metade                                71                                       14229,82
A balada de Hill Street                            50                                       10021
A balada de Nova Iorque                            18                                       3607,56
O Corsário Negro                                   27                                       5411,34
Tu, eu e mais uns quantos                          33                                       6613,86
Oracle 8 - Curso completo                          44                                       8818,48
A vizinha do lado                                  45                                       9018,9

 19 rows selected
*/
