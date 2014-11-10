-- P02
-- e
-- Mostre o título dos livros escritos por autores cujo último nome seja Loureiro.

SELECT L.titulo
FROM livros L, autores A
WHERE L.codigo_autor = A.codigo_autor
AND A.nome LIKE '%Loureiro';

/*
TITULO
--------------------------------------------------
TCP/IP em redes Microsoft para profissionais
Windows NT Server 4 para profissionais
O Corsário Negro
*/
