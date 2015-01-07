echo off
REM запуск программы 
"lab1.5.exe" < lab5.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt "lab5out.txt"
IF ERRORLEVEL 1 GOTO err
ECHO Program testing succeeded : -)
EXIT
:err
ECHO Program testing failed : -(
EXIT