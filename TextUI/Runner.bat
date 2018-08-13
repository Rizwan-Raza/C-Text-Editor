@echo off
prompt Rex:$g 
REM runs only if g++ command is added to the path variable
:label
cls
g++ -Irizzu Text_UI.cpp -o Text_UI
pause 
Text_UI
echo Want to Run it again ? If Yes, Press any key else Ctrl+C or close this window
pause >nul
goto label