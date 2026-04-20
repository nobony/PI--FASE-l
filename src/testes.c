#include <stdio.h>
#include "testes.h"
#include "busca.h"
#include "tempo.h"

void testesdoprofessor(VetorProdutos *v) {
    //Id para testes
    long int idsTeste[4] = {
        v->dados[0].id,               // Início
        v->dados[v->tamanho / 2].id,   // Meio
        v->dados[v->tamanho - 1].id,   // Final
        -999                         // Inexistente (ID que não existe)
    };

    char *labels[] = {"Inicio", "Meio", "Final", "Inexistente"};

    printf("\n--- RELATORIO TECNICO INICIAL ---\n");
    printf("Registros carregados: %d\n", v->tamanho);
    printf("----------------------------------------------------------\n");
    printf("%-12s | %-15s | %-15s\n", "Posicao", "Tempo Total(ms)", "Tempo Medio(ms)");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        double somaTemposRepeticao = 0;

        // Repetir ao menos 3 vezes
        for (int r = 0; r < 3; r++) {
            double t_inicio = obterTempo();

            // 1.000 buscas consecutivas
            for (int b = 0; b < 1000; b++) {
                buscaSequencial(v, idsTeste[i]);
            }

            double t_fim = obterTempo();
            somaTemposRepeticao += (t_fim - t_inicio);
        }

        double tempoMedioTotal = somaTemposRepeticao / 3.0;
        double tempoPorBusca = tempoMedioTotal / 1000.0;

        printf("%-12s | %-15.4f | %-15.6f\n", labels[i], tempoMedioTotal, tempoPorBusca);
    }
}