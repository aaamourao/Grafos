/**
 *
 * Trabalho 01 - Algoritmos com grafos 
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#include "arquivoParaGrafo.h"

#include <sstream>
#include <iterator>

using namespace std;

graf_bib::arquivoParaGrafo::arquivoParaGrafo(string nome_arq) 
    : nomeArq(nome_arq) {

        arq.open(nome_arq.c_str());

        string linha;
        while(getline(arq, linha)) {
            
            istringstream stream(linha);
            
            matrizGrafo.push_back(
                    Linha( istream_iterator<int>(stream),
                    istream_iterator<int>() ));
        }

}

graf_bib::Matriz graf_bib::arquivoParaGrafo::retMatriz(void) {
    
    return matrizGrafo;
}

string graf_bib::arquivoParaGrafo::toString(void) {

    string ret = "";

    for(Matriz::const_iterator linha = matrizGrafo.begin(); 
            linha != matrizGrafo.end(); 
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
