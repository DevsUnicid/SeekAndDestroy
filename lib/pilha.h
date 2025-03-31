#ifndef __PILHA_H
#define __PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"
#include "structPilha.h"

// Assinatura de funções
Pilha *pilhaInicializar(Pilha *pilha);
bool pilhaEstaVazia(Pilha *pilha);
void pilhaPush(Pilha **pilha, int novoVertice);
int pilhaPop(Pilha *pilha);
// int imprimePilha(int *pilha);

// Funções
Pilha *pilhaInicializar(Pilha *pilha) {
    pilha = (Pilha *) malloc(sizeof(Pilha));
    if (pilha == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        return NULL;
    }
    pilha->length = 0;
    pilha->itens = (int *) malloc(sizeof(int));
    pilha->itens[0] = -1; // Inicializa o primeiro elemento como -1

    return pilha;
}

bool pilhaEstaVazia(Pilha *pilha) {
    return pilha == NULL || pilha->length == 0;
}

void pilhaPush(Pilha **pilha, int novoVertice) {
    
    int qtdVertices = (*pilha)->length;

    *pilha = (Pilha *) realloc(*pilha, sizeof(int) * (qtdVertices + 1));
    (*pilha)->itens[qtdVertices] = novoVertice;
    (*pilha)->length++;
    (*pilha)->itens[qtdVertices + 1] = -1;
}

int pilhaPop(Pilha *pilha) {
    if (pilhaEstaVazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        return -1;
    }
    int verticeExcluir = pilha->itens[pilha->length - 1];

    pilha = (int *) realloc(pilha, pilha->length * sizeof(int) - 1);
    
    return verticeExcluir;
}

// int imprimePilha(Pilha *pilha) {
//     if (pilhaEstaVazia(pilha)) {
//         printf("Pilha vazia.\n");
//         return -1;
//     }

//     for (int i = 0; i < len(pilha); i++) {
//         printf("V%d ", pilha[i]);
//     }
//     printf("\n");
//     return 0;
// }

#endif