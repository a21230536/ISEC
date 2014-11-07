-- P06
-- 2
-- Para cada autor, mostre a quantidade total de livros que editou e quantos editou
-- pela editora ‘FCA – EDITORA’.
/*
Resultado
------------------------------------------------------------------------------------
O autor Alves Marques escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor Ana Capucho escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor Carlos Milheiro escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor Cláudio Tereso escreveu 2 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor Eurico Fonseca escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor José Luis Pereira escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor Maria José Sousa escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor Paulo Loureiro escreveu 3 livro(s) e 3 sob a alçada da editora FCA-EDITORA
O autor Rui Vega escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor Samuel Santos escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA
O autor Sérgio Sousa escreveu 2 livro(s) e 2 sob a alçada da editora FCA-EDITORA
O autor Vitor Gonçalves escreveu 1 livro(s) e 1 sob a alçada da editora FCA-EDITORA

 12 linhas seleccionadas
*/
SELECT 'O autor '||autores.nome||' escreveu '||X.t||' livro(s) e '
    ||Y.t||' sob a alçada da editora FCA-EDITORA' AS "Resultado"
FROM autores, (SELECT codigo_autor,
               COUNT(titulo) t
               FROM livros
               GROUP BY codigo_autor) X,
              (SELECT codigo_autor,
               COUNT(titulo) t
               FROM livros
               WHERE codigo_editora = (SELECT codigo_editora
                                       FROM editoras
                                       WHERE nome = 'FCA - EDITORA')
               GROUP BY codigo_autor) Y
WHERE autores.codigo_autor = X.codigo_autor
AND autores.codigo_autor = Y.codigo_autor;
