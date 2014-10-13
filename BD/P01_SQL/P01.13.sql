-- P01
-- 13. Mostrar o nome dos autores cuja idade seja superior a 30 anos e o género
--     preferido seja o Policial. Ordenar o resultado ascendentemente pelo nome.
SELECT nome
FROM autores
WHERE idade > 30
AND genero_preferido = 'Policial'
ORDER BY nome ASC;
