-- P01
-- 5. Mostrar o código e o título dos livros do género Informática.
SELECT codigo_livro, titulo
FROM livros
WHERE genero = 'Informática';
-- WHERE LOWER(genero) = 'informática';
