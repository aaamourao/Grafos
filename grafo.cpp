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

            if(*it >= 1)
                numArestas += *it;
        }
    }

    numArestas = numArestas/2;
}

unsigned int graf_bib::grafo::retNumVertices(void) {

    return numVertices;
}

unsigned int graf_bib::grafo::retNumArestas(void) {
    
    return numArestas;
}


graf_bib::Matriz graf_bib::grafo::retMatriz() {

    return matrizRep;
}

bool graf_bib::grafo::completo(void) {

    bool ret = true;

    if(numArestas != (numVertices*(numVertices -1))/2 )
        ret = false;

    else {
        for(Matriz::const_iterator linha = matrizRep.begin(); 
                linha != matrizRep.end(); 
                ++linha) {
        
            for(Linha::const_iterator it = linha->begin(); 
                    it != linha->end(); 
                    ++it) {

                if(*it != 1 && 
                    (linha - matrizRep.begin()) != (it - linha->begin()) ) {
                    ret = false;
                    break;
                }
                else if (*it != 0 && 
                    (linha - matrizRep.begin()) == (it - linha->begin()) ) {
                    ret = false;
                    break;
                }
                        
            }
        }
    }

    return ret;
}


graf_bib::Matriz graf_bib::grafo::completarGrafo(void) {

    Matriz *ret = NULL;

    if(!completo()) {
        
        ret = new Matriz(matrizRep);
        
        for(Matriz::iterator linha = ret->begin(); 
                linha != ret->end(); 
                ++linha) {

            for(Linha::iterator it = linha->begin(); 
                    it != linha->end(); 
                    ++it) {

                if(*it == 0 && 
                    (linha - ret->begin()) != (it - linha->begin()) ) 
                    *it = 1;

                else 
                    *it = 0;
            }
        }
    }

    return *ret;
}

string graf_bib::toString(Matriz mGrafo) {

    string ret = "";

    for(Matriz::const_iterator linha = mGrafo.begin(); 
            linha != mGrafo.end(); 
            ++linha) {
     
        for(Linha::const_iterator it = linha->begin(); 
                it != linha->end(); 
                ++it) {

            ret += to_string(*it) + " ";
        }

        ret += "\n";
    }

    return ret;
}

string graf_bib::onError( string Falha ) {
 
    cout << "Erro: " + Falha + "\n";
    return "Erro: " + Falha + "\n";
}
