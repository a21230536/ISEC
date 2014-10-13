-- 1. Mostrar o título dos livros Policiais do autor Cláudio Tereso.
SELECT titulo "Livros de Cláudio Tereso"
FROM livros, autores
WHERE autores.nome = 'Cláudio Tereso'
AND livros.genero = 'Policial'
AND livros.codigo_autor = autores.codigo_autor;
