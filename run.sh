#!/bin/bash 
#
# Compila e roda grafos
#

echo "clean before build";
make clean;

echo "";
echo "build";
make;

echo "";
echo "Run, Forest, run...";
echo "";
./trabalho_01;
