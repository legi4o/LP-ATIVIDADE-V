#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct dados_funcionario
{
    char nome[300];
    char situacao[300];
    int anoNascimento;
    float salario;
    int matricula;
    

};


void admissao(struct dados_funcionario *dados, int *totalFuncionarios)
{
    system("cls || clear");
    printf("======= ----------------------- =========\n");
    printf("========= ADMISS�O FUNCION�RIO  =========\n");

    printf("DIGITE O NOME:\n");
    gets(dados[*totalFuncionarios].nome);

    printf("DIGITE ANO DE NASCIMENTO:\n");
    scanf("%d", &dados[*totalFuncionarios].anoNascimento);
    fflush(stdin);

    printf("DIGITE O SAL�RIO:\n");
    scanf("%f", &dados[*totalFuncionarios].salario);
    fflush(stdin);

    printf("DIGITE N�MERO DE MATR�CULA:\n");
    scanf("%d", &dados[*totalFuncionarios].matricula);
    fflush(stdin);

    (*totalFuncionarios)++;

    printf("FUNCION�RIO ADMITIDO COM SUCESSO!\n");
}

void demissao(struct dados_funcionario *dados, int *totalFuncionarios ) {
    system("cls || clear");
    fflush(stdin);

    printf("======= ----------------------- =========\n");
    printf("========= DEMISS�O FUNCION�RIO  =========\n");

    int matriculaDemissao;
    int i;
    

    printf("DIGITE A MATR�CULA DO FUNCION�RIO:\n");
    scanf("%d", &matriculaDemissao);

    for (i = 0; i < *totalFuncionarios; i++) {
        if (dados[i].matricula == matriculaDemissao) {
            *totalFuncionarios --; 
            
            strcpy(dados[i].situacao, " *=== DEMITIDO===* ");
            printf("FUNCION�RIO DEMITIDO!\n");
            break;
        } else {
            printf("FUNCION�RIO N�O LOCALIZADO!\n");
        }
    }
    
(totalFuncionarios);
     
     
}


void consultarFuncionario(struct dados_funcionario *dados, int *totalFuncionarios)
{
    system("cls || clear");
    int consultaMatricula;
    int i;
   
    printf("\n");
    printf("======= ----------------------- =========\n");
    printf("========= CONSULTAR FUNCION�RIO =========\n");
    printf("\n");

    printf("DIGITE A MATR�CULA DO FUNCION�RIO:\n");
    scanf("%d", &consultaMatricula);

    for (i = 0; i < *totalFuncionarios; i++)
    {
        if (consultaMatricula == dados[i].matricula)
        {
            if(strcmp(dados[i].situacao, " *=== DEMITIDO===* ")==0){
            printf("*============ DEMITIDO================*\n");
            }
            printf("MATR�CULA: %d\n", dados[i].matricula);
            printf("NOME: %s\n", dados[i].nome);
            printf("ANO NASCIMENTO: %d\n", dados[i].anoNascimento);
            printf("SAL�RIO: %.1f\n", dados[i].salario);
        }else {   system("cls || clear");
            printf("FUNCION�RIO N�O ENCONTRADO!\n");}
    }
    
    printf("======= ----------------------- =========\n");
    printf("\n");
}

void listarFuncionarios(struct dados_funcionario *dados, int *totalFuncionarios)
{

    system("cls || clear");

    int i, cont2=0;
    
    printf("========= ----------------------- ==========\n");
    printf("========= FUNCION�RIOS CADASTRADOS =========\n");

    if (totalFuncionarios == 0)
    {
        printf("N�O TEM FUNCION�RIO CADASTRADOS!\n");
    }

    printf("Total de funcionarios cadastrados: %d\n", *totalFuncionarios);
    printf("Total de funcionarios DEMITIDOS: %d\n",cont2);
    
   

    for (i = 0; i < *totalFuncionarios; i++)
    {
        if(strcmp(dados[i].situacao, " *=== DEMITIDO===* ")==0){
            cont2++;
            printf("*============ DEMITIDO================*\n");
            }
        printf("MATR�CULA: %d\n", dados[i].matricula);
        printf("NOME: %s\n", dados[i].nome);
        printf("ANO NASCIMENTO: %d\n", dados[i].anoNascimento);
        printf("SAL�RIO: %.1f\n", dados[i].salario);
        printf("------------------------------------------\n");
        printf("\n");
    }
}


void consultarAposentadoria(struct dados_funcionario *dados, int *totalFuncionarios)
{

    int anoAtual;
    int tempoTrabalho = 0;
    int i;

    printf("QUANTOS ANOS O FUNCION�RIO TEM DE TRABALHO?\n");
    scanf("%d", &tempoTrabalho);

    for (i = 0; i < *totalFuncionarios; i++)

    {
        anoAtual=2023-dados[i].anoNascimento;
        if (anoAtual >= 65 || tempoTrabalho >= 35)
        {
            printf(" FUNCION�RIO EST� APTO PARA SE APOSENTAR!");
        }
        else
        {
            printf(" FUNCION�RIO N�O EST�  APTO PARA SE APOSENTAR");
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
    printf("========= CONSULTA SAL�RIO =========\n");

        printf("DIGITE A MATR�CULA DO FUNCION�RIO:\n");
    scanf("%d", &consultaMatricula);

    for (i = 0; i < *totalFuncionarios; i++)
    {
        if (consultaMatricula == dados[i].matricula)
        {
            printf("MATR�CULA: %d\n", dados[i].matricula);
            printf("NOME: %s\n", dados[i].nome);
            printf("ANO NASCIMENTO: %d\n", dados[i].anoNascimento);
            printf("SAL�RIO: %.1f\n", dados[i].salario);

            printf("DIGITE O TOTAL DE HORAS TRABALHADAS NO M�S:\n");
            scanf("%d", &horasTrabalhadas);
            if (horasTrabalhadas < 220)
            {
                horaDevendo = 220 - horasTrabalhadas;
                valorHora = dados[i].salario / 220;
                dados[i].salario += horasTrabalhadas*valorHora;
                printf(" O SAL�RIO A RECEBER SER� DE %.1f REAIS \n", dados[i].salario);
            }
            else
            {
                printf(" O SAL�RIO A RECEBER SER� DE %.1f REAIS \n", dados[i].salario);
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
        printf("1 - Admiss�o\n");
        printf("2 - Demiss�o\n");
        printf("3 - Consultar Funcion�rio\n");
        printf("4 - Verificar aposentadoria\n");
        printf("5 - Verificar sal�rio do m�s\n");
        printf("6 - Listar Funcion�rios\n");
        printf("7 - Sair\n");
        printf("Escolha uma op��o: ");
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
            consultarFuncionario(dados, &totalFuncionarios);

            break;
        case 4:
            consultarAposentadoria(dados, &totalFuncionarios);

            break;
        case 5:
            consultaSalario(dados, &totalFuncionarios);

            break;
        case 6:
            listarFuncionarios(dados, &totalFuncionarios);

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