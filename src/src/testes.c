#include <stdio.h>
#include "testes.h"
#include "busca.h"
#include "tempo.h"

void testes(VetorProdutos *v) {
    char *labels[] = {"Inicio", "Meio", "Final", "Inexistente"};
    int n_buscas = 1000;

    printf("\n--- RELATORIO TECNICO DE PERFORMANCE ---\n");
    printf("Registros carregados: %d\n", v->tamanho);
    printf("----------------------------------------------------------\n");
    printf("%-12s | %-15s | %-15s\n", "Posicao", "Tempo Total(ms)", "Tempo Medio(ms)");
    printf("----------------------------------------------------------\n");

    
    
    //Id para testes
    int idsIniciais[3] = {
        0,            // Início
        (v->tamanho / 2) - 500,  // Meio (pegando 500 antes do centro)
        v->tamanho - 1001       // Final (últimos 1000)
    };

    
    for (int i = 0; i < 3; i++) {
        double t_inicio = obterTempo();

        // Realiza 1000 buscas
         for (int b = 0; b < 1000; b++) {
            int idAlvo = idsIniciais[i] + b;

            if (idAlvo >= 0 && idAlvo < v->tamanho) {
                long int id_para_busca = v->dados[idAlvo].id;
                buscaSequencial(v, id_para_busca);
            }
        }
        
        double t_fim = obterTempo();
        double tempoTotal = t_fim - t_inicio;
        double tempoMedio = tempoTotal / n_buscas;

        printf("%-12s | %-15.4f | %-15.6f\n", labels[i], tempoTotal, tempoMedio);
    }

    printf("---------------------------------------------------------------------\n");
    
    long int idInexistente = -999; 
    double t_inc_ini = obterTempo();
    
    for (int b = 0; b < n_buscas; b++) {
        buscaSequencial(v, idInexistente);
    }
    
    double t_inc_fim = obterTempo();
    double tempoTotalInc = t_inc_fim - t_inc_ini;
    double tempoMedioInc = tempoTotalInc / n_buscas;

    printf("%-12s | %-15.4f | %-15.6f\n", "Inexistente", tempoTotalInc, tempoMedioInc);
    printf("---------------------------------------------------------------------\n");
}


