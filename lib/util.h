#ifndef __UTIL_H
#define __UTIL_H

#include <stdio.h>
#include <stdlib.h>

#include "structVertice.h"

#define TAMANHO_MAX_MATRIZ 25

void imprimeMatrizDeAdjascencias(int matriz[TAMANHO_MAX_MATRIZ][TAMANHO_MAX_MATRIZ], int qtdVertices) {
    printf("\n     ");
    for (int j = 0; j < qtdVertices; j++) {
        printf("V%d ", j+1);
    }
    printf("\n");

    for (int i = 0; i < qtdVertices; i++) {
        printf("V%d  | ", i+1);
        for (int j = 0; j < qtdVertices; j++) {
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
}

void normalizaMatriz(int matriz[TAMANHO_MAX_MATRIZ][TAMANHO_MAX_MATRIZ], int sizeMatriz) {
    for (int i = 0; i < sizeMatriz; i++) {
        for (int j = 0; j < sizeMatriz; j++) {
            if (matriz[i][j] != 1) {
                matriz[i][j] = 0;
            }
        }
    }
}

void appendInt(int **vetor, int valor) {
    *vetor = (int *) realloc(*vetor, sizeof(*vetor) + 1);
    (*vetor)[sizeof(*vetor)] = valor;
}

int len(int *vetor) {
    int length = 0;

    if (vetor == NULL) {
        printf("vetor == NULL ou vetor == 0\n");
        return 0;
    }
    else if (vetor[0] == -1) {
        return 0;
    }

    for (int i = 0; vetor[i] != -1 && vetor[i] != NULL; i++) {
        length++;
    }
    return length;
}

bool passouPelaPilha(int *pilha, int idVertice) {
    if (pilha == NULL) {
        return false;
    }

    for (int i = 0; i < len(pilha); i++) {
        if (pilha[i] == idVertice) {
            return true;
        }
    }
    return false;
}

void limpaVetor(int **vetor) 
{
    int vEmergente;

    if (*vetor != NULL) {
        free(*vetor);
    }

    vEmergente = *vetor[0];
    appendInt(vetor, vEmergente);
}

void adicionaFilhosNaPilha(int **pilha, int *filhos) 
{
    if (filhos == NULL) {
        return;
    }

    for (int i = 0; filhos[i] != -1; i++) {
        if (passouPelaPilha(*pilha, filhos[i])) {
            continue;
        }
        else {
            appendInt(pilha, filhos[i]);
        }
    }
}

void adicionaNoPassaramPelaPilha(int **idsPassaramPelaPilha, int *filhos) 
{
    if (filhos == NULL) {
        return;
    }

    for (int i = 0; filhos[i] != -1; i++) 
    {
        appendInt(idsPassaramPelaPilha, filhos[i]);
    }
}

#endif