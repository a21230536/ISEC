-- P05
-- 01
-- Qual o livro de Informática mais caro (preço de tabela mais elevado).
--
-- c) Usando o Exists

SELECT x.titulo, x.preco_tabela
FROM livros x
WHERE NOT EXISTS(SELECT Y.preco_tabela
    FROM livros y
    WHERE y.preco_tabela > x.preco_tabela
    AND y.genero = 'Informática')
AND x.genero = 'Informática';

/*
TITULO                                             PRECO_TABELA
-------------------------------------------------- ------------
Oracle 8 - Curso completo                                    44
*/
