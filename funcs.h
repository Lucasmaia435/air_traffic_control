#include "definitions.h"

Heap *criarHeap(int capacidade);
void trocar(Aeronave *a, Aeronave *b);
int calcularPrioridade(const Aeronave *aeronave);
void heapifyCima(Heap *heap, int index);
void heapifyBaixo(Heap *heap, int index);
void inserirAeronave(Heap *heap, Aeronave aeronave);
Aeronave consultarMaiorPrioridade(Heap *heap);
void removerMaiorPrioridade(Heap *heap);
void atualizarPrioridade(Heap *heap, int index);
void exibirHeap(Heap *heap);
void carregarAeronaves(Heap *heap, const char *arquivo);