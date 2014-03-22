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

graf_bib::grafo::grafo( vector < vector <int> > matrixGrafo ) 
    : matrizRep(matrixGrafo) {
    
    numVertices = matrizRep.size() * matrizRep.begin()->size();
    
    for(vector< vector<int> >::const_iterator it = matrizRep.begin(); 
            it != matrizRep.end(); 
            ++it) {
        
        if(it->size()!= matrizRep.size())
            throw onError("Tamanho matriz");
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

    for(vector< vector<int> >::const_iterator linha = matrizRep.begin(); 
            linha != matrizRep.end(); 
            ++linha) {
        for(vector<int>::const_iterator it = linha->begin(); 
                it != linha->end(); 
                ++it) {

            if(*it != 1) {
                ret = false;
                break;
            }
        }
    }

    return ret;
}

string graf_bib::onError( string Falha ) {

    return "Erro: " + Falha;
}
