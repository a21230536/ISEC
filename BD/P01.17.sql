-- P01
-- 17. Obter o seguinte output:
/*
Listagem de Livros
-------------------------------------------------------------------------------------
O livro "Microsoft Office 2000 para todos" custa 27 euros.
O livro "Microsoft Office 2000 sem fronteiras" custa 32 euros.
  ...
O livro "Oracle 8 - Curso completo" custa 25 euros.
O livro "A vizinha do lado" custa 25 euros.
  20 rows selected
*/
SELECT 'O livro "' || titulo || '" custa ' || preco_tabela || ' euros.' "Listagem de Livros" 
FROM livros;
