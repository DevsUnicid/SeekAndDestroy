#ifndef __MANIPULAMATRIZ_H
#define __MANIPULAMATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pilha.h"

#define TAMANHO_MAX_MATRIZ 25

// Definição de funções
int *buscaFilhos(int grafo[][TAMANHO_MAX_MATRIZ], int vertice);

// Funções
bool insereConexao(int matriz[][TAMANHO_MAX_MATRIZ], int idPai, int idConexao) {
    matriz[idPai - 1][idConexao - 1] = 1;
    matriz[idConexao - 1][idPai - 1] = 1;

    return true;
}

bool incluirVertice(int matriz[][TAMANHO_MAX_MATRIZ]) {
    int novoVertice, novaConexao;

    printf("Digite o valor/id do vértice: ");
    scanf(" %d", &novoVertice);

    if (novoVertice == 0) {
        return false;
    }

    while(true) {
        printf("Digite o id/número do vértice da conexão ou digite 0 para finalizar a inserção: ");
        scanf(" %d", &novaConexao);

        if (novaConexao == 0) {
            break;
        }
        insereConexao(matriz, novoVertice, novaConexao);
    }

    return true;
}

int *buscaCaminho(int grafo[][TAMANHO_MAX_MATRIZ], int qtdVertices, int vEmergente, int vIncidente) {
    int *caminhoIds = NULL;
    int *pilha;
    bool conituaFluxo = true;

    if (vEmergente == vIncidente) {
        printf("Vértices de origem e destino são iguais.\n");
        return NULL;
    }

    printf("1 ------------------\n");
    pilha = pilhaInicializar(NULL);

    printf("2 ------------------\n");
    pilhaPush(pilha, vEmergente);

    printf("3 ------------------\n");
    caminhoIds = buscaFilhos(grafo, vEmergente);

    printf("Impressão da pilha:\n");
    imprimePilha(pilha);

    printf("Impressão dos filhos:\n");
    for (int i = 0; caminhoIds[i] != -1; i++) {
        printf("V%d ", caminhoIds[i]);
    }

    // while(conituaFluxo) {

    // }

}

int *buscaFilhos(int grafo[][TAMANHO_MAX_MATRIZ], int vertice) 
{
    int *filhos, qtdFilhos = 0;
    int linha = vertice - 1;

    for (int j = 0; j < TAMANHO_MAX_MATRIZ; j++) 
    {
        if (grafo[linha][j] == 1) 
        {
            if (qtdFilhos == 0)
            {
                filhos = (int *) malloc(sizeof(int));
                filhos[qtdFilhos] = j + 1;
            }
            else 
            {
                filhos = (int *) realloc(filhos, qtdFilhos * sizeof(int) + 1);
                filhos[qtdFilhos] = j + 1;
            }

            qtdFilhos++;
        }
    }

    filhos = (int *) realloc(filhos, qtdFilhos * sizeof(int) + 1);
    filhos[qtdFilhos] = -1;

    return filhos;
}

#endif