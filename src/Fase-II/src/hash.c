#include <stdlib.h>
#include "hash.h"

void inicHash(TabelaHash* th, int tamanho) {
    th->tamanho = tamanho;
    th->colisoes = 0;
    // calloc já aloca a memória e preenche tudo com NULL (vazio)
    th->vetor = (NoHash**)calloc(tamanho, sizeof(NoHash*));
}

// F4: Meio do Quadrado Simplificado (Mid-Square) passado pelo professor
int funcaoHash(long int id, int m) {
    // Cast para unsigned long long previne overflow na multiplicação de IDs grandes
    unsigned long long quadrado = (unsigned long long)id * id;
    return (int)((quadrado / 100) % m);
}

void inserirHash(TabelaHash* th, Produto p) {
    int indice = funcaoHash(p.id, th->tamanho);

    NoHash* novo = (NoHash*)malloc(sizeof(NoHash));
    novo->p = p;
    novo->prox = NULL;

    // Se o espaço estiver vazio, insere direto
    if (th->vetor[indice] == NULL) {
        th->vetor[indice] = novo;
    } 
    // Se já tiver alguém, ocorreu uma colisão. Fazemos o encadeamento.
    else {
        th->colisoes++; // Contabiliza a colisão para o relatório
        NoHash* atual = th->vetor[indice];
        // Percorre a lista até o final para adicionar o novo produto
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Retorna 1 se encontrou ou 0 se não encontrou
int buscarHash(TabelaHash* th, long int idAlvo) {
    int indice = funcaoHash(idAlvo, th->tamanho);
    NoHash* atual = th->vetor[indice];

    // Percorre a lista encadeada daquele índice procurando o ID
    while (atual != NULL) {
        if (atual->p.id == idAlvo) {
            return 1; // Sucesso
        }
        atual = atual->prox;
    }
    return 0; // Não encontrou
}

void liberarHash(TabelaHash* th) {
    for (int i = 0; i < th->tamanho; i++) {
        NoHash* atual = th->vetor[i];
        while (atual != NULL) {
            NoHash* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(th->vetor); // Libera o array principal
}