-- FICHA 8
-- 10
-- Faça uma réplica da AUTORES usando o comando CREATE TABLE com subconsulta,
-- chamando à nova tabela AUTORES_BACKUP.

CREATE TABLE autores_backup AS (SELECT * FROM autores);
