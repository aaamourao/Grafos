#
#	Trabalho 01 - Algoritmos com grafos
#
#	Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
#	Tamires Vargas
#


all: trabalho_01

trabalho_01: main.o grafo.o gMatriz.o
	g++ main.o grafo.o gMatriz.o -o trabalho_01

main.o: main.cpp
	g++ -c main.cpp

grafo.o: grafo.cpp
	g++ -std=c++11 -c grafo.cpp

gMatriz.o: gMatriz.cpp
	g++ -std=c++11 -c gMatriz.cpp

clean:
	rm -rf *o .*.swp trabalho_01

