-- P01
-- 11. Seleccionar o título de todos os livros excepto os policiais.
SELECT titulo
FROM livros
WHERE genero <> 'Policial';
-- ou: WHERE genero != 'Policial';
