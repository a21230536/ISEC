-- 3. Qual o nome dos autores que escreveram livros do seu género preferido. 
SELECT nome
FROM autores, livros
WHERE livros.genero = autores.genero_preferido
AND livros.CODIGO_AUTOR = autores.CODIGO_AUTOR
ORDER BY nome DESC;
