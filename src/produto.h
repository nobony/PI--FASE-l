#ifndef PRODUTO_H
#define PRODUTO_H

//struct do produto (id,nome,categoria,valor)
typedef struct {
    long int id;
    char nome[50];
    char categoria [50];
    float valor;
} Produto;

//struct VetorProdutos
typedef struct{
    Produto* dados;
    int tamanho;
    int capacidade;
} VetorProdutos;

//sintaxe funcao inicializarVetor
void inicVetor(VetorProdutos *v); 

//sintaxe funcao addProduto
void addProdutos(VetorProdutos *v, Produto p);

//sintaxe funcao liberarMemoria
void liberarMemoria(VetorProdutos *v);

#endif 