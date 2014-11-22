-- FICHA 8
-- 14
-- Crie uma réplica da tabela EDITORAS, usando o comando CREATE TABLE com
-- subconsulta, chamando à nova tabela EDITORAS_BACKUP.

CREATE TABLE editoras_backup AS (SELECT * FROM editoras);