#include <stdio.h>

//struct do produto (id,nome,categoria,valor)
struct Produto {
    long int id;
    char nome[50];
    char categoria [50];
    float valor;
};

//struct VetorProdutos
struct VetorProdutos{
    struct Produto* dados;
    int tamanho;
    int capacidade;
};
