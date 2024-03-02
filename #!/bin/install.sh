#!/bin/bash

# This script installs essential tools and libraries for C++ development on Linux.

# Update package lists
sudo apt update

# Install the C++ compiler
sudo apt install g++

# Install build essentials
sudo apt install build-essential

# Install CMake (optional but commonly used)
sudo apt install cmake

# Install Git (optional but commonly used for version control)
sudo apt install git

# Install additional libraries (optional depending on your project requirements)
# Example: Boost C++ Libraries
sudo apt install libboost-all-dev

# Optionally, you can install an IDE for C++ development
# Example: Visual Studio Code
sudo apt install code

echo "C++ development environment setup completed."
