#ifndef __UTIL_H
#define __UTIL_H

#include <stdio.h>
#include <stdlib.h>

#include "structVetor.h"

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

void imprimeVetor(int *vetor) {
    if (vetor == NULL) {
        printf("Vetor vazio.\n");
        return;
    }

    for (int i = 0; vetor[i] != -1 && vetor[i] != NULL; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
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

void appendInt(Vetor **vetor, int *valores) 
{
    int tamanhoVetor = (*vetor)->length;
    int qtdValores = len(valores);

    printf("tamanhoVetor: %d\n", tamanhoVetor);
    printf("qtdValores: %d\n", qtdValores);

    if (tamanhoVetor == 0 && qtdValores > 1) 
    {
        (*vetor)->itens = (int *) malloc(sizeof(int) * qtdValores);
        (*vetor)->length++;
        for (int i = 0; i < qtdValores; i++) 
        {
            (*vetor)[i] = valores[i];
        }
    } 
    else if (tamanhoVetor > 0 && qtdValores > 1) 
    {
        (*vetor)->itens = (int *) realloc(*vetor, sizeof(int) * (tamanhoVetor + qtdValores));
        (*vetor)->length += qtdValores;
        for (int i = 0; i < qtdValores; i++) 
        {
            if (!contido(valores[i], *vector))
            {
                (*vetor)[tamanhoVetor + i] = valores[i];   
            }
        }
    }
    // else if (tamanhoVetor == 0 && qtdValores == 1) 
    // {
    //     *vetor = (int *) malloc(sizeof(int));
    //     (*vetor)[0] = valores[0];
    // }

    // for (int i = 0; i < qtdValores; i++) 
    // {
    //     tamanhoVetor = len(*vetor);
    //     for (int j = 0; j < tamanhoVetor; j++) 
    //     {
    //         if (valores[j] == (*vetor)[i])
    //         {
    //             continue ;
    //         }

    //         // Caso o valor não esteja no vetor, adiciona
    //         *vetor = (int *) realloc(*vetor, tamanhoVetor * sizeof(int) + 1);
    //         (*vetor)[tamanhoVetor - 1] = valores[i];
    //     }
    // }

    return ;
}

int len(int *vetor) {
    int length = 0;

    if (vetor == NULL) {
        return 0;
    }
    else if (vetor[0] <= -1) {
        return 0;
    }

    for (int i = 0; vetor[i] != -1 && vetor[i] != NULL; i++) {
        printf("vetor[%d]: %d\n", i, vetor[i]);
        length++;
    }
    return length;
}

bool contido(int valor, Vetor *vetor) {
    if (vetor == NULL) {
        return false;
    }

    for (int i = 0; i < vetor->length; i++) {
        if (vetor->itens[i] == valor) {
            return true;
        }
    }

    return false;
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
            pilhaPush(pilha, filhos[i]);
        }
    }
}


#endif