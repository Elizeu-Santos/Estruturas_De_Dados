#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} * ApElemento;

typedef struct
{
    ApElemento ini;
    ApElemento fim;
} Fila;

// Protótipos de funções
int menu();
Fila criaFila();
int filaVazia(Fila f);
void imprimeFila(Fila f);
Fila insereFila(Fila f, int e);
Fila retiraFila(Fila f, int *e);

int main()
{
    int op, valor;
    Fila f;
    f = criaFila();

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("--------- Inserir um elemento no final da fila ---------\n");
            printf("Digite o valor (int) que deseja empilhar: ");
            scanf(" %d", &valor);
            f = insereFila(f, valor);
            break;
        case 2:
            printf("-------- Retirar um elemento no início da fila ---------\n");
            if (!filaVazia(f))
            {
                f = retiraFila(f, &valor);
                printf("Elemento %d retirado da fila.\n", valor);
            }
            else
                printf("Fila vazia.\n");
            break;
        case 3:
            printf("-------------- Imprimir conteúdo da fila ---------------\n");
            if (!filaVazia(f))
            {
                printf("Itens da fila:\n");
                imprimeFila(f);
            }
            else
                printf("Fila vazia.\n");
            break;
        case 0:
            printf("---------------------- Saindo... -----------------------\n");
            break;
        default:
            printf("******************** Opção invalida ********************\n");
            break;
        }

    } while (op != 0);

    return 0;
}

int menu()
{
    int op = -1;

    printf("------------------------- MENU -------------------------\n");
    printf("\t 1 - Inserir um elemento no final da fila;\n");
    printf("\t 2 - Retirar um elemento no início da fila;\n");
    printf("\t 3 - Imprimir conteúdo da fila;\n");
    printf("\t 0 - Sair.\n\n");
    printf("Digite o número da opção desejada e tecle enter: ");
    scanf(" %d", &op);

    return op;
}

Fila criaFila()
{
    Fila f;
    f.ini = NULL;
    f.fim = NULL;
    return f;
}

int filaVazia(Fila f)
{
    if (f.ini == NULL)
        return TRUE;
    else
        return FALSE;
}

Fila insereFila(Fila f, int e)
{
    ApElemento novo;

    // aloca espaço
    novo = malloc(sizeof(struct elemento));

    // atribuições
    novo->dado = e;
    novo->prox = NULL;
    if (filaVazia(f))
    {
        f.ini = novo;
        f.fim = novo;
    }
    else
    {
        f.fim->prox = novo;
        f.fim = novo;
    }
    return f;
}

Fila retiraFila(Fila f, int *e)
{
    ApElemento ap;

    if (!filaVazia(f))
    {
        // retorna o valor do elemento que está no início da fila
        *e = f.ini->dado;
        // salva o endereço do inicio para a liberação
        ap = f.ini;
        // Faz o inicio apontar para o segundo elemento
        f.ini = f.ini->prox;
        // Libera o espaço ocupado pelo elemento removido
        free(ap);
        // se retirou o único elemento, atualiza o fim
        if (filaVazia(f))
            f.fim = NULL;
    }
    else
    {
        *e = -1;
    }
    return f;
}

void imprimeFila(Fila f)
{
    int i = 0;
    ApElemento ap;

    ap = f.ini;

    while (ap != NULL)
    {
        printf("%d", ap->dado);
        i++;
        ap = ap->prox;
        // se não null -> imprime vírgula
        if (ap != NULL)
        {
            printf(", ");
            // Pula uma linha a cada 10 elementos
            if (i == 20)
            {
                i = 0;
                printf("\n");
            }
        }
    }
    printf("\n");
}