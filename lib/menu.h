#ifndef __MENU_H
#define __MENU_H

#include <stdio.h>
#include <stdlib.h>

#include "structVertice.h"

#define TAMANHO_MATRIZ 5
#define TAMANHO_PADRAO 80;

void imprimeRepeticao(char padrao, int qtd) {
    for (int cont = 0; cont < qtd; cont++) {
        printf("%c", padrao);
    }
}

void espacamentoVertical(char padrao, int tamanhoPadrao) {
    printf("\n");
    imprimeRepeticao(padrao, (tamanhoPadrao - 56)/2);
    printf("                                                        ");
    imprimeRepeticao(padrao, (tamanhoPadrao - 56)/2);
}

void menuInicial(bool comCabecalho, bool apagaTudo) {
    int tamanhoPadrao = TAMANHO_PADRAO;

    if (apagaTudo) system("@cls||clear");

    imprimeRepeticao('*', tamanhoPadrao);
    printf("\n");
    imprimeRepeticao('*', tamanhoPadrao);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('*', tamanhoPadrao);

    // Cabeçalho
    if (comCabecalho) {    
        printf("\n");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
        printf("    Seja muito bem vindo(a) ao Buscador de caminhos!    ");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    }

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('*', tamanhoPadrao);
    espacamentoVertical('*', tamanhoPadrao);

    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("              O que deseja fazer agora?                 ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("   (Digite o número correspondente à ação que deseja)   ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical('*', tamanhoPadrao);
    espacamentoVertical('*', tamanhoPadrao);

    // Opção 1 - Mostrar Menu
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          1 - Incluir vértice                           ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 2 - Buscar prato
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          2 - Buscar caminho                            ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 3 - Imprime Matriz
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          3 - Imprime matriz de adjascencia              ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 0 - Sair do programa
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("         -1 - Sair do programa                          ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Pula linha no menu (espaçamento vert ical)
    espacamentoVertical('*', tamanhoPadrao);
    espacamentoVertical('*', tamanhoPadrao);

    // Rodapé
    printf("\n");
    imprimeRepeticao('*', tamanhoPadrao);
    printf("\n");
}

void menuArestas() {

}

#endif