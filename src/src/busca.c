#include <stdio.h>
#include "produto.h"

//funcao com loop de repeticao para implementar a busca sequencial
    // Retorna o índice do produto ou -1 se não encontrar
int buscaSequencial(VetorProdutos *v, long int idBusca) {
    for (int i = 0; i < v->tamanho; i++) {
        if (v->dados[i].id == idBusca) {
            return i; // Sucesso!
        }
    }
    return -1; // Não encontrado
}