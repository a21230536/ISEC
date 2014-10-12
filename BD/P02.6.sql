-- 6. Mostre, para cada autor, quais os livros que escreveu cujos géneros não são o género preferido do autor. Ordene o resultado pelo nome do autor.
SELECT nome "NOME DO AUTOR", titulo, genero, autores.GENERO_PREFERIDO
FROM livros, autores
WHERE livros.codigo_autor = autores.codigo_autor
--AND genero != genero_preferido
AND genero <> genero_preferido
ORDER BY nome;