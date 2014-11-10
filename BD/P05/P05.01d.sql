-- P05
-- 01
-- Qual o livro de Informática mais caro (preço de tabela mais elevado).
--
-- d) Utilizando subquery na cláusula FROM

SELECT x.titulo, x.preco_tabela
FROM livros x, (SELECT MAX(preco_tabela) M FROM livros WHERE genero = 'Informática') y
WHERE x.genero = 'Informática'
AND x.preco_tabela = y.M;

/*
TITULO                                             PRECO_TABELA
-------------------------------------------------- ------------
Oracle 8 - Curso completo                                    44
*/
