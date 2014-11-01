-- P05
-- 1
-- Qual o livro de Informática mais caro (preço de tabela mais elevado).
/*
TITULO                                             PRECO_TABELA
-------------------------------------------------- ----------------------
Windows NT Server 4 para profissionais             39
*/
-- a) Usando o Max
SELECT titulo, preco_tabela
FROM livros
WHERE genero = 'Informática'
AND preco_tabela = ( SELECT MAX(preco_tabela)
	FROM livros
	WHERE genero = 'Informática');
