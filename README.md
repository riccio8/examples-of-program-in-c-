# C++ program

This repository contains various C++ programs that utilize external libraries such as `boost/asio`, `windows.h`, etc.

## Installation

### Linux

#### Using the installation script

To install dependencies and set up the development environment on Linux, navigate in the correct path (#!\bin) and run the provided installation script:

```bash
cd #!\bin\
bash install.sh
```

This will install the C++ compiler, essential development tools, CMake (optional), Git (optional), Boost libraries, and, if desired, Visual Studio Code.
Using CMake

If you prefer using CMake to build the project:

```bash

mkdir build
cd build
cmake ..
make
```
### Windows

To clone and compile the project on Windows using git, follow these steps:

Install git.

Clone the repository:

```bash
git clone https://github.com/riccio8/examples-of-program-in-c-
```

Open the project in your preferred IDE or use the command prompt.

Configure and build the project using your preferred C++ compiler and download the boost asio library from here:

```bash
https://www.boost.org/doc/libs/1_84_0/doc/html/boost_asio.html
```

or from here:

```bash
https://think-async.com/Asio/Download.html
```

### Docker

In this repository, a Docker container has been set up to run the script `block.cpp`. The Docker container is configured using a Dockerfile named `block.dockerfile`.
Instructions

Building the Docker Image:

```bash
docker build -t cpp-windows-container -f block.dockerfile .
```

Running the Docker Container:

```bash
docker run --rm cpp-windows-container
```
Notes

    The Dockerfile sets up the environment to compile and execute block.cpp on a Windows-based Docker 
    container so YOUR OS MUST BE WINDOWS if you want to run docker with this engine.
    
    Ensure that Docker is installed and running on your system before following the above steps.
    Replace cpp-windows-container with your preferred image name if desired.

`Instead` if u want to run the notepad exe on linux-based OS you must use the docker-engine file that I gave in the notepad directory
    As for the other program, ensure that you are on the right directory and than build and run the docker container:
build:

    ```bash
    docker build -t notepad-container -f notepad.dockerfile.
    ```

run

    ```bash 
    docker run --rm -it notepad-container
    ```
    
### `I NEED TO TEST THIS TYPE OF INSTALLATION`

## Usage

After compiling the project, run the generated executable. 

## Contributions

If you find bugs or have suggestions to improve the project, feel free to submit a pull request or open an issue.


## License

```bash 
https://github.com/riccio8/examples-of-program-in-c-
```


## IMPORTANT!

You have to include file header, precompiled library, executable, dynamic and static library and so on when you download the file, because all this files are exclude in the .gitignore file
