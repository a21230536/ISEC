-- FICHA 8
-- 9
-- Apague da tabela LIVROS_BACKUP, os livros de informática que tem um preço inferior
-- à média dos preços de informática.

DELETE FROM livros_backup
WHERE preco_tabela < (SELECT AVG(preco_tabela)
    FROM livros_backup
    WHERE genero = 'INFORMÁTICA'
    GROUP BY genero)
AND genero = 'INFORMÁTICA';
