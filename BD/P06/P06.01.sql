-- Mostre o seguinte output (o Total de Livros, Total de Autores,
-- Total de Editoras que existem nas respectivas tabelas):
/*
Total de Livros Total de Autores Total de Editoras
--------------- ---------------- -----------------
             20               21                 3
*/
SELECT L.t "Total de Livros", A.t "Total de Autores", E.t "Total de Editoras"
FROM (SELECT COUNT(livros.codigo_livro) t FROM livros) L,
     (SELECT COUNT(autores.codigo_autor) t FROM autores) A,
     (SELECT COUNT(editoras.codigo_editora) t FROM editoras) E;
