-- 5. Mostrar quais os autores que compraram livros na livraria.
SELECT DISTINCT autores.NOME
FROM autores, clientes, vendas
WHERE vendas.CODIGO_CLIENTE = clientes.CODIGO_CLIENTE
AND autores.N_CONTRIBUINTE = clientes.N_CONTRIBUINTE;
