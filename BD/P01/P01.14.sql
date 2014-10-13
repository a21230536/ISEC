-- P01
-- 14. Apresentar o nome dos autores que contenham as letras ‘r’ e ‘d’.
SELECT nome
FROM autores
WHERE nome LIKE '%r%'
OR nome LIKE '%d%';
