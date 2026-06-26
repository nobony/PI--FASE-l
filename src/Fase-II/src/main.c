#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "leitura.h"
#include "testes.h"
#include "hash.h"

int main() {
    VetorProdutos v;
    inicVetor(&v);

    printf("Iniciando programa...\n");
    printf("Lendo o arquivo CSV para memoria dinamica...\n");
    lerCSV("dataset4.csv", &v);

    if (v.tamanho > 0) {
        printf("Carregando dados na Tabela Hash...\n");
        TabelaHash th;
        
        // O tamanho da hash é igual ao volume de dados (Requisito FASE II)
        inicHash(&th, v.tamanho); 

        // Transfere todos os produtos do vetor para a Hash
        for (int i = 0; i < v.tamanho; i++) {
            inserirHash(&th, v.dados[i]);
        }

        // Roda o laboratório de testes
        testes(&v, &th);

        printf("Liberando memoria da Tabela Hash...\n");
        liberarHash(&th);
    }

    printf("Liberando memoria do Vetor Inicial...\n");
    liberarMemoria(&v);
    
    return 0;
}
