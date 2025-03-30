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

int *buscaCaminho(int grafo[][TAMANHO_MAX_MATRIZ], int qtdVertices, int vEmergente, int vIncidente) 
{
    int *caminhoIds = NULL, *idsPassaramPelaPilha, *filhosAux;
    int *pilha, aux;
    bool continuaFluxo = true;

    if (vEmergente == vIncidente) 
    {
        printf("Vértices de origem e destino são iguais.\n");
        return NULL;
    }

    pilha = pilhaInicializar(NULL);
    pilhaPush(&pilha, vEmergente);

    while(continuaFluxo) 
    {
        aux = pilhaPop(pilha);
        if (aux == -1) 
        {
            printf("Pilha vazia.\n");
            continuaFluxo = false;
            break;
        }

        if (passouPelaPilha(pilha, aux)) 
        {
            continue;
        }

        if (aux == vIncidente) 
        {
            printf("Caminho encontrado!\n");
            appendInt(&caminhoIds, aux);
            continuaFluxo = false;
            break;
        }
        else 
        {
            appendInt(&caminhoIds, aux);
        }

        filhosAux = buscaFilhos(grafo, aux);
        if (len(filhosAux) == 0) 
        {
            // Caso o vértice não tenha filhos, chegamos ao fim desse caminho
            limpaVetor(&filhosAux);
            limpaVetor(&caminhoIds);
            continue;
        }
        else
        {
            // Adiciona os filhos na pilha
            adicionaFilhosNaPilha(&pilha, filhosAux);
            adicionaNoPassaramPelaPilha(&idsPassaramPelaPilha, filhosAux);
        }

    }

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