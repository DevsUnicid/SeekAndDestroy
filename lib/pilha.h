#ifndef __PILHA_H
#define __PILHA_H
/* Código copiado do conteúdo visto em aula.
   A implementação foi copiada, porém, muitos 
   ajustes precisaram ser feitos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structVertice.h"
#include "util.h"

int *pilhaInicializar(int *pilha) {
    pilha = (int *) malloc(sizeof(int));
    if (pilha == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        return NULL;
    }

    return pilha;
}

bool pilhaEstaVazia(int *pilha) {
    return pilha == NULL || *pilha == NULL;
}

void pilhaPush(int **pilha, int novoVertice) {
    int qtdVertices = len(*pilha);

    *pilha = (int *) realloc(*pilha, qtdVertices * sizeof(int) + 1);
    (*pilha)[qtdVertices] = novoVertice;
}

int pilhaPop(int *pilha) {
    if (pilhaEstaVazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        return -1;
    }
    int verticeExcluir = pilha[len(pilha) - 1];

    pilha = (int *) realloc(pilha, len(pilha) * sizeof(int) - 1);
    
    return verticeExcluir;
}

int imprimePilha(int *pilha) {
    if (pilhaEstaVazia(pilha)) {
        printf("Pilha vazia.\n");
        return -1;
    }

    for (int i = 0; i < len(pilha); i++) {
        printf("V%d ", pilha[i]);
    }
    printf("\n");
    return 0;
}

#endif