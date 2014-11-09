-- P02
-- 12 (alternativa)
-- Para cada autor, obtenha o nome completo, o seu primeiro e o último nome.

SELECT nome "Nome Completo",
    REPLACE(nome, REGEXP_SUBSTR(nome, ' [a-z A-Z]+ ') , ' ') "Primeiro e Último Nome",
    REGEXP_SUBSTR(nome, '^[a-zA-Z]+') "Primeiro Nome",
    REGEXP_SUBSTR(nome, '[a-zA-Z]+$') "Último Nome"
FROM autores;

/*
Nome Completo                  Primeiro e Último Nome         Primeiro Nome                  Último Nome                
------------------------------ ------------------------------ ------------------------------ ---------------------------
Sérgio Sousa                   Sérgio Sousa                   Sérgio                         Sousa                      
Vitor Gonçalves                Vitor Gonçalves                Vitor                          Gonçalves                  
Carlos Milheiro                Carlos Milheiro                Carlos                         Milheiro                   
Maria José Sousa               Maria Sousa                    Maria                          Sousa                      
Luis Gomes                     Luis Gomes                     Luis                           Gomes                      
Fernando Tavares               Fernando Tavares               Fernando                       Tavares                    
Pedro Coelho                   Pedro Coelho                   Pedro                          Coelho                     
Ana Capucho                    Ana Capucho                    Ana                            Capucho                    
Tânia Azevedo                  Tânia Azevedo                  Tânia                          Azevedo                    
Christian Crumush              Christian Crumush              Christian                      Crumush                    
Rui Lemos                      Rui Lemos                      Rui                            Lemos                      
Vitor Beça                     Vitor Beça                     Vitor                          Beça                       
Robert Cowart                  Robert Cowart                  Robert                         Cowart                     
Eurico Fonseca                 Eurico Fonseca                 Eurico                         Fonseca                    
Norberto Candeias              Norberto Candeias              Norberto                       Candeias                   
Rui Vega                       Rui Vega                       Rui                            Vega                       
Paulo Loureiro                 Paulo Loureiro                 Paulo                          Loureiro                   
Samuel Santos                  Samuel Santos                  Samuel                         Santos                     
Alves Marques                  Alves Marques                  Alves                          Marques                    
Cláudio Tereso                 Cláudio Tereso                 Cláudio                        Tereso                     
José Luis Pereira              José Pereira                   José                           Pereira                    

 21 rows selected
*/
