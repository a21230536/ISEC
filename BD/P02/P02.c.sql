-- P02
-- c
-- Construa o seguinte output: ...

SELECT LPAD(' '||RPAD(titulo||' ', (LENGTH(titulo)+50)/2, '<'), 50,'>') "Título Centrado"
FROM livros;

/*
Título Centrado
--------------------------------------------------
>>>>>>>> Microsoft Office 2000 para todos <<<<<<<<
>>>>>> Microsoft Office 2000 sem fronteiras <<<<<<
>>>>>>>>>>>> Fundamental do Word 2000 <<<<<<<<<<<<
>>>>>>>>>>>>> Domine a 110% Word 2000 <<<<<<<<<<<<
>>>>> Windows NT Server 4 para profissionais <<<<<
>>>>>>> Windows NT Server 4 Curso Completo <<<<<<<
>>>>>> Tecnologia dos Sistemas Distribuidos <<<<<<
>> TCP/IP em redes Microsoft para profissionais <<
>>>>>>>>> Redes Locais em Windows 98 e 95 <<<<<<<<
>>>>>>>>>>> Tecnologia de Base de Dados <<<<<<<<<<
>>>>>>>>>> O mistério da porta trancada <<<<<<<<<<
>>>>>>>>>>>>>>>> Os cinco na praia <<<<<<<<<<<<<<<
>>>>>>>>>>>>>>> A outra cara metade <<<<<<<<<<<<<<
>>>>>>>>>>>>> A balada de Hill Street <<<<<<<<<<<<
>>>>>>>>>>>>> A balada de Nova Iorque <<<<<<<<<<<<
>>>>>>>>>>>>>>>> O Corsário Negro <<<<<<<<<<<<<<<<
>>>>>>>>>>>> Tu, eu e mais uns quantos <<<<<<<<<<<
>>>>>>>>>>>> Oracle 8 - Curso completo <<<<<<<<<<<
>>>>>>>>>>>>>>>> A vizinha do lado <<<<<<<<<<<<<<<

 19 rows selected
*/
