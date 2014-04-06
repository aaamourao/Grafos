#!/bin/bash
#
# Automatiza commit e push para o github
#

if [ -n "$3" ] 
then 
  echo "Esqueceu do texto do commit, cabecao";
  exit 0;
else 
  # Limpa dados indesejados
  make clean;

  # Adiciona todos os arquivos modificados
  git add -u .;

  # Commita
  git commit -m $1;

  # Carrega no servidor
  git push -u origin master;
fi
