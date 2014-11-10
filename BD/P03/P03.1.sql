-- P03
-- 1
-- Obtenha os títulos editados em 2011.

SELECT titulo
FROM livros
WHERE TO_CHAR(data_edicao, 'YYYY') = 2011;

-- ou

SELECT titulo
FROM livros
WHERE EXTRACT(year FROM data_edicao) = 2011;

/*
TITULO
--------------------------------------------------
Domine a 110% Word 2000
*/
