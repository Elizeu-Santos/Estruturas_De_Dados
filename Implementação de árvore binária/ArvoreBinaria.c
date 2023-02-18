#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura "node" que representa um nó de uma árvore binária
struct node
{
    int data; // Valor armazenado no nó
    struct node *left; // Ponteiro para o filho esquerdo
    struct node *right; // Ponteiro para o filho direito
};

// Função para criar um novo nó com o valor especificado
struct node *createNode(int data)
{
    // Alocando memória para o novo nó
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó com o valor especificado na árvore
struct node *insertNode(struct node *root, int data)
{
    // Se a árvore estiver vazia, cria um novo nó e retorna
    if (root == NULL)
    {
        return createNode(data);
    }
    // Se o valor a ser inserido for menor que o valor do nó atual, insere à esquerda
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Função para remover um elemento da árvore
struct node *removeNode(struct node *root, int data)
{
     // Se a árvore estiver vazia, retorna
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = removeNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = removeNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

// Função para buscar um elemento na árvore
int searchNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        return 1;
    }
    if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

// Função para imprimir a árvore em pré-ordem
void printPreOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Função para imprimir a árvore em ordem crescente
void printInOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Função para imprimir a árvore em pós-ordem
void printPostOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}
// Menu principal
int main()
{
    int choice, data;
    struct node *root = NULL;

    while (1)
    {
        printf("\n1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Buscar elemento\n");
        printf("4. Imprimir em pré-ordem\n");
        printf("5. Imprimir em ordem crescente\n");
        printf("6. Imprimir em pós-ordem\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("Digite o elemento a ser removido: ");
            scanf("%d", &data);
            root = removeNode(root, data);
            break;
        case 3:
            printf("Digite o elemento a ser buscado: ");
            scanf("%d", &data);
            if (searchNode(root, data))
            {
                printf("O elemento existe na árvore\n");
            }
            else
            {
                printf("O elemento não existe na árvore\n");
            }
            break;
        case 4:
            printf("Elementos da árvore em pré-ordem: ");
            printPreOrder(root);
            break;
        case 5:
            printf("Elementos da árvore em ordem crescente: ");
            printInOrder(root);
            break;
        case 6:
            printf("Elementos da árvore em pós-ordem: ");
            printPostOrder(root);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }
    return 0;
}