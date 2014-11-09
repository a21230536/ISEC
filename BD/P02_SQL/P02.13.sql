-- P02
-- 13
-- Mostre o título, o género e o nome do autor dos livros editados pela editora ‘FCA - EDITORA’.
-- O título do livro deverá aparecer em maiúsculas, o género em minúsculas e o nome do autor com 
-- a primeira letra maiúscula e o resto em minúsculas. Ordene o resultado por nome do autor.

SELECT UPPER(L.titulo) "TITULO (em maiúsculas)",
    LOWER(L.genero) "género (minúsc.)",
    SUBSTR(UPPER(A.nome),0,1)||SUBSTR(LOWER(A.nome),1-LENGTH(A.nome)) "Autor (1ª letra minúsc.)"
FROM livros L, autores A, editoras E
WHERE L.codigo_autor = A.codigo_autor
AND L.codigo_editora = E.codigo_editora
AND E.nome = 'FCA - EDITORA';

/*
TITULO (em maiúsculas)                             género (minúsc.)     Autor (1ª letra minúsc.)
-------------------------------------------------- -------------------- -------------------------------
MICROSOFT OFFICE 2000 SEM FRONTEIRAS               informática          Sérgio sousa
MICROSOFT OFFICE 2000 PARA TODOS                   informática          Sérgio sousa
FUNDAMENTAL DO WORD 2000                           informática          Vitor gonçalves
DOMINE A 110% WORD 2000                            informática          Carlos milheiro
O MISTÉRIO DA PORTA TRANCADA                       policial             Maria josé sousa
A OUTRA CARA METADE                                romance              Ana capucho
A VIZINHA DO LADO                                  romance              Rui vega
O CORSÁRIO NEGRO                                   aventura             Paulo loureiro
TCP/IP EM REDES MICROSOFT PARA PROFISSIONAIS       informática          Paulo loureiro
WINDOWS NT SERVER 4 PARA PROFISSIONAIS             informática          Paulo loureiro
WINDOWS NT SERVER 4 CURSO COMPLETO                 informática          Samuel santos
TECNOLOGIA DOS SISTEMAS DISTRIBUIDOS               informática          Alves marques
REDES LOCAIS EM WINDOWS 98 E 95                    informática          Cláudio tereso
TECNOLOGIA DE BASE DE DADOS                        informática          José luis pereira

 14 rows selected
*/
