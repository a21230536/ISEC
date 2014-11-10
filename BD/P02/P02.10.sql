-- P02
-- 10
-- Obtenha o título em maiúsculas, minúsculas e com a primeira letra de cada
-- palavra maiúscula e restantes minúsculas dos livros editados.

SELECT UPPER(titulo) "Letras Maiúsculas",
  LOWER(titulo) "Letras Minúsculas",
  INITCAP(LOWER(titulo)) "1ª Letra Maiúscula/Palavra"
FROM livros;

/*
Letras Maiúsculas                                  Letras Minúsculas                                  1ª Letra Maiúscula/Palavra                       
-------------------------------------------------- -------------------------------------------------- --------------------------------------------------
MICROSOFT OFFICE 2000 PARA TODOS                   microsoft office 2000 para todos                   Microsoft Office 2000 Para Todos                   
MICROSOFT OFFICE 2000 SEM FRONTEIRAS               microsoft office 2000 sem fronteiras               Microsoft Office 2000 Sem Fronteiras               
FUNDAMENTAL DO WORD 2000                           fundamental do word 2000                           Fundamental Do Word 2000                           
DOMINE A 110% WORD 2000                            domine a 110% word 2000                            Domine A 110% Word 2000                            
WINDOWS NT SERVER 4 PARA PROFISSIONAIS             windows nt server 4 para profissionais             Windows Nt Server 4 Para Profissionais             
WINDOWS NT SERVER 4 CURSO COMPLETO                 windows nt server 4 curso completo                 Windows Nt Server 4 Curso Completo                 
TECNOLOGIA DOS SISTEMAS DISTRIBUIDOS               tecnologia dos sistemas distribuidos               Tecnologia Dos Sistemas Distribuidos               
TCP/IP EM REDES MICROSOFT PARA PROFISSIONAIS       tcp/ip em redes microsoft para profissionais       Tcp/Ip Em Redes Microsoft Para Profissionais       
REDES LOCAIS EM WINDOWS 98 E 95                    redes locais em windows 98 e 95                    Redes Locais Em Windows 98 E 95                    
TECNOLOGIA DE BASE DE DADOS                        tecnologia de base de dados                        Tecnologia De Base De Dados                        
O MISTÉRIO DA PORTA TRANCADA                       o mistério da porta trancada                       O Mistério Da Porta Trancada                       
OS CINCO NA PRAIA                                  os cinco na praia                                  Os Cinco Na Praia                                  
A OUTRA CARA METADE                                a outra cara metade                                A Outra Cara Metade                                
A BALADA DE HILL STREET                            a balada de hill street                            A Balada De Hill Street                            
A BALADA DE NOVA IORQUE                            a balada de nova iorque                            A Balada De Nova Iorque                            
O CORSÁRIO NEGRO                                   o corsário negro                                   O Corsário Negro                                   
TU, EU E MAIS UNS QUANTOS                          tu, eu e mais uns quantos                          Tu, Eu E Mais Uns Quantos                          
ORACLE 8 - CURSO COMPLETO                          oracle 8 - curso completo                          Oracle 8 - Curso Completo                          
A VIZINHA DO LADO                                  a vizinha do lado                                  A Vizinha Do Lado                                  

 19 rows selected
*/
