#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definindo a estrutura de dados
typedef struct elemento

{
    int dado;
    struct elemento *prox;
} 

* Lista;

int menu();
Lista criaLista();
Lista insereOrdenado(Lista l1, int valor);
Lista retiraLista(Lista l, int e);
Lista buscaLista(Lista l, int e);
void imprimir();
int contaLista(Lista l);

int main()

{
    int op, cont, item, valorInt;
    Lista l1, busca;
    l1 = criaLista();

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("|----------------------- INSERIR ELEMENTO ------------------------|\n");
            printf("Digite um valor inteiro para ser inserido na lista: ");
            scanf(" %d", &valorInt);
            l1 = insereOrdenado(l1, valorInt);
            break;
        case 2:
            printf("|----------------------- RETIRAR ELEMENTO ------------------------|\n");
            if (l1 == NULL)
                printf("Lista VAZIA...\n");
            else
            {
                printf("Digite um valor inteiro para ser retirado da lista: ");
                scanf(" %d", &valorInt);
                busca = buscaLista(l1, valorInt);
                if (busca == NULL)
                    printf("Este valor %d nao esta na lista.\n", valorInt);
                else
                {
                    l1 = retiraLista(l1, valorInt);
                    printf("Este valor %d foi retirado da lista.\n", valorInt);
                }
            }
            break;
        case 3:
            printf("|------------------------ BUSCAR ELEMENTO ------------------------|\n");
            if (l1 == NULL)
                printf("Lista VAZIA...\n");
            else
            {
                printf("Digite um valor inteiro para buscar na lista: ");
                scanf(" %d", &valorInt);
                busca = buscaLista(l1, valorInt);
                if (busca == NULL)
                    printf("Este valor %d nao esta na lista.\n", valorInt);
                else
                    printf("Este valor %d esta na lista.\n", valorInt);
            }
            break;
        case 4:
            printf("|------------------------- EXIBIR LISTA -------------------------|\n");
            if (l1 == NULL)
                printf("Lista VAZIA...\n");
            else
                imprimir(l1);
            break;
        case 5:
            printf("|----------------- NUMEROS DE ELEMENTOS NA LISTA ----------------|\n");
            if (l1 == NULL)
                printf("Lista VAZIA... Nenhum elemento encontrado.\n");
            else
            {
                valorInt = contaLista(l1);
                if (valorInt == 1)
                    printf("Essa lista tem apenas %d elemento.\n", valorInt);
                else
                    printf("Essa lista tem %d elementos.\n", valorInt);
            }
            break;
        case 0:
            printf("|----------------------- SAINDO DO SISTEMA ----------------------|\n");
            break;
        default:
            printf("|------------------------- OPCAO INVALIDA -----------------------|\n");
            break;
        }
    } while (op != 0);

    return 0;
}

// MENU PRINCIPAL
int menu()
{
    int op = -1;

    printf("|----------------------------- MENU LISTA ------------------------|\n\n");
    printf("\t [1] - Inserir elemento;\n");
    printf("\t [2] - Retirar elemento;\n");
    printf("\t [3] - Buscar elemento;\n");
    printf("\t [4] - Imprimir o conteúdo da lista;\n");
    printf("\t [5] - Número de elementos na lista;\n");
    printf("\t [0] - Sair.\n\n");
    printf("|-----------------------------------------------------------------|\n");
    printf("Escolha uma opção desejada e tecle enter: ");
    
    scanf(" %d", &op);

    return op;
}

// CRIAR LISTA
Lista criaLista()

{
    return NULL;
}

// FUNÇÃO PARA INSERIR A LISTA ORDENADA
Lista insereOrdenado(Lista l1, int valor)

{
    Lista l, novo, ant;

    l = l1;
    novo = malloc(sizeof(struct elemento));
    novo -> dado = valor;
    ant = criaLista();

    // VERIFICAÇÃO DA LISTA VAZIA
    if (l != NULL)
    {
        while ((l != NULL) && (l->dado < valor))
        {
            ant = l;
            l = l->prox;
        }

        novo->prox = l;

        if (ant == NULL)
            l1 = novo;
        else
            ant->prox = novo;
    }
    else
    {
        novo -> prox = NULL;
        l1 = novo;
    }

    return l1;
}

// RETIRAR O ELEMENTO DA LISTA
Lista retiraLista(Lista l, int e)
{
    Lista p,
        ant;

    p = l;
    ant = l;

    while ((p != NULL) && (p->dado != e))
    {
        ant = p;
        p = p->prox;
    }
    if (p != NULL)
    {                 
        if (p == ant)
        {
            l = p -> prox;
            free(p);
        }
        else
        {
            ant -> prox = p -> prox;
            free(p);
        }
    }
    return (l);
}

//  BUSCAR O ELEMENTO NA LISTA
Lista buscaLista(Lista l, int e)
{
    Lista p;

    p = l;

    while ((p != NULL) && (p -> dado != e))
    {
        p = p -> prox;
    }
    
    return (p);
}

// IMPRIMIR LISTA
void imprimir(Lista l)
{
    int i = 0;
    Lista p;

    printf("Itens da lista:\n");
    p = l;            
    while (p != NULL) 
    {
        for (i = 0; i < 20 && p != NULL; i++)
        {
            printf("%d", p -> dado);
            p = p->prox;           
  
            if (p != NULL)
                printf(", ");
        }
        printf("\n");
    }
}

// CONTAR NÚMEROS DE NODOS DA LISTA
int contaLista(Lista l)

{
    Lista p;
    int cont = 0;

    p = l;            
    while (p != NULL)
    {
        cont++;
        p = p -> prox;
    }
    
    return cont;
}