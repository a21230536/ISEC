-- 3. Nomes dos autores que escreveram livros do seu género preferido. 
SELECT nome
FROM autores, livros
WHERE livros.GENERO = autores.GENERO_PREFERIDO
AND livros.CODIGO_AUTOR = autores.CODIGO_AUTOR
ORDER BY nome DESC;
