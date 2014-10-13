-- P01
-- 12. Seleccionar o título de todos os livros excepto os policiais, usando o NOT.
SELECT titulo
FROM livros
WHERE NOT genero = 'Policial';
