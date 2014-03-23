/**
 *
 * Trabalho 01 - Algoritmos com grafos 
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 * */

#include <iostream>
#include "grafo.h"
#include "arquivoParaGrafo.h"

using namespace std;

int main () {

    graf_bib::arquivoParaGrafo vMtrxGrafo01("grafo01.txt");
    graf_bib::grafo grafo01(vMtrxGrafo01.retMatriz());

    cout << vMtrxGrafo01.toString() << endl;
    if(grafo01.completo()) {
        cout << "O grafo 01 e completo!" << endl;
        cout << "======================" << endl << endl;
    }

    graf_bib::arquivoParaGrafo vMtrxGrafo02("grafo02.txt");
    graf_bib::grafo grafo02(vMtrxGrafo02.retMatriz());

    cout << vMtrxGrafo02.toString() << endl;
    if(grafo02.completo())
        cout << "O grafo 02 e completo!" << endl;

    return 0;
}
