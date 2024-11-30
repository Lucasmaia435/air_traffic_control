#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef struct Aeronave
{
    char id[6];
    int combustivel;
    int horario;
    int tipo;
    int emergencia;
    int prioridade;
} Aeronave;

typedef struct Heap
{
    Aeronave *dados;
    int tamanho;
    int capacidade;
} Heap;

#endif // DEFINITIONS_H