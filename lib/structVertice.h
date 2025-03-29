#ifndef __STRUCTVERTICE_H
#define __STRUCTVERTICE_H

typedef struct svertice {
    int idVertice;
    char nomeVertice[100];
    int pesoVertice;
    int *conexoes;
} Svertice;

#endif