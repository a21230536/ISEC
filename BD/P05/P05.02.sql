-- P05
-- 2
-- Quais os autores que publicaram livros com mais do que o número médio de páginas por
-- livro.
/*
NOME
------------------------------
Alves Marques
Ana Capucho
Cláudio Tereso
Fernando Tavares
José Luis Pereira
Paulo Loureiro
Robert Cowart
Rui Lemos
Sérgio Sousa
Vitor Beça

10 rows selected
*/
SELECT DISTINCT nome
FROM autores, livros
WHERE paginas > (SELECT AVG(paginas) FROM livros)
AND livros.codigo_autor = autores.codigo_autor;
