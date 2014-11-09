-- P02
-- 14
-- Quais os livros cujo título tem mais de 20 caracteres.

SELECT titulo "Título"
FROM livros
WHERE LENGTH(titulo) > 20;

/*
Título
--------------------------------------------------
Microsoft Office 2000 para todos
Microsoft Office 2000 sem fronteiras
Fundamental do Word 2000
Domine a 110% Word 2000
Windows NT Server 4 para profissionais
Windows NT Server 4 Curso Completo
Tecnologia dos Sistemas Distribuidos
TCP/IP em redes Microsoft para profissionais
Redes Locais em Windows 98 e 95
Tecnologia de Base de Dados
O mistério da porta trancada
A balada de Hill Street
A balada de Nova Iorque
Tu, eu e mais uns quantos
Oracle 8 - Curso completo

 15 rows selected
*/
