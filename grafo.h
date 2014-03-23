/**
 *
 * Trabalho 01 - Algoritmos com grafos 
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#ifndef GRAFO_H
#define GRAFO_H

#include "gMatriz.h"

namespace graf_bib {

    class grafo : public gMatriz {
        private:
           unsigned int numVertices;
           unsigned int numArestas;
        
        public:
            grafo(std::string arquivo);

            unsigned int retNumVertices(void);
            unsigned int retNumArestas(void);
            Matriz retMatriz();
            std::string toString(void);

            bool completo(void);
            Matriz completarGrafo(void);
    };
}

#endif // GRAFO_H 
