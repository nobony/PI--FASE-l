#include <stdio.h>
#include <stdlib.h>
#include "produto.h"


int main(){
    //inicialização do vetor
    VetorProdutos v;
    
    inicVetor(&v);

    //chamada da leitura do CSV
    lerCSV("dataset4", &v);

    //execução dos testes (Victor)
    //impressão dos resultados (Victor)

    //liberacao de memoria pos uso (evita memory leak)
    liberarMemoria(&v);

    return 0;

}
