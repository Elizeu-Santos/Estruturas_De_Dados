#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int chave;
    struct node *prox;
} No;

No *tabela_hash[MAX];

// Inicializa a tabela hash
void inicializar() {
    int i;
    for (i = 0; i < MAX; i++) {
        tabela_hash[i] = NULL;
    }
}

// Função de hash
int hash(int chave) {
    return chave % MAX;
}

// Insere um elemento na tabela hash
void inserir(int chave) {
    int indice = hash(chave);
    No *novo_no = (No *) malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->prox = tabela_hash[indice];
    tabela_hash[indice] = novo_no;
}

// Remove um elemento da tabela hash
void remover_elemento(int chave) {
    int indice = hash(chave);
    No *temp, *prev;
    temp = tabela_hash[indice];
    prev = NULL;
    while (temp != NULL) {
        if (temp->chave == chave) {
            if (prev == NULL) {
                tabela_hash[indice] = temp->prox;
            } else {
                prev->prox = temp->prox;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->prox;
    }
}

// Busca um elemento na tabela hash
int buscar(int chave) {
    int indice = hash(chave);
    No *temp;
    temp = tabela_hash[indice];
    while (temp != NULL) {
        if (temp->chave == chave) {
            return 1;
        }
        temp = temp->prox;
    }
    return 0;
}

// Imprime todos os elementos da tabela hash
void imprimir_tabela() {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("Índice %d: ", i);
        No *temp = tabela_hash[i];
        while (temp != NULL) {
            printf("%d ", temp->chave);
            temp = temp->prox;
        }
        printf("\n");
    }
}

int main() {
    int escolha, chave;
    inicializar();
    while (1) {
        printf("----------------------\n");
        printf("[1] > Inserir elemento\n");
        printf("[2] > Remover elemento\n");
        printf("[3] > Buscar elemento\n");
        printf("[4] > Imprimir tabela\n");
        printf("[5] > Sair\n");
        printf("----------------------\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &chave);
                inserir(chave);
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &chave);
                remover_elemento(chave);
                break;
            case 3:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &chave);
                if (buscar(chave)) {
                    printf("Elemento encontrado\n");
                } else {
                    printf("Elemento não encontrado\n");
                }
                break;
            case 4:
                imprimir_tabela();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }
    return 0;
}
