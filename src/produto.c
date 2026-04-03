#include <stdlib.h>
#include "produto.h"

//manipulacao do vetor
/* -inicializacao (malloc porque comeca com 0)
    -insercao com realloc (para continuar de onde parou)
    -liberacao de memoria*/

//iniciar
void inicVetor (VetorProdutos *v){
    v->tamanho = 0;
    v->capacidade = 1000;
    v->dados = malloc(v->capacidade * sizeof(Produto));
}


//inserir
void addProduto(VetorProdutos *v, Produto p){
    //quando o vetor está cheio:
    if(v->tamanho == v->capacidade){
        v->capacidade *= 2; //dobra a capacidade
        v->dados = (Produto*) realloc(v->dados, v-> capacidade * sizeof(Produto));//realocou a memória
    }
    v->dados[v->tamanho++] = p;
}


//liberar para evitar problemas
void liberarMemoria(VetorProdutos *v){
    if(v->dados != NULL){
        free(v->dados);
        v->dados = NULL;
    }
}