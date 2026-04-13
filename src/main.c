#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "leitura.h"

int main(){
    //inicialização do vetor
    VetorProdutos v;

    printf("Início do programa\n");
    inicVetor(&v);

    //chamada da leitura do CSV
    lerCSV("src/dataset4.csv", &v);


    //inicio do clock 
    
    //impressão dos resultados (Victor)
    buscaSequencial(&v);

    //liberacao de memoria pos uso (evita memory leak)
    liberarMemoria(&v);

    printf("\nPrograma encerrado.\n");

    return 0;

}
