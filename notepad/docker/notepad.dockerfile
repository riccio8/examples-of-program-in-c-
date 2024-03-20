# I NEED TO TEST that engine, it isn't complited yet 
# the exe file and the docker egine must be in the same folder in the same path


FROM ubuntu:latest # u can choose another version or distribution

RUN dpkg --add-architecture i386 && \
    apt-get update && \
    apt-get install -y wine

COPY programma.exe /programma.exe

CMD ["wine", "/programma.exe"]
