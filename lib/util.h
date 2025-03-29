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

void appendInt(int *vetor, int valor) {
    vetor = (int *) realloc(vetor, sizeof(vetor) + 1);
    vetor[sizeof(vetor)] = valor;
}

int len(int *vetor) {
    int length = 0;

    if (*vetor == NULL || *vetor == 0) {
        printf("vetor == NULL ou vetor == 0\n");
        return 0;
    }
    else if (vetor[0] == -1) {
        return 0;
    }

    for (int i = 0; vetor[i] != -1 || vetor[i] == NULL; i++) {
        printf("vetor[%d]: %d\n", i, vetor[i]);
        length++;
    }
    return length;
}

#endif