-- P02
-- f
-- O mesmo que no exercício número 16, mas com o preço depois do aumento
-- arredondado para um número inteiro.

SELECT titulo,
    preco_tabela,
    ROUND(preco_tabela*1.1355) AS preco_com_aumento
FROM livros
WHERE genero = 'Policial';

/*
TITULO                                             PRECO_TABELA PRECO_COM_AUMENTO
-------------------------------------------------- ------------ -----------------
O mistério da porta trancada                                 29                33 
A balada de Hill Street                                      50                57 
A balada de Nova Iorque                                      18                20
*/
