cd /d "%~dp0"
set PATH=%~dp0;%PATH%
premake5 --file=easyhook.lua vs2015
premake5 --file=easyhook.lua vs2005
