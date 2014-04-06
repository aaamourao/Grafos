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
#include <vector>
#include <list>
#include <set>

namespace graf_bib {

  class grafo : public gMatriz {
    private:
     unsigned int numVertices;
     unsigned int numArestas;
     unsigned int simples;
     std::vector<std::string> corVertice;
     void bfs_visit(const unsigned int &indice, 
         Caminho &vistados, Caminho &fifo);
     void dfs_visit(const unsigned int &indice, 
         Caminho &vistados);

    public:
      grafo(std::string arquivo);

      unsigned int retNumVertices(void);
      unsigned int retNumArestas(void);
      Matriz retMatriz();

      bool completo(void);
      Matriz completarGrafo(void);
      std::list<unsigned int> bfs (unsigned int indiceInicial);
      std::list<unsigned int> dfs (unsigned int indiceInicial);
      unsigned int num_componentes (void);
      bool hamiltoniano (void);
  };
}

#endif // GRAFO_H
