-- P02
-- 12
-- Para cada autor, obtenha o nome completo, o seu primeiro e o último nome.

SELECT nome "Nome Completo",
  SUBSTR(nome, 0, INSTR(nome, ' ') - 1) "Primeiro Nome",
  SUBSTR(nome, INSTR(nome, ' ', -1) + 1) "Último Apelido"
FROM autores;

/*
Nome Completo                  Primeiro Nome                  Último Apelido
------------------------------ ------------------------------ ------------------------------
Sérgio Sousa                   Sérgio                         Sousa
Vitor Gonçalves                Vitor                          Gonçalves
Carlos Milheiro                Carlos                         Milheiro
Maria José Sousa               Maria                          Sousa
Luis Gomes                     Luis                           Gomes
Fernando Tavares               Fernando                       Tavares
Pedro Coelho                   Pedro                          Coelho
Ana Capucho                    Ana                            Capucho
Tânia Azevedo                  Tânia                          Azevedo
Christian Crumush              Christian                      Crumush
Rui Lemos                      Rui                            Lemos
Vitor Beça                     Vitor                          Beça
Robert Cowart                  Robert                         Cowart
Eurico Fonseca                 Eurico                         Fonseca
Norberto Candeias              Norberto                       Candeias
Rui Vega                       Rui                            Vega
Paulo Loureiro                 Paulo                          Loureiro
Samuel Santos                  Samuel                         Santos
Alves Marques                  Alves                          Marques
Cláudio Tereso                 Cláudio                        Tereso
José Luis Pereira              José                           Pereira

 21 rows selected
*/
