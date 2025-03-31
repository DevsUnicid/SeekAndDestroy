#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib/structVetor.h"
#include "lib/util.h"
#include "lib/manipulaMatriz.h"
#include "lib/menu.h"

#define TAMANHO_MAX_MATRIZ 25

int main() {
    int grafoMatriz[TAMANHO_MAX_MATRIZ][TAMANHO_MAX_MATRIZ] = {0}, *filhos, tamanhoMatriz;
    int vEmergente, vIncidente;
    int vertice, aux;
    char pse;

    int escolhaUsuario = NULL;

    printf("\n\tEm primeiro lugar, digite a quantidade de \nvértices (de 1 a 25) que deseja inserir: ");
    scanf(" %d", &tamanhoMatriz);

    if (tamanhoMatriz < 1 || tamanhoMatriz > 25) {
        printf("Você NÃO prestou atenção nas regras e o programa será desligado\n\n");
    }

    menuInicial(true, true);
    printf("\n::: ");

    scanf(" %d", &escolhaUsuario);
    system("@cls||clear");

    while(true) {
        if (escolhaUsuario == NULL) {
            menuInicial(false, false);
            printf("\n::: ");

            scanf(" %d", &escolhaUsuario);
        }

        switch (escolhaUsuario)
        {
            case 0:
                printf("\n\n\n\t\tObrigado por usar o Buscador.\n\n\n\n\n\n\n");
                exit(0);
                break;

            case 1:
                incluirVertice(grafoMatriz);
                break;

            case 2:
                printf("\nDigite o vértice de origem: ");
                scanf(" %d", &vEmergente);

                printf("\nDigite o vértice de destino: ");
                scanf(" %d", &vIncidente);
                buscaCaminho(grafoMatriz, tamanhoMatriz, vEmergente, vIncidente);
                break;

            case 3:
                printf("Pressione ENTER para sair da visualização\n");
                normalizaMatriz(grafoMatriz, tamanhoMatriz);
                imprimeMatrizDeAdjascencias(grafoMatriz, tamanhoMatriz);
                scanf("%c", &pse);
                getchar();

                break;
            
            default:
                printf("Deu algum problema");
                break;
        }

        escolhaUsuario = NULL;
    }
    
    // // Inicializa a matriz
    // // Vétice 1
    // grafoMatriz[0][1] = 1;
    // grafoMatriz[0][2] = 1;
    // grafoMatriz[0][3] = 1;

    // // Vétice 2
    // grafoMatriz[1][0] = 1;
    // grafoMatriz[1][2] = 1;
    
    // // Vétice 3
    // grafoMatriz[2][0] = 1;
    // grafoMatriz[2][1] = 1;

    // // Vétice 4
    // grafoMatriz[3][0] = 1;
    // grafoMatriz[3][4] = 1;

    // // Vétice 5
    // grafoMatriz[4][3] = 1;

    

    // pilhaInicializar(&pilha);

    // Svertice vertice1 = {1, "Vertice 1", 1};
    // pilhaPush(&pilha, &vertice1);

    // Svertice vertice2 = {2, "Vertice 2", 1};
    // pilhaPush(&pilha, &vertice2);

    // Svertice vertice3 = {3, "Vertice 3", 1};
    // pilhaPush(&pilha, &vertice3);

    // Svertice vertice4 = {4, "Vertice 4", 1};
    // pilhaPush(&pilha, &vertice4);

    // Svertice vertice5 = {5, "Vertice 5", 1};
    // pilhaPush(&pilha, &vertice5);

    // filhos = buscaFilhos(&vertice1, grafoMatriz);

}