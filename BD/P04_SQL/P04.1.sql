-- P04
-- 1. Escreva um comando que determine quantos livros de Informática existem. O 
--    resultado deve ser semelhante ao que se segue.
/*
Total de livros de Informática
------------------------------
11
*/
SELECT COUNT(*) AS "Total de livros de Informática"
FROM LIVROS
WHERE GENERO = 'Informática';
