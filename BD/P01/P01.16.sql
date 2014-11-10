-- P01
-- 16. Seleccione o título dos livros dos géneros policiais, romances e aventura.
SELECT titulo
FROM livros
WHERE genero = 'Policial'
OR genero = 'Romance'
OR genero = 'Aventura';
