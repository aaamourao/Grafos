/**
 *
 * Trabalho 01 - Algoritmos com grafos 
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 * */

#include "grafo.h"

using namespace std;

graf_bib::grafo::grafo( Matriz matrixGrafo ) 
    : matrizRep(matrixGrafo) {
    
    numVertices = matrizRep.size() * matrizRep.begin()->size();
    
    for(Matriz::const_iterator linha = matrizRep.begin(); 
            linha != matrizRep.end(); 
            ++linha) {
        
        if(linha->size()!= matrizRep.size())
            throw onError("Tamanho matriz");


        for(Linha::const_iterator it = linha->begin(); 
                it != linha->end(); 
                ++it) {

            // Isto nao trata se ha arestas para o proprio vertice
            if(*it == 1) 
                ++numArestas;
        }
    }
}

unsigned int graf_bib::grafo::retNumVertices() {

    return numVertices;
}

unsigned int graf_bib::grafo::retNumArestas() {
    
    return numArestas;
}

bool graf_bib::grafo::completo() {

    bool ret = true;

    if(numArestas != numVertices*(numVertices -1)/2 )
        ret = false;

    return ret;
}

string graf_bib::onError( string Falha ) {

    return "Erro: " + Falha;
}
