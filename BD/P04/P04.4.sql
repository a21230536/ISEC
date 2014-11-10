-- P04
-- 4
-- Para cada livro de Informática, encontre o preço mais baixo, mais alto e médio a
-- que foi vendido:
/*
TITULO                                 P_MAIS_BAIXO P_MAIS_ALTO P_MEDIO
-------------------------------------- ------------ ----------- ----------------------
Domine a 110% Word 2000                3            3           3
Fundamental do Word 2000               3            3           3
Microsoft Office 2000 para todos       0            45          16,43
Redes Locais em Windows 98 e 95        2            3           2,5
...
Windows NT Server 4 para profissionais 3             30         16,5

7 rows selected
*/
SELECT TITULO,
	MIN(PRECO_UNITARIO) preco_mais_baixo,
	MAX(PRECO_UNITARIO) preco_mais_alto,
	ROUND(AVG(PRECO_UNITARIO),2) preco_mai_baixo
FROM LIVROS, VENDAS
WHERE LIVROS.CODIGO_LIVRO = VENDAS.CODIGO_LIVRO
GROUP BY TITULO;
