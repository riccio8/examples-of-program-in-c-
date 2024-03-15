# this is the docker engine
# it will allow you tu run the block script also on linux, because the problem is that the filebloc.cpp call a function in the library windows.h, that is present only on windows
# insteaad, with docker, you can virtualize your application and run everywhere
# this is an experiment and i'll test it if it works 
  
FROM mcr.microsoft.com/windows/servercore:ltsc2019

COPY block.cpp .

RUN cl /EHsc block.cpp /link /out:main.exe


CMD ["block.exe"]
CMD ["echo", "docker run successfully"]
