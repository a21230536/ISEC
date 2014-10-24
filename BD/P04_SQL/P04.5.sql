-- P04
-- 5
-- Encontre a diferença entre os preços de tabela mais alto e mais baixo de cada
-- género.
/*
GENERO               Diferença
-------------------- ----------------------
Policial             34
Informática          17
Romance              47
Aventura             28
*/
SELECT GENERO, MAX(PRECO_TABELA) - MIN(PRECO_TABELA) "Diferença"
FROM LIVROS
GROUP BY GENERO;
