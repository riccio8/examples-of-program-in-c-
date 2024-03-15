# this is the docker engine
# it will allow you tu run the block script also on linux, because the problem is that the filebloc.cpp call a function in the library windows.h, that is present only on windows
# insteaad, with docker, you can virtualize your application and run everywhere
# this is an experiment and i'll test it if it works 
  
FROM mcr.microsoft.com/windows/servercore:ltsc2019 AS builder

SHELL ["powershell", "-Command", "$ErrorActionPreference = 'Stop'; $ProgressPreference = 'SilentlyContinue';"]

WORKDIR /app

COPY block.cpp .

RUN cl /EHsc block.cpp /link /out:block.exe

# using wine for running exe bin on linux
FROM i386/debian:buster-slim

RUN dpkg --add-architecture i386 && \
    apt-get update && \
    apt-get install -y --no-install-recommends wine && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/block.exe .

CMD ["wine", "block.exe"]
CMD ["echo", "Esecuzione di Docker riuscita"]
