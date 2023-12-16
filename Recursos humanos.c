#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define armazenamentoContaTam 100

struct dados_funcionario
{
    char nome[300];
    int anoNascimento;
    float salario;
    int matricula;
};

void admissao(struct dados_funcionario *dados, int *totalFuncionarios)
{
    system("cls || clear");
    printf("======= ----------------------- =========\n");
    printf("========= ADMISSÃO FUNCIONÁRIO  =========\n");

    printf("DIGITE O NOME:\n");
    gets(dados[*totalFuncionarios].nome);

    printf("DIGITE ANO DE NASCIMENTO:\n");
    scanf("%d", &dados[*totalFuncionarios].anoNascimento);
    fflush(stdin);

    printf("DIGITE O SALÁRIO:\n");
    scanf("%f", &dados[*totalFuncionarios].salario);
    fflush(stdin);

    printf("DIGITE NÚMERO DE MATRÍCULA:\n");
    scanf("%d", &dados[*totalFuncionarios].matricula);
    fflush(stdin);

    (*totalFuncionarios)++;

    printf("FUNCIONÁRIO ADMITIDO COM SUCESSO!\n");
}

void demissao(struct dados_funcionario *dados, int *totalFuncionarios)
{
    system("cls || clear");

    printf("======= ----------------------- =========\n");
    printf("========= DEMISSÃO FUNCIONÁRIO  =========\n");

    int matriculaDemissao;
    int i;

    printf("DIGITE A MATRÍCULA DO FUNCIONÁRIO:\n");
    scanf("%d", &matriculaDemissao);

    for (i = 0; i < totalFuncionarios; i++)
    {
        if (dados[i].matricula == matriculaDemissao)
        {

            totalFuncionarios--;
            printf("FUNCIONÁRIO DEMITIDO!\n");
        }
        else
        {
            printf("FUNCIONÁRIO NÃO ENCONTRADO!\n");
        }
    }

    (*totalFuncionarios);
}

void consultarFuncionario(struct dados_funcionario *dados, int *totalFuncionarios)
{
    system("cls || clear");
    int consultaMatricula;
    int i;
    printf("\n");
    printf("======= ----------------------- =========\n");
    printf("========= CONSULTAR FUNCIONÁRIO =========\n");
    printf("\n");

    printf("DIGITE A MATRÍCULA DO FUNCIONÁRIO:\n");
    scanf("%d", &consultaMatricula);

    for (i = 0; i < totalFuncionarios; i++)
    {
        if (consultaMatricula == dados[i].matricula)
        {
            printf("MATRÍCULA: %d\n", dados[i].matricula);
            printf("NOME: %s\n", dados[i].nome);
            printf("ANO NASCIMENTO: %d\n", dados[i].anoNascimento);
            printf("SALÁRIO: %.1f\n", dados[i].salario);
        }
    }
    printf("======= ----------------------- =========\n");
    printf("\n");
}

void listarFuncionarios(struct dados_funcionario *dados, int *totalFuncionarios)
{

    system("cls || clear");

    int i;
    printf("========= ----------------------- ==========\n");
    printf("========= FUNCIONÁRIOS CADASTRADOS =========\n");

    if (totalFuncionarios == 0)
    {
        printf("NÃO TEM FUNCIONÁRIO CADASTRADOS!\n");
    }

    printf("Total de funcionarios cadastrados: %d\n", totalFuncionarios);

    for (i = 0; i < totalFuncionarios; i++)
    {
        printf("MATRÍCULA: %d\n", dados[i].matricula);
        printf("NOME: %s\n", dados[i].nome);
        printf("ANO NASCIMENTO: %d\n", dados[i].anoNascimento);
        printf("SALÁRIO: %.1f\n", dados[i].salario);
        printf("------------------------------------------\n");
        printf("\n");
    }
}


void consultarAposentadoria(struct dados_funcionario *dados, int *totalFuncionarios)
{

    int anoAtual;
    int tempoTrabalho = 0;
    int i;

    printf("QUANTOS ANOS O FUNCIONÁRIO TEM DE TRABALHO?\n");
    scanf("%d", &tempoTrabalho);

    for (i = 0; i < totalFuncionarios; i++)

    {
        anoAtual=2023-dados[i].anoNascimento;
        if (anoAtual >= 65 || tempoTrabalho >= 35)
        {
            printf(" FUNCIONÁRIO ESTÁ APTO PARA SE APOSENTAR!");
        }
        else
        {
            printf(" FUNCIONÁRIO NÃO ESTÁ  APTO PARA SE APOSENTAR");
        }
    }
}


void consultaSalario(struct dados_funcionario *dados, int *totalFuncionarios)
{
    int consultaMatricula;
    int horaDevendo = 0;
    int i, horasTrabalhadas = 0;
    float valorHora;

    printf("=== ----------------------- ===\n");
    printf("========= CONSULTA SALÁRIO =========\n");

        printf("DIGITE A MATRÍCULA DO FUNCIONÁRIO:\n");
    scanf("%d", &consultaMatricula);

    for (i = 0; i < totalFuncionarios; i++)
    {
        if (consultaMatricula == dados[i].matricula)
        {
            printf("MATRÍCULA: %d\n", dados[i].matricula);
            printf("NOME: %s\n", dados[i].nome);
            printf("ANO NASCIMENTO: %d\n", dados[i].anoNascimento);
            printf("SALÁRIO: %.1f\n", dados[i].salario);

            printf("DIGITE O TOTAL DE HORAS TRABALHADAS NO MÊS:\n");
            scanf("%d", &horasTrabalhadas);
            if (horasTrabalhadas < 220)
            {
                horaDevendo = 220 - horasTrabalhadas;
                valorHora = dados[i].salario / 220;
                dados[i].salario -= horaDevendo * valorHora;
                printf(" O SALÁRIO A RECEBER SERÁ DE %.1f REAIS \n", dados[i].salario);
            }
            else
            {
                printf(" O SALÁRIO A RECEBER SERÁ DE %.1f REAIS \n", dados[i].salario);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    struct dados_funcionario dados[100];
    int totalFuncionarios = 0;
    int opcao;

    do
    {
        printf("\n");
        printf("\n");
        printf("=== ----------------------- ===\n");
        printf("========= SISTEMA RH  =========\n");
        printf("=== ----------------------- ===\n");
        printf("1 - Admissão\n");
        printf("2 - Demissão\n");
        printf("3 - Consultar Funcionário\n");
        printf("4 - Verificar aposentadoria\n");
        printf("5 - Verificar salário do mês\n");
        printf("6 - Listar Funcionários\n");
        printf("7 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            admissao(dados, &totalFuncionarios);

            break;
        case 2:
            demissao(dados, &totalFuncionarios);

            break;
        case 3:
            consultarFuncionario(dados, totalFuncionarios);

            break;
        case 4:
            consultarAposentadoria(dados, totalFuncionarios);

            break;
        case 5:
            consultaSalario(dados, totalFuncionarios);

            break;
        case 6:
            listarFuncionarios(dados, totalFuncionarios);

            break;
        case 7:
            system("cls || clear");
            printf("Encerrando o sistema...\n");

            break;

        default:
            break;
        }

    } while (opcao != 7);

    return 0;
}