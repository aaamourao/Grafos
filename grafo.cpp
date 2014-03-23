/**
 *
 * Trabalho 01 - Algoritmos com grafos 
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 * */

#include "grafo.h"
#include <iostream>

using namespace std;

graf_bib::grafo::grafo( Matriz matrixGrafo ) 
    : matrizRep(matrixGrafo) {
    
    numVertices = matrizRep.size();
    numArestas = 0;

    for(Matriz::const_iterator linha = matrizRep.begin(); 
            linha != matrizRep.end(); 
            ++linha) {
        
        if(linha->size()!= matrizRep.size())
            throw onError("Matriz deve ser quadrada");


        for(Linha::const_iterator it = linha->begin(); 
                it != linha->end(); 
                ++it) {

            if(*it == 1 && 
                    (linha - matrizRep.begin()) != (it - linha->begin()) ) 
                ++numArestas;
        }
    }

    numArestas = numArestas/2;
}

unsigned int graf_bib::grafo::retNumVertices() {

    return numVertices;
}

unsigned int graf_bib::grafo::retNumArestas() {
    
    return numArestas;
}

bool graf_bib::grafo::completo() {

    bool ret = true;

    if(numArestas != (numVertices*(numVertices -1))/2 )
        ret = false;

    return ret;
}

string graf_bib::onError( string Falha ) {
 
    cout << "Erro: " + Falha + "\n";
    return "Erro: " + Falha + "\n";
}
