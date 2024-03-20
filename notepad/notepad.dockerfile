# I NEED TO TEST that engine, it isn't complited yet 

FROM mcr.microsoft.com/windows/servercore:ltsc2019

COPY pnotepad.exe /notepad.exe

CMD ["cmd", "/c", "C:\\programma.exe"]
