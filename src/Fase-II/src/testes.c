#include <stdio.h>
#include "testes.h"
#include "busca.h"
#include "tempo.h"
#include "hash.h"

// Note que agora passamos as duas estruturas para o teste
void testes(VetorProdutos *v, TabelaHash *th) {
    char *labels[] = {"Inicio", "Meio", "Final", "Inexistente"};
    int n_buscas = 1000;

    printf("\n--- RELATORIO TECNICO FASE II: TABELA HASH ---\n");
    printf("Registros carregados: %d\n", th->tamanho);
    printf("Total de Colisoes: %d\n", th->colisoes);
    printf("--------------------------------------------------\n");
    printf("%-12s | %-15s | %-15s\n", "Posicao", "Tempo Total(ms)", "Tempo Medio(ms)");
    printf("--------------------------------------------------\n");

    int idsIniciais[3] = {
        0, 
        (v->tamanho / 2) - 500, 
        v->tamanho - 1001 
    };

    for (int i = 0; i < 3; i++) {
        double t_inicio = obterTempo();

        for (int b = 0; b < n_buscas; b++) {
            int idAlvo = idsIniciais[i] + b;
            if (idAlvo >= 0 && idAlvo < v->tamanho) {
                long int id_para_busca = v->dados[idAlvo].id;
                // AQUI ESTÁ A MÁGICA: Busca $O(1)$ na tabela Hash
                buscarHash(th, id_para_busca); 
            }
        }

        double t_fim = obterTempo();
        double tempoTotal = t_fim - t_inicio;
        double tempoMedio = tempoTotal / n_buscas;

        printf("%-12s | %-15.4f | %-15.6f\n", labels[i], tempoTotal, tempoMedio);
    }

    printf("--------------------------------------------------\n");

    // Teste de Inexistentes
    long int idInexistente = -999;
    double t_inc_ini = obterTempo();

    for (int b = 0; b < n_buscas; b++) {
        buscarHash(th, idInexistente);
    }

    double t_inc_fim = obterTempo();
    double tempoTotalInc = t_inc_fim - t_inc_ini;
    double tempoMedioInc = tempoTotalInc / n_buscas;

    printf("%-12s | %-15.4f | %-15.6f\n", "Inexistente", tempoTotalInc, tempoMedioInc);
    printf("--------------------------------------------------\n");
}