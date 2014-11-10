-- P04
-- 7
-- Mostre o preço de tabela médio de cada género de livro, ordenando os
-- resultados por ordem crescente dos preços médios. O preço médio deverá ser
-- arredondado para o menor inteiro possível que seja superior ou igual ao seu
-- valor. Apenas deverão ser mostrados os géneros com mais do que 4 títulos.
/*
GENERO               Preço Médio
-------------------- ----------------------
Informática          28
*/
-- AMBIGUIDADE em "menor inteiro possível que seja superior ou igual ao seu valor"
-- "o seu valor" = y = 29.73...
-- "inteiro superior ou igual ao seu valor" = CEIL(y) = 30
-- "menor inteiro possível" de 30 ? REDUNDANTE!
-- FLOOR(CEIL(y)) = FLOOR(30) = 30
SELECT GENERO, CEIL(AVG(PRECO_TABELA)) "Preço Médio"
FROM LIVROS
GROUP BY GENERO
HAVING COUNT(GENERO) > 4
ORDER BY "Preço Médio" ASC;
