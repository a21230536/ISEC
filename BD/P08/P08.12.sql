-- FICHA 8
-- 12
-- Actualize o campo NLIVROS adicionado no ponto anterior, com a informação do número
-- de livros que cada autor escreveu.

UPDATE autores_backup
SET nlivros = NVL((SELECT COUNT(*)
              FROM livros_backup
              WHERE autores_backup.codigo_autor = livros_backup.codigo_autor
              GROUP BY autores_backup.codigo_autor), 0);
