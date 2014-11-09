-- P02
-- 15
-- Para os livros Policiais, mostre o título, o preço e o preço com um aumento de
-- 13,55%. O preço depois do aumento deverá ser arredondado na primeira casa
-- decimal.

SELECT titulo,
    preco_tabela,
    ROUND(preco_tabela*1.1355, 1) AS preco_com_aumento
FROM livros
WHERE genero = 'Policial';

/*
TITULO                                             PRECO_TABELA PRECO_COM_AUMENTO
-------------------------------------------------- ------------ -----------------
O mistério da porta trancada                                 29              32,9
A balada de Hill Street                                      50              56,8
A balada de Nova Iorque                                      18              20,4
*/
