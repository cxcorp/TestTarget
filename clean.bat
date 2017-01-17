@echo off

WHERE nmake
IF %ERRORLEVEL% NEQ 0 ECHO ERROR! nmake was not found, please run this script from the Developer Comman Prompt for VS2015"

nmake clean /F NMakefile