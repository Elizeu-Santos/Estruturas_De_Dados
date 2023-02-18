#include <stdio.h>
#include <math.h>

float soma(float a, float b)
{
    return a + b;
}

float produto(float a, float b)
{
    return a * b;
}

float dif(float a, float b)
{
    return a - b;
}

float div(float a, float b)
{
    return a / b;
}

float calc(float a, float b, char op)
{
    if (op == '+')
        return soma(a, b);
    else if (op == '-')
        return dif(a, b);
    else if (op == '*')
        return produto(a, b);
    else if (op == '/')
        return div(a, b);
}

int main()
{
    float x, y, resultado;
    char op;

    printf("Digite uma operação (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Digite o primeiro número: ");
    scanf(" %f", &x);
    printf("Digite o segundo número: ");
    scanf(" %f", &y);
    printf("\nResultado é: %.4f", calc(x, y, op));

    return 1;
}