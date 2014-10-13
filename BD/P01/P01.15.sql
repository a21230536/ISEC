-- P01
-- 15. Seleccionar o título dos livros que começam por ‘O’ e contêm a sequência de
--     letras ‘st’ e também os que começam por ‘M’ e contém a sequência ‘to’.
SELECT titulo
FROM livros
WHERE titulo LIKE 'O%st%'
OR titulo LIKE 'M%to%';
