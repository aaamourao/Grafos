/**
 *
 * Trabalho 01 - Algoritmos com grafos
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 * */

#include "grafo.h"
#include <algorithm>
#include <limits>

#include <iostream>

using namespace std;

graf_bib::grafo::grafo( string arquivo )
    : gMatriz(arquivo) {

  numVertices = matrizRep.size();
  numArestas  = 0;
  
  corVertice.resize(numVertices, "branco"); 

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

        if(linha - ret->begin() != it - linha->begin())
          *it = 1;

        else
          *it = 0;
      }
    }
  }

  return *ret;
}

graf_bib::Caminho graf_bib::grafo::bfs (unsigned int verticeInicial) {

  Caminho fifo;
  Caminho *visitados = NULL;
  
  for (unsigned int vertice = 0;
      vertice < numVertices; 
      ++vertice) {

    corVertice[vertice] = "branco";
  }
  
  visitados = new Caminho();
  bfs_visit(verticeInicial, *visitados, fifo);

  return *visitados;
}

void graf_bib::grafo::bfs_visit(const unsigned int &vertice,
                      Caminho &visitados, Caminho &fifo) {

  corVertice[vertice] = "cinza";
	
  Matriz *ret = new Matriz(matrizRep);
  Matriz::iterator linha = ret->begin() + vertice;

  for(Linha::iterator it = linha->begin(); it != linha->end(); ++it) {
		
    if (*it >= 1) {

      int indiceAdj = it -(linha->begin());

      if (corVertice[indiceAdj] == "branco") {
        fifo.push_back(indiceAdj);
        corVertice[indiceAdj] = "cinza";
      }
    }
  }
  corVertice[vertice] = "preto";
  visitados.push_back(vertice);

  if(!fifo.empty()) {
    unsigned int proxVertice = fifo.front();
    fifo.pop_front();

    bfs_visit(proxVertice, visitados, fifo);
  }
}

graf_bib::Caminho graf_bib::grafo::dfs (unsigned int verticeInicial) {

  Caminho *visitados = NULL;

  for (unsigned int vertice = 0;
      vertice < numVertices; 
      ++vertice) {

    corVertice[vertice] = "branco";
  }
  
  visitados = new Caminho();
  dfs_visit(verticeInicial, *visitados);

  return *visitados;
}

void graf_bib::grafo::dfs_visit(const unsigned int &vertice,
                      Caminho &visitados) {

  corVertice[vertice] = "cinza";
	
  Matriz *ret = new Matriz(matrizRep);
  Matriz::iterator linha = ret->begin() + vertice;

  visitados.push_back(vertice);

  for(Linha::iterator it = linha->begin(); it != linha->end(); ++it) {
		
    if (*it >= 1) {

      int indiceAdj = it -(linha->begin());

      if (corVertice[indiceAdj] == "branco")
        dfs_visit(indiceAdj, visitados);
    }
  }
  
  corVertice[vertice] = "preto";
}

graf_bib::Caminho graf_bib::grafo::dfs (Matriz mAdj,
    unsigned int verticeInicial) {

  Caminho *visitados = NULL;

  for (unsigned int vertice = 0;
      vertice < numVertices; 
      ++vertice) {

    corVertice[vertice] = "branco";
  }
  
  visitados = new Caminho();
  dfs_visit(mAdj, verticeInicial, *visitados);

  return *visitados;
}

void graf_bib::grafo::dfs_visit(Matriz mAdj, const unsigned int &vertice,
                      Caminho &visitados) {

  corVertice[vertice] = "cinza";
	
  Matriz *ret = new Matriz(mAdj);
  Matriz::iterator linha = ret->begin() + vertice;

  visitados.push_back(vertice);

  for(Linha::iterator it = linha->begin(); it != linha->end(); ++it) {
		
    if (*it >= 1) {

      int indiceAdj = it -(linha->begin());

      if (corVertice[indiceAdj] == "branco")
        dfs_visit(mAdj, indiceAdj, visitados);
    }
  }
  
  corVertice[vertice] = "preto";
}

unsigned int graf_bib::grafo::num_componentes (void){
  
  unsigned int componentes = 0;
  Caminho fifo_naoVisitados; 
  
  for (unsigned int vertice = 0;
        vertice < numVertices; 
        ++vertice) {

      fifo_naoVisitados.push_back(vertice);
      corVertice[vertice] = "branco";
  }

  while(!fifo_naoVisitados.empty()) {
    
    int verticeAtual = fifo_naoVisitados.front();
    fifo_naoVisitados.pop_front();
    
    if(corVertice[verticeAtual] == "branco") {

      ++componentes;

      this->dfs(verticeAtual);
    }
  }

  return componentes;  
}

graf_bib::Caminho graf_bib::grafo::dijkstra(unsigned int verInicial, 
    unsigned int verFinal) {
  
  Caminho queue;

  set<unsigned int> verificados;
  map<unsigned int, unsigned int > pi;
  
  for (unsigned int vertice = 0;
      vertice < numVertices; 
      ++vertice) {

    queue.push_back(vertice);
    peso[vertice] = numeric_limits<unsigned int>::max(); 
  }

  peso[verInicial] = 0;

  
  while(!queue.empty()) {
    
    unsigned int verticeAtual = extract_min(queue);

    if(verticeAtual == verFinal)
      break;

    verificados.insert(verticeAtual);
    
    Matriz *gph = new Matriz(matrizRep);
    Matriz::iterator linha = gph->begin() + verticeAtual;

    for(Linha::iterator it = linha->begin(); it != linha->end(); ++it) {
		
      if (*it >= 1) {
        
        int indiceAdj = it -(linha->begin());
        
        map<unsigned int, unsigned int>::iterator alreadyRead 
          = peso.find(indiceAdj);

        if(alreadyRead != peso.end()) {

          if(peso[indiceAdj] > *it) {
            peso[indiceAdj] = *it;
            pi[indiceAdj] = verticeAtual;
          }
        }
      }
    }
  } 

  Caminho melhorcaminho;
  
  unsigned int verAtual = verFinal;
  melhorcaminho.push_back(verAtual);

  while(1) {
    
    verAtual = pi[verAtual];
    melhorcaminho.push_back(verAtual);
    
    if(verAtual == verInicial)
      break;
  }
  
  melhorcaminho.reverse();

  return melhorcaminho;
}

unsigned int graf_bib::grafo::extract_min(Caminho &queue) {
 
  unsigned int verticeMin;
  unsigned int min = numeric_limits<unsigned int>::max();

  for(map<unsigned int, unsigned int>::iterator it = peso.begin(); 
      it != peso.end(); 
      ++it) {
		
    if (it->second < min) {
      
      min         = it->second;
      verticeMin  = it->first;
    }
  }

  peso.erase(verticeMin);
  queue.remove(verticeMin);
  
  return verticeMin;
}

bool graf_bib::grafo::hamiltoniano (void) {


  Matriz *ret = new Matriz(matrizRep);
  vector< list < int > > fila;
  list < int > verticesChecados;
  verticesChecados.push_back(0);
  Matriz::iterator linha = ret->begin();
  int indiceVertice = 0;
  list <int> lista;
  bool verticeRetirado = false;

  // Inicializa fila
  for(Matriz::iterator linha = ret->begin();
        linha != ret->end();
        ++linha) {
    lista.clear();
    for(Linha::iterator it = linha->begin();
      it != linha->end();
      ++it) {//itera nos vertices adjacentes

      if (*it ==1 && (linha - (ret->begin()) != it - (linha->begin()))) {

        //Adiciona os vertices adjacentes a uma fila de prioridades
        lista.push_back(it - (linha->begin()));
      }
    }
    fila.push_back(lista);
  }

  while(1) {

    if (fila[indiceVertice].empty()) {
      return false;
    }

    if (find(verticesChecados.begin(),
          verticesChecados.end(),
          fila[indiceVertice].front())==verticesChecados.end()) {

      //vertice ainda nao esta no ciclo
      //Adiciona um vertice ao ciclo de hamilton
      verticesChecados.push_back(fila[indiceVertice].front());
      //Proximo vertice a verificar seus vertices adjacentes
      linha = ret->begin() + (fila[indiceVertice].front());
      // Retira o vertice da fila de prioridades
      fila[indiceVertice].pop_front();
      indiceVertice = linha - (ret->begin());
    }
    else {

      while (find(verticesChecados.begin(),
          verticesChecados.end(),
          fila[indiceVertice].front()) != verticesChecados.end()){

      //checa se vertice ja esta no ciclo
        if (verticesChecados.size()== numVertices &&
            fila[indiceVertice].front() == verticesChecados.front()) {

          //encontrou ciclo
          string ciclo;
          for (int i=0; i<numVertices; i++) {
            ciclo = ciclo + to_string(verticesChecados.front()) + "->";
            verticesChecados.pop_front();
          }

          cout << ciclo << endl << endl;

          return true;
        } else {

            // Retira o vertice da fila de prioridades
            fila[indiceVertice].pop_front();
            if (fila[indiceVertice].empty()) {

                //volta para vertice anterior
                verticesChecados.pop_back();
                // Adiciona vertices adjacentes novamente
                for(Linha::iterator it = linha->begin();
                    it != linha->end();
                    ++it) {//itera nos vertices adjacentes

                    if (*it ==1 && (linha - (ret->begin()) != it - (linha->begin()))) {
                        fila[indiceVertice].push_back(it - (linha->begin()));
                    }
                }
                linha = ret->begin() + verticesChecados.back();
                verticeRetirado = true;
                break;
            } else {

                //Proximo vertice a verificar seus vertices adjacentes
                linha = ret->begin() + (fila[indiceVertice].front());

            }

        }

      }
      if (!verticeRetirado) {
        verticesChecados.push_back(fila[indiceVertice].front());
        fila[indiceVertice].pop_front();
        linha = ret->begin() + verticesChecados.back();
      }
      verticeRetirado = false;
      indiceVertice = linha - (ret->begin());
    }
  }
  return false;
}

graf_bib::Matriz graf_bib::grafo::kruskal(void) {
  
  Matriz arvore;

  arvore.resize(numVertices);

  list< pair<unsigned int, pair<unsigned int, unsigned int> > > queue;
  pair<unsigned int, unsigned int> aresta;

  for(Matriz::iterator linha = matrizRep.begin();
      linha != matrizRep.end();
      ++linha) { 
    for(Linha::iterator it = linha->begin(); it != linha->end(); ++it) {
      
      arvore[it - linha->begin()].resize(numVertices, 0);

      if(*it >= 1 && (linha-matrizRep.begin()) < (it-linha->begin())) { 
        aresta = make_pair(linha - matrizRep.begin(), it - linha->begin());
        queue.push_back(make_pair(*it, aresta));
      }
    }
  }

  queue.sort();

  set<unsigned int> vertices;
  
  while(!queue.empty()) {
    
    unsigned int custo = queue.front().first;
    aresta = queue.front().second;

    queue.pop_front();

    Caminho floresta1;
    Caminho floresta2;

    floresta1 = dfs(arvore, aresta.first);
    floresta2 = dfs(arvore, aresta.second);

    floresta1.sort();
    floresta2.sort();

    bool jaConectadas = false;
    if(floresta1 == floresta2)
      jaConectadas = true;
   
    if(!jaConectadas) { 
      if (arvore[aresta.first][aresta.second] == 0) {
        arvore[aresta.first][aresta.second] = custo;
        arvore[aresta.second][aresta.first] = custo;

        vertices.insert(aresta.first);
        vertices.insert(aresta.second);
      }
    }
  }

  return arvore;
}  
