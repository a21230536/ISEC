-- P01
-- 8. Mostrar o título de todos os livros de Informática ordenados descendente pelo
--    preço.
SELECT titulo
FROM livros
WHERE genero = 'Informática'
ORDER BY preco_tabela DESC;
