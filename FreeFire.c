#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Função para inserir um item no inventário
void inserirItem(Item* inventario, int* totalItens) {
    if (*totalItens >= 10) {
        printf("Inventário cheio! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("Digite o nome do item: ");
    scanf("%s", inventario[*totalItens].nome);

    printf("Digite o tipo do item (ex: arma, municao, cura): ");
    scanf("%s", inventario[*totalItens].tipo);

    printf("Digite a quantidade do item: ");
    scanf("%d", &inventario[*totalItens].quantidade);

    (*totalItens)++;
    printf("Item adicionado com sucesso!\n");
}

// Função para remover um item do inventário
void removerItem(Item* inventario, int* totalItens) {
    if (*totalItens == 0) {
        printf("O inventário está vazio! Não há itens para remover.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a ser removido: ");
    scanf("%s", nome);

    for (int i = 0; i < *totalItens; i++) {
        if (strcmp(inventario[i].nome, nome) == 0) {
            for (int j = i; j < *totalItens - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            (*totalItens)--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }

    printf("Item não encontrado no inventário.\n");
}

// Função para listar todos os itens do inventário
void listarItens(Item* inventario, int totalItens) {
    if (totalItens == 0) {
        printf("O inventário está vazio!\n");
        return;
    }

    printf("Itens no inventário:\n");
    for (int i = 0; i < totalItens; i++) {
        printf("Item %d:\n", i + 1);
        printf("Nome: %s\n", inventario[i].nome);
        printf("Tipo: %s\n", inventario[i].tipo);
        printf("Quantidade: %d\n", inventario[i].quantidade);
        printf("\n");
    }
}

// Função para buscar um item no inventário
void buscarItem(Item* inventario, int totalItens) {
    if (totalItens == 0) {
        printf("O inventário está vazio!\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a ser buscado: ");
    scanf("%s", nome);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(inventario[i].nome, nome) == 0) {
            printf("Item encontrado:\n");
            printf("Nome: %s\n", inventario[i].nome);
            printf("Tipo: %s\n", inventario[i].tipo);
            printf("Quantidade: %d\n", inventario[i].quantidade);
            return;
        }
    }

    printf("Item não encontrado no inventário.\n");
}

// Função principal
int main() {
    Item inventario[10]; // Vetor para armazenar até 10 itens
    int totalItens = 0;  // Contador de itens no inventário
    int opcao;

    do {
        printf("\nSistema de Inventário\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(inventario, &totalItens);
                break;
            case 2:
                removerItem(inventario, &totalItens);
                break;
            case 3:
                listarItens(inventario, totalItens);
                break;
            case 4:
                buscarItem(inventario, totalItens);
                break;
            case 5:
                printf("Saindo do sistema de inventário...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}