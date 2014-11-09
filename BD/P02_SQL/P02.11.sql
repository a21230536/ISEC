-- P02
-- 11
-- Obtenha o título dos livros de informática, independentemente do modo como o
-- género foi escrito (maiúsculas ou minúsculas).

SELECT titulo AS "Titulo"
FROM livros
WHERE LOWER(genero) = 'informática';

/*
Titulo
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
Oracle 8 - Curso completo

 11 rows selected
*/
