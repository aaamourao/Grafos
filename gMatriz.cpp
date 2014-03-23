/**
 *
 * Trabalho 01 - Algoritmos com grafos 
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#include "gMatriz.h"

#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

graf_bib::gMatriz::gMatriz(string nome_arq) 
    : nomeArq(nome_arq) {

        ifstream arq(nome_arq.c_str());

        string linha;
        while(getline(arq, linha)) {
            
            istringstream stream(linha);
            
            matrizRep.push_back(
                    Linha( istream_iterator<int>(stream),
                    istream_iterator<int>() ));
        }

        arq.close();
}

graf_bib::Matriz graf_bib::gMatriz::retMatriz(void) {
    
    return matrizRep;
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
