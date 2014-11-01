-- P05
-- 3
-- Quais os autores que publicaram mais livros do que a média de livros por autor.
/*
NOME
------------------------------
Cláudio Tereso
Sérgio Sousa
Paulo Loureiro
*/
SELECT nome
FROM autores, livros
WHERE livros.codigo_autor = autores.codigo_autor
HAVING count(nome) > (SELECT AVG(COUNT(*))
	FROM livros
	GROUP BY codigo_autor)
GROUP BY nome;
