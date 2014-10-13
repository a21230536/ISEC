-- P01
-- 7. Seleccionar os géneros dos livros que tenham mais de 700 páginas ou preço de
--    tabela superior a 45.
SELECT titulo
FROM livros
WHERE paginas > 700
OR preco_tabela > 45;
