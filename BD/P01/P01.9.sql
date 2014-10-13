-- P01
-- 9. Mostrar o ISBN, o título, preço de tabela e quantidade em stock dos livros de
--    Informática, ordenados descendentemente pelo preço de tabela e
--    ascendentemente pela quantidade em stock.
SELECT isbn, titulo, preco_tabela, quant_em_stock
FROM livros
ORDER BY preco_tabela DESC, quant_em_stock ASC;
