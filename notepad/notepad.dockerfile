
FROM mcr.microsoft.com/windows/servercore:ltsc2019

COPY pnotepad.exe /notepad.exe

CMD ["cmd", "/c", "C:\\programma.exe"]
