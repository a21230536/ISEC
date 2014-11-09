-- 2. Mostrar o título dos livros Policiais escritos por autores de Coimbra.
SELECT livros.TITULO
FROM autores, livros
WHERE livros.GENERO = 'Policial'
AND autores.MORADA LIKE '%Coimbra'
AND autores.CODIGO_AUTOR = livros.CODIGO_AUTOR;
