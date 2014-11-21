-- FICHA 8
-- 2
-- Pretende-se que passe a ser possível aos clientes da livraria avaliarem os livros que
-- esta disponibiliza. A avaliação consistirá na atribuição de um número de estrelas
-- compreendido entre 1 (livro muito mau) e 5 (livro muito bom). Crie a nova tabela
-- AVALIACOES que permita registar esta informação, de acordo com o diagrama abaixo.

CREATE TABLE AVALIACOES (
    CODIGO_LIVRO NUMBER(4, 0),
    CODIGO_CLIENTE NUMBER(4, 0),
    NOTA NUMBER(1, 0),
    CONSTRAINT CODIGO_LIVRO_CLIENTE_pk
        PRIMARY KEY (CODIGO_LIVRO, CODIGO_CLIENTE),
    CONSTRAINT CODIGO_LIVRO_fk
        FOREIGN KEY (CODIGO_LIVRO)
        REFERENCES LIVROS(CODIGO_LIVRO),
    CONSTRAINT CODIGO_CLIENTE_fk
        FOREIGN KEY (CODIGO_CLIENTE)
        REFERENCES CLIENTES (CODIGO_CLIENTE));
