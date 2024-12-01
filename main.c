#include "definitions.h"
#include "funcs.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    // Configurar o locale para UTF-8
    setlocale(LC_ALL, "pt_BR.UTF-8");

    Heap *heap = criarHeap(100);

    carregarAeronaves(heap, "voos.csv");

    int command = 0;

    do
    {
        printf("\n\n+==============================================+\n");
        printf("|| 1 - Inserir aeronave                       ||\n");
        printf("|| 2 - Remover aeronave                       ||\n");
        printf("|| 3 - Exibir aeronaves                       ||\n");
        printf("|| 4 - Exibir aeronave com maior prioridade   ||\n");
        printf("|| 5 - Remover aeronave com maior prioridade  ||\n");
        printf("|| 6 - Atualizar prioridade                   ||\n");
        printf("|| 7 - Sair                                   ||\n");
        printf("+==============================================+\n\n");
        printf("Digite o comando: ");

        scanf("%d", &command);

        switch (command)
        {
        case 1:
            printf("Digite o ID da aeronave: ");
            char id[6];
            scanf(" %6s", id);
            printf("Digite o combustível da aeronave: ");
            int combustivel;
            scanf("%d", &combustivel);
            printf("Digite o horário da aeronave: ");
            int horario;
            scanf("%d", &horario);
            printf("Digite o tipo da operação: ");
            int tipo;
            scanf("%d", &tipo);
            printf("Digite a emergência da aeronave: ");
            int emergencia;
            scanf("%d", &emergencia);
            Aeronave nova;
            strcpy(nova.id, id);
            nova.combustivel = combustivel;
            nova.horario = horario;
            nova.tipo = tipo;
            nova.emergencia = emergencia;
            inserirAeronave(heap, nova);
            printf("Aeronave inserida com sucesso.\n");
            break;
        case 2:
            removerMaiorPrioridade(heap);
            break;
        case 3:
            exibirHeap(heap);
            break;
        case 4:
            printf("Aeronave com maior prioridade:\n");
            Aeronave maior = consultarMaiorPrioridade(heap);
            printf("ID: %s, Prioridade: %d\n", maior.id, maior.prioridade);
            break;
        case 5:
            removerMaiorPrioridade(heap);
            break;
        case 6:
            printf("Digite o ID da aeronave: ");
            char idAtualizar[6];
            scanf(" %6s", idAtualizar);
            printf("Digite o novo combustível da aeronave: ");
            int novoCombustivel;
            scanf("%d", &novoCombustivel);
            printf("Digite o novo horário da aeronave: ");
            int novoHorario;
            scanf("%d", &novoHorario);
            printf("Digite o novo tipo da operação: ");
            int novoTipo;
            scanf("%d", &novoTipo);
            printf("Digite a nova emergência da aeronave: ");
            int novaEmergencia;
            scanf("%d", &novaEmergencia);
            atualizarPrioridade(heap, idAtualizar, novoCombustivel, novoHorario, novoTipo, novaEmergencia);
            break;
        case 7:
            free(heap->dados);
            free(heap);
            break;
        default:
            printf("Opção inválida\n");
        }
    } while (command != 7);

    return 0;
}
