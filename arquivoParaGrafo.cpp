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

        ifstream arq(nome_arq.c_str());

        string linha;
        while(getline(arq, linha)) {
            
            istringstream stream(linha);
            
            matrizGrafo.push_back(
                    Linha( istream_iterator<int>(stream),
                    istream_iterator<int>() ));
        }

        arq.close();
}

graf_bib::Matriz graf_bib::arquivoParaGrafo::retMatriz(void) {
    
    return matrizGrafo;
}
