@echo off 
setlocal enabledelayedexpansion
for /r %%a in (*.h) do (
  set "x=%%a"
  echo !x:%cd%\=!
)