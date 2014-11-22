-- FICHA 8
-- 3
-- Faça uma cópia da tabela LIVROS para uma nova tabela LIVROS_BACKUP. Use o
-- comando CREATE TABLE com subconsulta. Na cópia de valores transforme os géneros
-- dos livros para maiúsculas. Note que como está a produzir alterações sobre algumas
-- colunas irá ter que usar pseudónimos para a tabela LIVROS_BACKUP possuir colunas
-- com nomes válidos.

CREATE TABLE LIVROS_BACKUP AS
    (SELECT
        CODIGO_LIVRO,
        CODIGO_EDITORA,
        CODIGO_AUTOR,
        TITULO,
        ISBN,
        UPPER(GENERO) AS GENERO,
        PRECO_TABELA,
        PAGINAS,
        QUANT_EM_STOCK,
        UNIDADES_VENDIDAS,
        DATA_EDICAO
    FROM LIVROS);
