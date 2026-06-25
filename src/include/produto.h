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
void addProduto(VetorProdutos *v, Produto p);

//sintaxe funcao liberarMemoria
void liberarMemoria(VetorProdutos *v);

// Estrutura do Nó da Lista Encadeada (para tratar colisões)
typedef struct NoHash {
    Produto p;
    struct NoHash* prox;
} NoHash;

// Estrutura principal da Tabela Hash
typedef struct {
    NoHash** vetor; // Array de ponteiros para as listas
    int tamanho;    // Tamanho (m) - quantidade de registros
    int colisoes;   // Contador para o relatório técnico
} TabelaHash;
#endif 