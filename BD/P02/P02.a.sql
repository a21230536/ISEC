-- P02
-- a
-- Seleccione o título e o género dos livros que não sejam policiais ou
-- romances, assim como todos os livros em que o título comece pela letra ‘O’.

SELECT titulo, genero
FROM livros
WHERE NOT (genero = 'Policial' OR genero = 'Romance')
OR titulo LIKE 'O%';

/*
TITULO                                             GENERO
-------------------------------------------------- --------------------
Microsoft Office 2000 para todos                   Informática
Microsoft Office 2000 sem fronteiras               Informática
Fundamental do Word 2000                           Informática
Domine a 110% Word 2000                            Informática
Windows NT Server 4 para profissionais             Informática
Windows NT Server 4 Curso Completo                 Informática
Tecnologia dos Sistemas Distribuidos               Informática
TCP/IP em redes Microsoft para profissionais       Informática
Redes Locais em Windows 98 e 95                    Informática
Tecnologia de Base de Dados                        Informática
O mistério da porta trancada                       Policial
Os cinco na praia                                  Aventura
O Corsário Negro                                   Aventura
Tu, eu e mais uns quantos                          Aventura
Oracle 8 - Curso completo                          Informática

 15 rows selected
*/
