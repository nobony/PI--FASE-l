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
    struct Produto* dados;
    int tamanho;
    int capacidade;
} VetorProdutos;

//sintaxe funcao inicializarVetor
void inicVetor(VetorProdutos *c); 

//sintaxe funcao addProduto
void addProdutos(VetorProdutos *c, Produto p);

//sintaxe funcao liberarMemoria
void liberarMemoria(VetorProdutos *v);

#endif 