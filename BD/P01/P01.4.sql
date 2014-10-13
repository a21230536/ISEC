-- P01
-- 4. Seleccionar o título dos livros cujo preço de tabela esteja entre 25 e 35.
SELECT titulo
FROM livros
WHERE preco_tabela BETWEEN 25 AND 35;
-- ou: WHERE preco_tabela >= 25 AND preco_tabela <= 35;
