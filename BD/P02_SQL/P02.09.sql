-- P02
-- 9
-- Para os livros com um número de páginas entre 400 e 700, calcule o custo por
-- página arredondado à 2ª casa decimal e o valor inteiro (em euros) superior e
-- inferior. O resultado deve ser ordenado pelo custo por página.

SELECT titulo "Título",
  TO_CHAR(ROUND(preco_tabela/paginas, 2), '0D99') "Custo/página",
  CEIL(preco_tabela/paginas) "Superior",
  FLOOR(preco_tabela/paginas) "Inferior"
FROM livros
WHERE paginas BETWEEN 400 AND 700
ORDER BY 2;

/*
Título                                             Custo/página   Superior   Inferior
-------------------------------------------------- ------------ ---------- ----------
Microsoft Office 2000 para todos                    0,05                 1          0
Microsoft Office 2000 sem fronteiras                0,05                 1          0
Tecnologia dos Sistemas Distribuidos                0,05                 1          0
Tecnologia de Base de Dados                         0,05                 1          0
O Corsário Negro                                    0,06                 1          0
Windows NT Server 4 para profissionais              0,06                 1          0
Windows NT Server 4 Curso Completo                  0,07                 1          0
Oracle 8 - Curso completo                           0,08                 1          0
TCP/IP em redes Microsoft para profissionais        0,08                 1          0
A balada de Hill Street                             0,10                 1          0

 10 rows selected
*/
