#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "leitura.h"
#include "testes.h"   // <--- ESTE É FUNDAMENTAL!
#include "busca.h"
#include "tempo.h"

int main() {
    VetorProdutos v;
    inicVetor(&v);

    printf("Iniciando programa...\n");

    printf("Lendo o arquivo CSV...\n");
    lerCSV("dataset4.csv", &v); 

    if (v.tamanho > 0) {
        testesdoprofessor(&v); 
    }

    printf("Liberando memoria...\n");
    liberarMemoria(&v);
    return 0;
}
