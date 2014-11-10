-- P03
-- 02
-- Obtenha o seguinte output:
/*
Hora Actual Data Actual
----------- ----------------------------------------------
01:06:46    10, Novembro , 2014
*/

SELECT
    TO_CHAR(sysdate, 'hh24:mi:ss') "Hora Actual",
    TO_CHAR(sysdate, 'dd, Month, yyyy') "Data Actual"
FROM dual;
