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


#include <iostream>

using namespace std;

graf_bib::grafo::grafo( string arquivo )
    : gMatriz(arquivo) {

  numVertices = matrizRep.size();
  numArestas  = 0;
  simples     = true;
  
  corVertice.resize(numVertices, "branco"); 

  for(Matriz::const_iterator linha = matrizRep.begin();
      linha != matrizRep.end();
      ++linha) {

    if(linha->size()!= matrizRep.size())
      throw onError("Matriz deve ser quadrada");


    for(Linha::const_iterator it = linha->begin();
        it != linha->end();
        ++it) {

      if(*it >= 1) {
        
        numArestas += *it;
        
        if(*it > 1 && !simples)
          simples = false;
      }
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

  if(!simples)
    ret = false;
  else if(numArestas != (numVertices*(numVertices -1))/2 )
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

  if(!completo() && simples) {

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

list<unsigned int> graf_bib::grafo::dfs (unsigned int verticeInicial) {

  Caminho *visitados = NULL;

  if(simples) {  
    
    for (unsigned int vertice = 0;
        vertice < numVertices; 
        vertice++) {

      corVertice[vertice] = "branco";
    }
    
    visitados = new Caminho();
    dfs_visit(verticeInicial, *visitados);
  }

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

void graf_bib::grafo::num_componentes (void){
int componentes=0;
  int vertice=0;
  set<int> verticesDoComponente;//TODO: inicializar
  // Lista para vertices que nao verificou vertices adjacentes
  list<int> verticesNaoVerificados;//TODO: inicializar
  for (vertice=0; vertice < numVertices; vertice++) {
      verticesNaoVerificados.push_back(vertice);
  }
  //Matriz de adjacencias
  Matriz *ret = new Matriz(matrizRep);
  Matriz::iterator linha = ++(ret->begin());

  while(!verticesNaoVerificados.empty()) {
    for(Linha::iterator it = linha->begin(); 
      it != linha->end(); 
        ++it) {//itera nos vertices adjacentes
        
      if (*it ==1) {
            verticesDoComponente.insert(it - (linha->begin()));
        }
    }
    verticesNaoVerificados.remove(linha-(ret->begin()));
    if (!verticesDoComponente.empty()) {
        linha = ret->begin() + *(++verticesDoComponente.begin());
    } 
    else {
        componentes++;
    }
  }
}

bool graf_bib::grafo::hamiltoniano (void) {
//TODO: checar se tem apenas 1 componente antes

  Matriz *ret = new Matriz(matrizRep);
  list < int > verticesChecados;//TODO: inicializar
  vector< list < int > > fila;//TODO: inicializar
  Matriz::iterator linha = ++(ret->begin());
  int indiceVertice = 0;

  while(!fila[0].empty()) {
      
    for(Linha::iterator it = linha->begin();
      it != linha->end(); 
      ++it) {//itera nos vertices adjacentes
        
      if (*it ==1) {
        //Adiciona os vertices adjacentes a uma fila de prioridades
            
        fila[indiceVertice].push_front(it - (linha->begin()));
      }
    }

    if (!(fila[indiceVertice].empty()) && 
        find(verticesChecados.begin(),
          verticesChecados.end(),
          fila[indiceVertice].front())==verticesChecados.end()) {
      
      //vertice ainda nao esta no ciclo
      //Adiciona um vertice ao ciclo de hamilton
      verticesChecados.push_back(fila[indiceVertice].front());
      
      //Proximo vertice a verificar seus vertices adjacentes
      linha = ret->begin() + (fila[indiceVertice].front());
      indiceVertice = linha - (ret->begin());
      
      // Retira o vertice da fila de prioridades
      fila[indiceVertice].pop_front();
    } 
    else {
    
      while (find(verticesChecados.begin(),
          verticesChecados.end(),
          fila[indiceVertice].front()) != verticesChecados.end()){
      
      //checa se vertice ja esta no ciclo
        if (verticesChecados.size()== numVertices && 
            fila[indiceVertice].front() == verticesChecados.front()) {
          
          //encontrou ciclo
          return true;
        } 
        else {//ciclo ainda nao encontrado
        
          if (fila[indiceVertice].empty()) {
            //volta para outra combinacao sem adicionar vertice ao ciclo
            verticesChecados.pop_back();
          
            linha = ret->begin() + indiceVertice -1;
            //volta para vertice anterior
          
            indiceVertice = linha - (ret->begin());
          } 
          else {
            // Retira o vertice da fila de prioridades
            fila[indiceVertice].pop_front();
            
            //Proximo vertice a verificar seus vertices adjacentes
            linha = ret->begin() + (fila[indiceVertice].front());
            indiceVertice = linha - (ret->begin());
          }
        }
      }
    }
  }

  return false;
}
