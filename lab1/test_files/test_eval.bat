echo off
REM запуск программы без параметров
"eval.exe" 
IF ERRORLEVEL 1 GOTO err
REM запуск программы с одним нечисловым параметром
"eval.exe" notANumber 
IF NOT ERRORLEVEL 3 GOTO err
REM запуск программы с пустой строкой в качестве одного из параметров
"eval.exe" "" 
IF NOT ERRORLEVEL 3 GOTO err
REM запуск программы с одним числовым параметром
"eval.exe" -123 
IF NOT ERRORLEVEL 0 GOTO err
REM запуск программы с одним знаком параметром
"eval.exe" + 
IF NOT ERRORLEVEL 3 GOTO err
REM запуск программы с одним числом и одним знаком
"eval.exe" 1 + 
IF NOT ERRORLEVEL 1 GOTO err
REM запуск программы с одним знаком и одним числом
"eval.exe" - 1
IF NOT ERRORLEVEL 1 GOTO err
REM запуск программы со знаком в конце и четным числом аргументов
"eval.exe" 3 - 1 /
IF NOT ERRORLEVEL 1 GOTO err
REM запуск программы со знаком в конце и нечетным числом аргументов
"eval.exe" 3 - 1 / *
IF NOT ERRORLEVEL 3 GOTO err
REM запуск программы с двумя знаками подряд и четным числом аргументов
"eval.exe" 3 - / 1
IF NOT ERRORLEVEL 1 GOTO err
REM запуск программы с двумя числами подряд и четным числом аргументов
"eval.exe" 3 - 3 1
IF NOT ERRORLEVEL 1 GOTO err
REM запуск программы с двумя знаками подряд и нечетным числом аргументов
"eval.exe" 3 - / 1 +
IF NOT ERRORLEVEL 1 GOTO err
REM запуск программы с двумя числами подряд и нечетным числом аргументов
"eval.exe" 3 - 3 1 -
IF NOT ERRORLEVEL 1 GOTO err
REM запуск программы с выражением
eval.exe 13 + 7 / 8 * 3.8 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt "1.txt"
IF ERRORLEVEL 1 GOTO err
REM запуск программы с выражением
eval.exe 1 + 1 * 5 / 3 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt "2.txt"
IF ERRORLEVEL 1 GOTO err
REM запуск программы с делением на 0
eval.exe 1 + 1 * 5 / 0 
IF NOT ERRORLEVEL 4 GOTO err
ECHO Program testing succeeded : -)
EXIT
:err
ECHO Program testing failed : -(
EXIT