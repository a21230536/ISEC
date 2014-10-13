-- P01
-- 6. Seleccionar o título dos livros policiais com mais de 500 páginas.
SELECT titulo
FROM livros
WHERE genero = 'Policial'
AND paginas > 500;
