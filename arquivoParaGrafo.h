/**
 *
 * Trabalho 01 - Algoritmos com grafos 
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#ifndef ARQUIVOPARAGRAFO_H
#define ARQUIVOPARAGRAFO_H

#include <fstream>
#include "grafo.h"

namespace graf_bib {

    class arquivoParaGrafo {

        private:
            const std::string nomeArq;
            Matriz matrizGrafo;

        public:
            arquivoParaGrafo(std::string nome_arq);
            Matriz retMatriz(void);
            std::string toString(void);  
    };
}

#endif // ARQUIVOPARAGRAFO_H
