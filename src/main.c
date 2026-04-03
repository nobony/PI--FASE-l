#include <stdio.h>
#include <stdlib.h>


int main(){
//inicialização do vetor
    struct VetorProdutos vetor;

    vetor.tamanho = 0;
    vetor.capacidade = 1000;
    vetor.dados = malloc(vetor.capacidade)


/*chamada da leitura do CSV
execução dos testes
impressão dos resultados*/

//fopen e fgets
    FILE *file; //ponteiro do arquivo

    file = fopen("../dataset4.csv", "r");
    
    if (file == NULL) {
        printf("Erro em abrir o arquivo\n");
        return 1;
    } else {
        printf("aberto\n");
    }

    while(fgets(char *VetorProdutos; int n; stdin)){
        for(int i = 0; i < n; i++){

        }
    }

}
