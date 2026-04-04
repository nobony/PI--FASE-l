#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"

// lê o arquivo e preenche o vetor(funcao lerCSV)
void lerCSV(const char *dataset4, VetorProdutos *v){
    //abre o arquivo
     FILE *file; //ponteiro do arquivo

    file = fopen("../dataset4.csv", "r");
    
    if (!file) {
        printf("Erro em abrir o arquivo\n");
        exit (1);
    }

    char linha[200]; //define o vetor linha, a string a ser lida

    //ignorar cabeçario
    fgets(linha, sizeof(linha), file);

     // ler linha por linha com while(buffer, tamanho, arquivo)){}
    while(fgets(linha, sizeof(linha), file)){
        Produto p; //cria a estrutura vazia para ser preenchida

         //parse dos dados na linha com strtok
        char *token = strtok(linha, ",");
        if(!token) continue; //valida
        p.id = atoi(token); //aloca em id e transforma string em int

        token = strtok(linha, ",");
        if(!token) continue; //valida
        p.nome; //aloca em nome

        token = strtok(linha, ",");
        if(!token) continue; //valida
        p.valor = atof(token); //aloca em valor e transforma string em float

        addProduto(v, p);
        }
    }
