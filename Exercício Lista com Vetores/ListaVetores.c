#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxItensNaLista 10
#define TamanhoItem 20

typedef char tpLista[MaxItensNaLista][TamanhoItem];

int menu() // MENU DO PROGRAMA
{
    int op = -1;

    printf("|----------------------------- MENU LISTA ------------------------|\n\n");
    printf("\t [1] - Inserir Elemento;\n");
    printf("\t [2] - Retirar Elemento;\n");
    printf("\t [3] - Criar Lista;\n");
    printf("\t [4] - Contar Elementos da Lista;\n");
    printf("\t [5] - Exibir Lista;\n");
    printf("\t [0] - Sair;\n\n");
    printf("|-----------------------------------------------------------------|\n");
    printf("Escolha uma opção desejada e tecle enter: ");

    scanf(" %d", &op);

    return op;
}

void clear() // Limpar entrada do teclado antes do FGETS
{
    char ch;
    while (ch = getchar() != '\n' && ch != EOF)
        ;
}

int inserir(tpLista Lista, int n, int max) // INSERIR ELEMENTO
{
    clear();
    printf("Digite o nome do item para ser inserido: \n");
    fgets(Lista[n], sizeof(Lista[n]), stdin);
    n++;
    return n;
}

int retirarItem(tpLista Lista, int n, int max) // RETIRAR ELEMENTO
{
    int i = 0;
    char item[TamanhoItem];

    if (n > 0)
    {
        clear();
        printf("Digite o nome do item:\n");
        fgets(item, sizeof(item), stdin);

        for (i = 0; i < n; i++)
        {
            if (strcmp(Lista[i], item) == 0)
            {
                for (i; i < n; i++)
                    strcpy(Lista[i], Lista[i + 1]);

                n--;

                for (i = n; i < max; i++)
                    Lista[i][0] = '\0';

                printf("Item removido com SUCESSO! \n");

                break;
            }
            else if (i == n - 1)
                printf("Item não encontrado! \n");
        }
    }
    else
    {
        printf("Lista VAZIA! \n");
        return 0;
    }

    return n;
}

int criarLista(tpLista Lista, int n) // CRIAR LISTA
{
    int i;

    for (i = 0; i < n; i++)
    {
        Lista[i][0] = '\0';
    }

    return 0;
}

int contaLista(tpLista Lista, int n, int max) // CONTAR ELEMENTOS DA LISTA
{
    int i;

    if (n > 0)
    {
        for (i = 0; i < n && strlen(Lista[i]) > 0; i++)
            ;
        return (i);
    }
    else
    {
        return 0;
    }
}

void imprimirLista(tpLista Lista, int n) // EXIBIR CONTEÚDO DA LISTA
{
    int i;

    if (n > 0)
    {
        for (i = 0; i < n && strlen(Lista[i]) > 0; i++)
            printf("%s", Lista[i]);
    }
    else
        printf("Lista VAZIA! \n");
}

int main()
{
    int op = -1, itensNaLista = 0;
    tpLista Listas;

    while (op != 0)
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("|----------------------- INSERIR ELEMENTO ------------------------|\n");
            if (itensNaLista == MaxItensNaLista)
                printf("LISTA CHEIA. REMOVA ALGUNS ITEM PARA ADICIONAR MAIS ELEMENTOS.\n");
            else
                itensNaLista = inserir(Listas, itensNaLista, MaxItensNaLista);

            break;
        case 2:
            printf("|----------------------- RETIRAR ELEMENTO ------------------------|\n");
            itensNaLista = retirarItem(Listas, itensNaLista, MaxItensNaLista);

            break;
        case 3:
            printf("|------------------------- CRIAR LISTA --------------------------|\n");
            itensNaLista = criarLista(Listas, MaxItensNaLista);
            printf("LISTA criada com SUCESSO!\n");

            break;
        case 4:
            printf("|------------------ CONTAR ELEMENTOS DA LISTA -------------------|\n");
            printf("No momento consta %d itens nesta lista.\n", contaLista(Listas, itensNaLista, MaxItensNaLista));

            break;
        case 5:
            printf("|------------------------- EXIBIR LISTA -------------------------|\n");
            imprimirLista(Listas, itensNaLista);

            break;
        case 0:
            printf("|----------------------- SAINDO DO SISTEMA ----------------------|\n");
            break;
        default:
            printf("|------------------------- OPCAO INVALIDA -----------------------|\n");
            break;
        }
    }

    return 0;
}