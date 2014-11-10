-- P03
-- 04
-- Mostre os livros adquiridos no intervalo de Dezembro de 2013 a Janeiro de 2014 por clientes de Lisboa.

SELECT titulo
FROM livros, clientes, vendas
WHERE vendas.codigo_livro = livros.codigo_livro
AND vendas.codigo_cliente = clientes.codigo_cliente
AND clientes.morada LIKE '%Lisboa'
AND data_venda BETWEEN TO_DATE('2013-12-01') AND TO_DATE('2014-01-30');

-- ou

SELECT titulo
FROM livros, clientes, vendas
WHERE vendas.codigo_livro = livros.codigo_livro
AND vendas.codigo_cliente = clientes.codigo_cliente
AND clientes.morada LIKE '%Lisboa'
AND ((TO_CHAR(vendas.data_venda, 'yyyy') = '2013' AND TO_CHAR(data_venda, 'mm') = '12')
    OR (TO_CHAR(data_venda, 'yyyy') = '2014' AND TO_CHAR(data_venda, 'mm') = '01'));

/*
TITULO
--------------------------------------------------
Windows NT Server 4 para profissionais
Microsoft Office 2000 para todos
Tecnologia dos Sistemas Distribuidos
Redes Locais em Windows 98 e 95
*/
