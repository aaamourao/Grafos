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
#include <map>

namespace graf_bib {

  class grafo : public gMatriz {
    private:
     unsigned int numVertices;
     unsigned int numArestas;
     
     std::vector<std::string> corVertice;
     std::map<unsigned int, unsigned int> peso;
     
     void bfs_visit(const unsigned int &indice, 
         Caminho &vistados, Caminho &fifo);
     void dfs_visit(const unsigned int &indice, 
         Caminho &vistados);
     
     unsigned int extract_min(Caminho &queue);

    public:
      grafo(std::string arquivo);

      unsigned int retNumVertices(void);
      unsigned int retNumArestas(void);
      Matriz retMatriz();

      bool completo(void);
      Matriz completarGrafo(void);
      
      Caminho bfs(unsigned int indiceInicial);
      Caminho dfs(unsigned int indiceInicial);
      Caminho dijkstra(unsigned int verInicial, unsigned int verFinal); 
      
      unsigned int num_componentes (void);
      
      bool hamiltoniano (void);

  };
}

#endif // GRAFO_H
