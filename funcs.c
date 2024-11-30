#include "definitions.h"
#include <stdio.h>

Heap *criarHeap(int capacidade)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->dados = (Aeronave *)malloc(capacidade * sizeof(Aeronave));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void trocar(Aeronave *a, Aeronave *b)
{
    Aeronave temp = *a;
    *a = *b;
    *b = temp;
}

int calcularPrioridade(const Aeronave *aeronave)
{
    int prioridade = aeronave->combustivel;
    if (aeronave->emergencia)
        prioridade += 1000;
    return prioridade;
}

void heapifyCima(Heap *heap, int index)
{
    int pai = (index - 1) / 2;
    while (index > 0 && heap->dados[index].prioridade > heap->dados[pai].prioridade)
    {
        trocar(&heap->dados[index], &heap->dados[pai]);
        index = pai;
        pai = (index - 1) / 2;
    }
}

void heapifyBaixo(Heap *heap, int index)
{
    int maior = index;
    int esq = 2 * index + 1;
    int dir = 2 * index + 2;

    if (esq < heap->tamanho && heap->dados[esq].prioridade > heap->dados[maior].prioridade)
        maior = esq;

    if (dir < heap->tamanho && heap->dados[dir].prioridade > heap->dados[maior].prioridade)
        maior = dir;

    if (maior != index)
    {
        trocar(&heap->dados[index], &heap->dados[maior]);
        heapifyBaixo(heap, maior);
    }
}

void inserirAeronave(Heap *heap, Aeronave aeronave)
{
    if (heap->tamanho == heap->capacidade)
    {
        printf("Heap cheio, não é possível inserir mais aeronaves.\n");
        return;
    }

    aeronave.prioridade = calcularPrioridade(&aeronave);
    heap->dados[heap->tamanho] = aeronave;
    heapifyCima(heap, heap->tamanho);
    heap->tamanho++;
}

Aeronave consultarMaiorPrioridade(Heap *heap)
{
    if (heap->tamanho == 0)
    {
        printf("Heap vazio.\n");
        exit(1);
    }
    return heap->dados[0];
}

void removerMaiorPrioridade(Heap *heap)
{
    if (heap->tamanho == 0)
    {
        printf("Heap vazio, não é possível remover.\n");
        return;
    }

    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;
    heapifyBaixo(heap, 0);
}

void atualizarPrioridade(Heap *heap, int index)
{
    if (index < 0 || index >= heap->tamanho)
    {
        printf("Índice inválido.\n");
        return;
    }

    heap->dados[index].prioridade = calcularPrioridade(&heap->dados[index]);
    heapifyCima(heap, index);
    heapifyBaixo(heap, index);
}

void exibirHeap(Heap *heap)
{
    for (int i = 0; i < heap->tamanho; i++)
    {
        printf("Identificador: %s, Combustível: %d, Horário: %d, Tipo: %s, Emergência: %s, Prioridade: %d\n",
               heap->dados[i].id, heap->dados[i].combustivel, heap->dados[i].horario,
               heap->dados[i].tipo ? "Pouso" : "Decolagem",
               heap->dados[i].emergencia ? "Sim" : "Não",
               heap->dados[i].prioridade);
    }
}

void carregarAeronaves(Heap *heap, const char *arquivo)
{
    FILE *file = fopen(arquivo, "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        return;
    }

    char linha[128];
    while (fgets(linha, sizeof(linha), file))
    {
        Aeronave aeronave;
        sscanf(linha, "%[^,],%d,%d,%d,%d",
               aeronave.id,
               &aeronave.combustivel,
               &aeronave.horario,
               (int *)&aeronave.tipo,
               (int *)&aeronave.emergencia);
        aeronave.prioridade = calcularPrioridade(&aeronave);
        inserirAeronave(heap, aeronave);
    }

    fclose(file);
}
