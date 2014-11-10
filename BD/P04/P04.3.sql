-- P04
-- 3
-- Mostre quantos livros existem para cada género. Ordene o resultado pelo género.
/*
Genero       Quantidade
------------ ----------
Aventura     3
Informática  11
Policial     3
Romance      3
*/
SELECT GENERO "Genero", COUNT(*) "Quantidade"
FROM LIVROS
GROUP BY GENERO;
