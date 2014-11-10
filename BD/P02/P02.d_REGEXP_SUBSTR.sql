-- P02
-- d (REGEXP_SUBSTR)
-- Quais os clientes que compraram livros editados pela FCA-EDITORA escritos por
-- autores que moram na mesma cidade.

SELECT DISTINCT L.titulo "Livro", C.nome "Nome do Cliente", A.nome "Nome do Autor"
    --,REGEXP_SUBSTR(A.morada, '[a-zA-Z]+$') "Cidade"
FROM livros L, clientes C, autores A, editoras E, vendas V
WHERE V.codigo_cliente = C.codigo_cliente
AND V.codigo_livro = L.codigo_livro
AND L.codigo_editora = E.codigo_editora
AND L.codigo_autor = A.codigo_autor
AND E.nome = 'FCA - EDITORA'
AND REGEXP_SUBSTR(C.morada, '[a-zA-Z]+$') = REGEXP_SUBSTR(A.morada, '[a-zA-Z]+$')
ORDER BY A.nome DESC;


/*
Livro                                              Nome do Cliente                Nome do Autor
-------------------------------------------------- ------------------------------ ------------------------------
Microsoft Office 2000 para todos                   Manuela Tinto                  Sérgio Sousa
Microsoft Office 2000 para todos                   Pedro Antunes                  Sérgio Sousa
TCP/IP em redes Microsoft para profissionais       Manuela Tinto                  Paulo Loureiro
Windows NT Server 4 para profissionais             Manuela Tinto                  Paulo Loureiro
Windows NT Server 4 para profissionais             Vitor Pereira                  Paulo Loureiro
*/
