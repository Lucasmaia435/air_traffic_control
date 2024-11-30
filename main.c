#include "definitions.h"
int main()
{
    Heap *heap = criarHeap(100);

    carregarAeronaves(heap, "voos.csv");

    Aeronave nova = {"AB123", 50, 1200, 1, 1, 0};
    inserirAeronave(heap, nova);

    // printf("Aeronave com maior prioridade:\n");
    // Aeronave maior = consultarMaiorPrioridade(heap);
    // printf("ID: %s, Prioridade: %d\n", maior.id, maior.prioridade);

    // removerMaiorPrioridade(heap);

    printf("Heap atualizado:\n");
    exibirHeap(heap);

    free(heap->dados);
    free(heap);

    return 0;
}
