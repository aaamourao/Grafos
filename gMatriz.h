/**
 *
 * Trabalho 01 - Algoritmos com grafos 
 *
 * Adriano de Araujo Abreu Mourao (mourao.aaa at gmail.com)
 * Tamires Vargas Capanema Franco Santos (tamiresvargas at hotmail.com)
 *
 **/

#ifndef ARQPARAMATR_H
#define ARQPARAMATR_H

#include <fstream>
#include <vector>
#include <list>
#include <string>

namespace graf_bib {

  typedef std::vector< std::vector<int> > Matriz;
  typedef std::vector<int>                Linha;
  typedef std::list<unsigned int>         Caminho;
  
  class gMatriz {

    protected:
      const std::string nomeArq;
      Matriz matrizRep;

    public:
      gMatriz(std::string nome_arq);
      virtual Matriz retMatriz(void);

      virtual bool operator==(const gMatriz &compMatr) const;
      virtual bool operator!=(const gMatriz &compMatr) const;
  };

  std::string onError(std::string Falha);

  std::string toString(Matriz mGrafo);
  std::string toString(Caminho visitados);
}

#endif // ARQPARAMATR_H
