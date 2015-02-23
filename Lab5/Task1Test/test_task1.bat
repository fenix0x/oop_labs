@echo off
task1.exe < shapes.txt > res.txt
IF ERRORLEVEL 1 GOTO err
FC /B res.txt "test.txt"
IF ERRORLEVEL 1 GOTO err
ECHO Program testing succeeded : -)
EXIT
:err
ECHO Program testing failed : -(
EXIT