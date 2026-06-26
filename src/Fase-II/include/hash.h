#ifndef HASH_H
#define HASH_H

#include "produto.h"

void inicHash(TabelaHash* th, int tamanho);
int funcaoHash(long int id, int m);
void inserirHash(TabelaHash* th, Produto p);
int buscarHash(TabelaHash* th, long int idAlvo);
void liberarHash(TabelaHash* th);

#endif