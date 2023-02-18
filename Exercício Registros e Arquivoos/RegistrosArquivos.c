#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximoAlunos 40
#define tamanhoNome 40

// Struct
typedef struct
{
    char nome[tamanhoNome];
    int matricula;
    float notasProvas[2];
    float notaMedia;
    int faltas;
    char resultado[12];

} aluno;

void clear()
{
    char ch;
    while (ch = getchar() != '\n' && ch != EOF)
        ;
}

// Menu Principal
int menuPrincipal()
{
    int op = -1;

    printf("------------------- 📋 Welcome to the Student Registration System 📋 -------------------\n");
    printf("\t 1 - [Inserir alunos];\n");
    printf("\t 2 - [Listar alunos];\n");
    printf("\t 3 - [Salvar dados];\n");
    printf("\t 4 - [Carrega dados];\n");
    printf("\t 5 - [Sair];\n\n");
    printf("Digite um número na opção desejada e tecle enter para selecionar: ");
    scanf(" %d", &op);

    return op;
}

// Calcular Resultado
const char *resultadoAluno(float notaMedia, int faltas)
{
    if (notaMedia >= 6 && faltas <= 20)
        return "APROVADO ";
    else
        return "REPROVADO ";
}

// Inserir Alunos
int inserirAluno(aluno a[], int n, int max)
{
    int op = 1;
    while (op == 1)
    {
        if (n >= max)
        {
            printf("Já possui todos os %d alunos cadastrados.\n", max);
            op = 0;
        }
        else if (n < max)
        {
            printf("Cadastrando %d/%d alunos.\n", n + 1, max);

            clear();
            printf("Nome: ");
            fgets(a[n].nome, sizeof(a[n].nome), stdin);
            a[n].nome[strcspn(a[n].nome, "\n")] = 0;
            printf("Matricula: ");
            scanf(" %d", &a[n].matricula);
            printf("Nota 1: ");
            scanf(" %f", &a[n].notasProvas[0]);
            printf("Nota 2: ");
            scanf(" %f", &a[n].notasProvas[1]);
            printf("Faltas: ");
            scanf(" %d", &a[n].faltas);

            // Calcular Média e Resultado do Aluno
            a[n].notaMedia = (a[n].notasProvas[0] + a[n].notasProvas[1]) / 2.0;
            strcpy(a[n].resultado, resultadoAluno(a[n].notaMedia, a[n].faltas));
            n++;

            printf("\nDigite 1 para inserir mais um aluno(s)\n");
            printf("ou digite 0 para retornar ao Menu Principal: ");
            scanf(" %d", &op);
        }
    }

    return n;
}

// Listar Alunos Cadastrados
void listarAlunos(aluno a[], int n)
{
    if (n == 0)
    {
        printf("No momento existe %d alunos cadastrados.\n", n);
    }
    else
    {
        int i;
        for (i = 0; i < n; i++)
        {
            printf("Nome: %s\n", a[i].nome);
            printf("Matricula: %d\n", a[i].matricula);
            printf("Nota 1: %.2f\n", a[i].notasProvas[0]);
            printf("Nota 2: %.2f\n", a[i].notasProvas[1]);
            printf("Nota media: %.2f\n", a[i].notaMedia);
            printf("Faltas: %d\n", a[i].faltas);
            printf("Resultado: %s\n", a[i].resultado);

            if (i < n - 1)
                printf("\n");
        }
    }
}

// Gravação de Arquivos
const char *salvarDados(aluno a[], int n)
{
    int i = 0;
    FILE *f;

    f = fopen("alunos.txt", "w");
    if (f == NULL)
    {
        return "❌ ERRO ao abrir o arquivo. ";
    }

    for (i = 0; i < n; i++)
    {
        fprintf(f, "%s\t%d\t%.2f\t%.2f\t%.2f\t%d\t%s\n", a[i].nome, a[i].matricula, a[i].notasProvas[0], a[i].notasProvas[1], a[i].notaMedia, a[i].faltas, a[i].resultado);
    }

    fclose(f);
    return "Dados salvos com SUCESSO ✅! ";
}

// Ler os arquivos e passar para Struct
int carregarDados(aluno a[])
{
    int i = 0;
    char readLine[200];
    char *item;
    FILE *f;

    f = fopen("alunos.txt", "r");
    if (f == NULL)
    {
        return -1;
    }

    while (fgets(readLine, 200, f))
    {
        item = strtok(readLine, "\t");
        strcpy(a[i].nome, item);

        item = strtok(NULL, "\t");
        a[i].matricula = atoi(item);

        item = strtok(NULL, "\t");
        a[i].notasProvas[0] = strtof(item, NULL);

        item = strtok(NULL, "\t");
        a[i].notasProvas[1] = strtof(item, NULL);

        item = strtok(NULL, "\t");
        a[i].notaMedia = strtof(item, NULL);

        item = strtok(NULL, "\t");
        a[i].faltas = atoi(item);

        item = strtok(NULL, "\n");
        strcpy(a[i].resultado, item);

        i++;
    }

    fclose(f);

    return i;
}

int main()
{
    int op = 0, alunosCadastrados = 0, err = 0;
    aluno alunos[maximoAlunos];

    alunosCadastrados = carregarDados(alunos);

    if (alunosCadastrados == -1)
        alunosCadastrados = 0;

    while (op != 5)
    {
        op = menuPrincipal();

        switch (op)
        {
        case 1:
            printf("-------------------- Inserir Aluno ---------------------\n");
            alunosCadastrados = inserirAluno(alunos, alunosCadastrados, maximoAlunos);
            break;
        case 2:
            printf("-------------------- Listar Alunos ---------------------\n");
            listarAlunos(alunos, alunosCadastrados);
            break;
        case 3:
            printf("-------------------- Salvar Dados ----------------------\n");
            printf("%s\n", salvarDados(alunos, alunosCadastrados));
            break;
        case 4:
            printf("-------------------- Carregar Dados --------------------\n");
            err = carregarDados(alunos);

            if (err == -1)
                printf("❌ ERRO ao abrir o arquivo.\n");
            else
            {
                alunosCadastrados = err;
                printf("Dados carregados com sucesso ✅\n");
            }

            break;
        case 5:
            printf("------------------------Saindo-----------------------\n");
            break;

        default:
            printf("******************** Opcao invalida ********************\n");
            break;
        }
    }

    return 0;
}