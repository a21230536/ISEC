-- FICHA 8
-- 11
-- Adicione à tabela AUTORES_BACKUP a coluna NLIVROS do tipo NUMBER que irá
-- conter informação sobre a quantidade de livros escritos por esse autor. A nova coluna é
-- de preenchimento obrigatório, deve conter, por defeito, o valor 0 (zero) e deve permitir
-- armazenar apenas valores compreendidos entre 0 e 150.

ALTER TABLE autores_backup
ADD (nlivros NUMBER(3, 0) DEFAULT 0 NOT NULL,
    CONSTRAINT nlivros_limites CHECK (nlivros BETWEEN 0 AND 150));
