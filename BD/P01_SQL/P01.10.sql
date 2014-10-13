-- P01
-- 10. Códigos dos autores cujos livros existem na livraria.
SELECT DISTINCT codigo_autor
FROM livros
WHERE quant_em_stock > 0;
