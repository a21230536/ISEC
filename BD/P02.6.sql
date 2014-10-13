-- 6. Mostrar, para cada autor, quais os livros que escreveu cujos géneros não são o género preferido do autor.
--    Ordenar o resultado pelo nome do autor.
SELECT nome "NOME DO AUTOR", titulo, genero
FROM livros, autores
WHERE livros.codigo_autor = autores.codigo_autor
AND genero <> genero_preferido -- ou: genero != genero_preferido
ORDER BY nome;
