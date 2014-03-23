#
#	Trabalho 01 - Algoritmos com grafos
#
#	Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
#	Tamires Vargas
#


all: trabalho_01

trabalho_01: main.o grafo.o arquivoParaGrafo.o
	g++ main.o grafo.o arquivoParaGrafo.o -o trabalho_01

main.o: main.cpp
	g++ -c main.cpp

grafo.o: grafo.cpp
	g++ -c grafo.cpp

arquivoParaGrafo.o: arquivoParaGrafo.cpp
	g++ -std=c++11 -c arquivoParaGrafo.cpp

clean:
	rm -rf *o .*.swp trabalho_01

