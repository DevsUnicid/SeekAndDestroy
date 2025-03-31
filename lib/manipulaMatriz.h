#ifndef __MANIPULAMATRIZ_H
#define __MANIPULAMATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"
#include "pilha.h"

#define TAMANHO_MAX_MATRIZ 25

// Assinatura de funções
bool insereConexao(int matriz[][TAMANHO_MAX_MATRIZ], int idPai, int idConexao);
bool incluirVertice(int matriz[][TAMANHO_MAX_MATRIZ]);
int *buscaCaminho(int grafo[][TAMANHO_MAX_MATRIZ], int qtdVertices, int vEmergente, int vIncidente);
Vetor *buscaFilhos(int grafo[][TAMANHO_MAX_MATRIZ], int qtdVertices, int vertice) ;

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
    Vetor *caminhoIds = NULL, *idsPassaramPelaPilha = NULL, *filhosAux;
    Pilha *pilha;
    int aux;
    bool continuaFluxo = true;

    if (vEmergente == vIncidente) 
    {
        printf("Vértices de origem e destino são iguais.\n");
        return NULL;
    }

    pilha = pilhaInicializar(NULL);
    pilhaPush(&pilha, vEmergente);
    idsPassaramPelaPilha = iniciaVetor(vEmergente);
    filhosAux = iniciaVetor(-1);

    while(continuaFluxo) 
    {
        aux = pilhaPop(pilha);

        if (aux == -1) 
        {
            continuaFluxo = false;
            break;
        }

        if (aux == vIncidente) 
        {
            appendInt(&caminhoIds, aux);
            continuaFluxo = false;
            break;
        }
        else 
        {
            appendInt(&caminhoIds, aux);
        }

        filhosAux = buscaFilhos(grafo, qtdVertices, aux);

        if (filhosAux->length == 0) 
        {
            limpaVetor(&filhosAux);
            limpaVetor(&caminhoIds);
            continue;
        }
        else
        {
            adicionaFilhosNaPilha(&pilha, filhosAux, idsPassaramPelaPilha);
            appendListInt(&idsPassaramPelaPilha, filhosAux);
        }
    }

    for (int i = 0; i < caminhoIds->length; i++) 
    {
        printf("%d ", caminhoIds->itens[i]);
    }
    printf("\n");
}

Vetor *buscaFilhos(int grafo[][TAMANHO_MAX_MATRIZ], int qtdVertices, int vertice) 
{
    int qtdFilhos = 0;
    int linha = vertice - 1;

    Vetor **filhos = (Vetor **) malloc(sizeof(Vetor *));
    *filhos = (Vetor *) malloc(sizeof(Vetor));
    (*filhos)->length = 0;
    (*filhos)->itens = NULL;

    for (int j = 0; j < qtdVertices; j++) 
    {
        qtdFilhos = (*filhos)->length;

        if (grafo[linha][j] == 1) 
        {
            if (qtdFilhos == 0)
            {
                (*filhos)->itens = (int *) malloc(sizeof(int));
                (*filhos)->length = 1;
                (*filhos)->itens[qtdFilhos] = j + 1;
            }
            else 
            {
                (*filhos)->itens = (int *) realloc((*filhos)->itens, (qtdFilhos + 1) * sizeof(int));
                (*filhos)->length++;
                (*filhos)->itens[qtdFilhos] = j + 1;
            }

            qtdFilhos++;
        }
    }

    (*filhos)->itens = (int *) realloc((*filhos)->itens, sizeof(int) * (1 + qtdFilhos));
    (*filhos)->itens[qtdFilhos] = -1;

    return *filhos;
}

#endif
