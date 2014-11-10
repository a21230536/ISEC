-- P04
-- 2
-- Escreva um comando que conte o número de livros editados, calcule o preço 
-- médio dos livros e o total de livros vendidos.
/*
Total de Livros Preço Médio  Total de livros vendidos 
--------------- ------------ ------------------------
20              30,5         924096
*/
SELECT COUNT(*) "Total de Livros",
	AVG(PRECO_TABELA) "Preço Médio",
	SUM(UNIDADES_VENDIDAS) "Total de livros vendidos"
FROM LIVROS;
