#ifndef __UTIL_H
#define __UTIL_H

#include <stdio.h>
#include <stdlib.h>

#include "structVetor.h"
#include "pilha.h"

#define TAMANHO_MAX_MATRIZ 25

// Assinatura de funções
void imprimeMatrizDeAdjascencias(int matriz[TAMANHO_MAX_MATRIZ][TAMANHO_MAX_MATRIZ], int qtdVertices);
void imprimeVetor(Vetor *vetor);
void normalizaMatriz(int matriz[TAMANHO_MAX_MATRIZ][TAMANHO_MAX_MATRIZ], int sizeMatriz);
void appendInt(Vetor **vetor, int valor);
int len(int *vetor);
bool contido(int valor, Vetor *vetor);
bool passouPelaPilha(int idVertice, Vetor *idsPassaramPelaPilha) ;
void limpaVetor(int **vetor);
void adicionaFilhosNaPilha(int **pilha, Vetor *filhos, Vetor *idsPassaramPelaPilha) ;

//Funções 
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

void imprimeVetor(Vetor *vetor) {
    if (vetor == NULL) {
        printf("Vetor vazio.\n");
        return;
    }

    printf("vetor->itens[0]: %d\n", vetor->itens[0]);
    printf("vetor->length: %d\n", vetor->length);
    for (int i = 0; i < vetor->length; i++) {
        printf("%d ", vetor->itens[i]);
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

Vetor *iniciaVetor(int valor) {
    Vetor *vetor = (Vetor *) malloc(sizeof(Vetor));

    if (valor == -1) 
    {
        vetor->length = 0;
        vetor->itens = NULL;
    }
    else 
    {
        vetor->length = 1;
        vetor->itens = (int *) malloc(sizeof(int));
        vetor->itens[0] = valor;
    }

    return vetor;
}

void appendInt(Vetor **vetor, int valor) 
{
    int tamanhoVetor;

    if (*vetor == NULL) 
    {
        *vetor = (Vetor *) malloc(sizeof(Vetor));
        (*vetor)->length = 0;
        (*vetor)->itens = NULL;
    }
    tamanhoVetor = (*vetor)->length;

    if (tamanhoVetor == 0) 
    {
        (*vetor)->itens = (int *) malloc(sizeof(int) * 2);
        (*vetor)->length = 1;
        (*vetor)->itens[0] = valor;
        (*vetor)->itens[1] = -1;
    }
    else 
    {
        (*vetor)->itens = (int *) realloc((*vetor)->itens, sizeof(int) * (tamanhoVetor + 1));
        (*vetor)->length++;
        (*vetor)->itens[tamanhoVetor] = valor;
        (*vetor)->itens[tamanhoVetor + 1] = -1;
    }

    return ;
}

void  appendListInt(Vetor **vetor, Vetor *valores) 
{
    if (*vetor == NULL) 
    {
        *vetor = (Vetor *) malloc(sizeof(Vetor));
        (*vetor)->length = 0;
        (*vetor)->itens = NULL;
    }

    for (int i = 0; i < valores->length; i++) 
    {
        if (!contido(valores->itens[i], *vetor)) 
        {
            appendInt(vetor, valores->itens[i]);
        }
    }
}

int len(int *vetor) {
    int length = 0;

    if (vetor == NULL) {
        return 0;
    }
    else if (vetor[0] <= -1) {
        return 0;
    }

    for (int i = 0; vetor[i] > -1 && vetor[i] != NULL && vetor[i] < 10000; i++) {
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

bool passouPelaPilha(int idVertice, Vetor *idsPassaramPelaPilha) 
{
    if (idsPassaramPelaPilha == NULL) {
        return false;
    }

    for (int i = 0; i < idsPassaramPelaPilha->length; i++) {
        if (idsPassaramPelaPilha->itens[i] == idVertice) {
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
    *vetor = iniciaVetor(vEmergente);
}

void adicionaFilhosNaPilha(int **pilha, Vetor *filhos, Vetor *idsPassaramPelaPilha) 
{
    if (filhos->length == 0) {
        return;
    }

    for (int i = 0; i < filhos->length; i++) {
        if (passouPelaPilha(filhos->itens[i], idsPassaramPelaPilha)) {
            continue;
        } else {
            pilhaPush(pilha, filhos->itens[i]);
        }
    }
}

int *list(int valor) {
    int *vetorFinal = (int *) malloc(sizeof(int) * 2);
    vetorFinal[0] = valor;
    vetorFinal[1] = -1;
    return vetorFinal; 
}

#endif
