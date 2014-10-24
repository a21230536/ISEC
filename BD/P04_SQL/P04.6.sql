-- P04
-- 6
-- Para cada título mostre o seu preço de tabela, quantos livros foram vendidos, a
-- receita esperada (por vender o livro ao preço de tabela) e a receita efectivamente
-- realizada (receita obtida através da venda do livro a um preço diferente do preço
-- de tabela).
/*
TITULO                               PRECO NUM_VENDIDOS REC_ESPERADA REC_EFECTIVA
------------------------------------ ----- ------------ ------------ ------------
Fundamental do Word 2000             24    5            120          15
Tecnologia dos Sistemas Distribuidos 25    23           575          69
Domine a 110% Word 2000              22    2            44           6
...
Redes Locais em Windows 98 e 95      22    16           352          40
7 rows selected ...
*/
SELECT TITULO,
	AVG(PRECO_TABELA) AS preco,
	SUM(QUANTIDADE) AS num_vendidos,
	SUM(QUANTIDADE)*AVG(PRECO_TABELA) AS rec_esperada,
	SUM(PRECO_UNITARIO*QUANTIDADE) AS rec_efectiva
FROM LIVROS,VENDAS
WHERE LIVROS.CODIGO_LIVRO = VENDAS.CODIGO_LIVRO
GROUP BY TITULO;

-- AVG(PRECO_TABELA) <=> SUM(PRECO_TABELA)/COUNT(PRECO_TABELA)
