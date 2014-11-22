-- FICHA 8
-- 4
-- Como ao criar a nova tabela LIVROS_BACKUP as restrições não são copiadas altere a
-- tabela de modo a incluir as restrições que existiam na tabela LIVROS original. Use o
-- comando ALTER TABLE.

ALTER TABLE livros_backup
ADD CONSTRAINT codigo_livro_pk PRIMARY KEY (codigo_livro);

ALTER TABLE livros_backup
ADD CONSTRAINT codigo_editora_fk FOREIGN KEY (codigo_editora)
    REFERENCES editoras (codigo_editora);

ALTER TABLE livros_backup
ADD CONSTRAINT codigo_autor_fk FOREIGN KEY (codigo_autor)
    REFERENCES autores (codigo_autor);
