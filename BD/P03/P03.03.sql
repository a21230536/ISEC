-- P03
-- 03
-- Seleccione o título e o preço dos livros editados há menos de 365 dias.

SELECT titulo AS "Título", preco_tabela AS "Preço"
FROM livros
WHERE (sysdate - data_edicao) < 365;

/*
Título                                                  Preço
-------------------------------------------------- ----------
Microsoft Office 2000 sem fronteiras                       32
Windows NT Server 4 para profissionais                     40
Tecnologia dos Sistemas Distribuidos                       25
TCP/IP em redes Microsoft para profissionais               33
A balada de Nova Iorque                                    18
Tu, eu e mais uns quantos                                  33

 6 rows selected
*/
