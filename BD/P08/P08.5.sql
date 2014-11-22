-- FICHA 8
-- 5
-- Insira, na tabela LIVROS_BACKUP, o novo livro do Sérgio Sousa, cujo título é
-- ‘Informática para todos’ e que foi editado hoje pela FCA. O livro custa 24€ e tem 430
-- páginas, tendo-lhe sido atribuído o ISBN 132434 e o código 51. Ainda não foi vendida
-- qualquer unidade deste livro.

INSERT INTO livros_backup (
    codigo_livro,
    codigo_editora,
    codigo_autor,
    titulo,
    isbn,
    genero,
    preco_tabela,
    paginas,
    unidades_vendidas)
VALUES (
    51, 
    (SELECT codigo_editora FROM editoras WHERE nome LIKE 'FCA%'),
    (SELECT codigo_autor FROM autores WHERE nome = 'Sérgio Sousa'),
    'Informática para todos',
    132434,
    'Informática',
    24,
    480,
    0);
