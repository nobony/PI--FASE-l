#include <stdio.h>
#include <time.h>

// Esta é a sua ferramenta de medição
double obterTempo() {
    return ((double)clock() / CLOCKS_PER_SEC) * 1000.0;
}

// Exemplo de como você usaria para medir 1000 buscas no FIM
double t_inicio = obterTempo(); // Foto 1

for (int i = v.tamanho - 1000; i < v.tamanho; i++) {
    buscaSequencial(&v, v.dados[i].id);
}

double t_fim = obterTempo(); // Foto 2

printf("Tempo total para as 1000 buscas no fim: %.4f ms\n", t_fim - t_inicio);