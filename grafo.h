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

#include <vector>
#include <string>

namespace graf_bib {
    class grafo {
        private:
           unsigned int numVertices;
           unsigned int numArestas;
        
            const std::vector < std::vector <int> > matrizRep;

        public:
            grafo (std::vector < std::vector <int> > matrixGrafo);

            unsigned int retNumVertices();
            unsigned int retNumArestas();

            bool completo();
    };

    std::string onError(std::string Falha);
}

#endif // GRAFO_H 
