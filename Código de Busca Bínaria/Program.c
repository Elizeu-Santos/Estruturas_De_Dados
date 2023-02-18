#include <stdio.h>

#define TAM 10

// Função para busca sequencial em um vetor
int busca_sequencial(int vetor[], int chave) {
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] == chave) {
            return i;  // Retorna a posição do elemento se encontrado
        }
    }
    return -1; // Retorna -1 caso o elemento não seja encontrado
}

// Função para busca binária em um vetor ordenado
int busca_binaria(int vetor[], int chave) {
    int esquerda = 0; // Define o limite esquerdo do intervalo de busca
    int direita = TAM - 1; // Define o limite direito do intervalo de busca
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (vetor[meio] == chave) {
            return meio;
        } else if (vetor[meio] < chave) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int main() {
    int numeros[TAM]; // Declara um vetor de inteiros com TAM elementos
    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < TAM; i++) { // Pede para o usuário digitar 10 números inteiros
        scanf("%d", &numeros[i]); // Lê cada um dos números e os armazena no vetor
    }

    int chave;
    printf("Digite o numero a ser buscado:\n");
    scanf("%d", &chave); // Pede para o usuário digitar o número a ser buscado

    // Busca sequencial
    int posicao = busca_sequencial(numeros, chave); // Chama a função de busca sequencial
    if (posicao == -1) {
        printf("Valor nao encontrado.\n");
    } else {
        printf("Posicao do elemento: %d\n", posicao);
    }

    // Busca binaria
    int ordenado[TAM];
    for (int i = 0; i < TAM; i++) {
        ordenado[i] = numeros[i]; // Copia os valores do vetor original para o novo vetor
    }
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = i + 1; j < TAM; j++) {
            if (ordenado[i] > ordenado[j]) {
                int temp = ordenado[i]; // Troca os elementos de posição
                ordenado[i] = ordenado[j];
                ordenado[j] = temp;
            }
        }
    }

    printf("Digite o numero a ser buscado (em um vetor ordenado):\n");
    scanf("%d", &chave);

    posicao = busca_binaria(ordenado, chave); // Chama a função de busca binária
    if (posicao == -1) {
        printf("Valor nao encontrado.\n"); // Imprime "Valor não encontrado" se a função de busca retornar -1
    } else {
        printf("Posicao do elemento: %d\n", posicao); // Imprime a posição do elemento se ele for encontrado
    }

    return 0;
}