markdown

# Repository Name

Questo repository contiene vari programmi in c++ che utilizzano librerie esterne come boost/asio, windows.h ecc

## Installazione

### Linux

#### Utilizzando lo script di installazione

Per installare le dipendenze e configurare l'ambiente di sviluppo su Linux, eseguire lo script di installazione fornito:

```bash
./install.sh
```
Questo installerà il compilatore C++, strumenti di sviluppo essenziali, CMake (opzionale), Git (opzionale), le librerie Boost e, se desiderato, Visual Studio Code.
Utilizzando CMake

Se si preferisce utilizzare CMake per compilare il progetto:

```bash
mkdir build
cd build
cmake ..
make
```


Windows

Per clonare e compilare il progetto su Windows con git, seguire questi passaggi:

installare git,

Clonare il repository:

```bash

git clone https://github.com/riccio8/examples-of-program-in-c-
```

Aprire il progetto nella tua IDE preferita o utilizzare il prompt dei comandi.

Configurare e compilare il progetto utilizzando il tuo compilatore C++ preferito.

Utilizzo

Dopo aver compilato il progetto, eseguire l'eseguibile generato. Il programma si metterà in ascolto su una porta specifica per le connessioni in ingresso tramite socket TCP.
Contributi

Se trovi bug o hai suggerimenti per migliorare il progetto, non esitare a inviare una pull request o aprire un'issue.


Licenza

https://github.com/riccio8/examples-of-program-in-c-
