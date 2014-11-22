-- FICHA 8
-- 8
-- Actualize, na tabela LIVROS_BACKUP, os preços dos livros de aventuras de modo a
-- que estes sofram um aumento em 10%.

UPDATE livros_backup
SET preco_tabela = preco_tabela*1.1
WHERE genero = 'AVENTURA';
