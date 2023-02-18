#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Definir os tipos
typedef struct elemento
{
    int dado;
    struct elemento *prox;
} * Pilha;

// Funções
int menu();
Pilha criaPilha();
int pilhaVazia(Pilha p);
void imprimePilha(Pilha p);
Pilha empilha(Pilha p, int e);
Pilha desempilha(Pilha p, int *e);

// Main
int main()
{
    int op, valorInt;
    Pilha p1;
    p1 = criaPilha();

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("----------------- Empilhar um elemento -----------------\n");
            printf("Digite o valor (int) que deseja empilhar: ");
            scanf(" %d", &valorInt);
            p1 = empilha(p1, valorInt);
            break;
        case 2:
            printf("--------------- Desempilhar um elemento ----------------\n");
            printf("Desempilhando elemento...\n");
            p1 = desempilha(p1, &valorInt);
            if (valorInt == -1)
                printf("Pilha vazia!\n");
            else
                printf("O elemento foi desempilhado.\n");
            break;
        case 3:
            printf("--------------- Exibir conteudo da pilha ---------------\n");
            if (pilhaVazia(p1) == TRUE)
                printf("Pilha vazia!\n");
            else
            {
                printf("Itens da pilha:\n");
                imprimePilha(p1);
            }
            break;
        case 0:
            printf("----------------------- Saindo... ----------------------\n");
            break;
        default:
            printf("******************** Opcao invalida ********************\n");
            break;
        }
    } while (op != 0);

    return 0;
}

int menu()
{
    int op = -1;

    // Menu
    printf("-------------- PILHA COM ALOCACAO DINAMICA -------------\n");
    printf("\t 1 - Empilhar um elemento;\n");
    printf("\t 2 - Desempilhar um elemento;\n");
    printf("\t 3 - Exibir conteudo da pilha;\n");
    printf("\t 0 - Sair.\n\n");
    printf("--------------------------------------------------------\n");
    printf("Digite o numero da opcao desejada e tecle enter: ");
    scanf(" %d", &op);

    return op;
}

Pilha criaPilha()
{
    return NULL;
}

int pilhaVazia(Pilha p)
{
    if (p == NULL)
        return TRUE;
    else
        return FALSE;
}

void imprimePilha(Pilha p)
{
    Pilha ap;
    ap = p;

    while (ap != NULL)
    {
        printf("%d", ap->dado);
        ap = ap->prox;
        if (ap != NULL)
            printf(", ");
    }
    printf(".\n");
}

Pilha empilha(Pilha p, int e)
{
    Pilha novo;                             
    novo = malloc(sizeof(struct elemento)); 
    novo->dado = e;                         
    novo->prox = p;                         
    return (novo);                          
}

Pilha desempilha(Pilha p, int *e)
{
    Pilha ap; // Apontador auxiliar

    
    if (!pilhaVazia(p))
    {
        *e = p->dado;
        ap = p;
        p = p->prox;
        
        free(ap);
    }
    else
    {
        // Se a pilha estiver vazia, return -1.
        *e = -1;
    }

    return (p);
}