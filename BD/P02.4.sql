-- 4. Mostrar título/preço_de_tabela dos livros adquiridos por clientes de Coimbra.
SELECT titulo, preco_tabela
FROM livros, clientes, vendas
WHERE clientes.morada LIKE '%Coimbra'
AND clientes.codigo_cliente = vendas.codigo_cliente
AND livros.codigo_livro = vendas.codigo_livro;
