#include <stdlib.h>
#include <stdio.h>
#define max 20

typedef struct info
{
    char nome[61];
    int idade;
    float peso;
    float altura;
}Info;

void insere(Info dados[max])
{
    int i;

    for(i=0;i<max;i++)
    {
        printf("=====================");
        printf("\nNOME DO ALUNO[%d]: ",(i+1));
        fflush(stdin);
        gets(dados[i].nome);
        printf("\nIDADE[%d]: ",(i+1));
        scanf("%d",&dados[i].idade);
        printf("\nPESO[%d]: ",(i+1));
        scanf("%f",&dados[i].peso);
        printf("\nALTURA[%d]: ",(i+1));
        scanf("%f",&dados[i].altura);
    }
}

int MaiorAltura(Info dados[max])
{
    int i;
    int j;
    float aux=0;

    for(i=0;i<max;i++)
    {
        if(dados[i].altura>aux)
        {
            aux=dados[i].altura;
            j=i;
        }
    }
    return j;
}

float imc(Info dados[max],int N)
{
    float IMC;

    IMC=dados[N].peso/(dados[N].altura*dados[N].altura);

    return IMC;
}

int newer(Info dados[max])
{
    int i;
    int j;
    float aux=999;

    for(i=0;i<max;i++)
    {
        if (dados[i].idade<aux)
        {
            aux=dados[i].idade;
            j=i;
        }
    }
    return j;
}
int older(Info dados[max])
{
    int i;
    int j;
    float aux=0;

    for(i=0;i<max;i++)
    {
        if (dados[i].idade>aux)
        {
            aux=dados[i].idade;
            j=i;
        }
    }
    return j;
}

float IMCMedio(Info dados[max])
{
    float total=0;
    int i;

    for(i=0;i<max;i++)
    {
        total=imc(dados,i)+total;
    }
    return total=total/max;
}

int IMCMaior(Info dados[max])
{
    int i;
    int j;
    float aux=0;

    for(i=0;i<max;i++)
    {
        if (imc(dados,i)>aux)
        {
            aux=imc(dados,i);
            j=i;
        }
    }
    return j;
}

int IMCMenor(Info dados[max])
{
    int i;
    int j;
    float aux=999;

    for(i=0;i<max;i++)
    {
        if (imc(dados,i)<aux)
        {
            aux=imc(dados,i);
            j=i;
        }
    }
    return j;
}

int main()
{
    float imc_medio;
    Info alunos[max];
    int velho;
    int novo;
    int maiorIMC;
    int menorIMC;
    int mais_alto;

    insere(alunos);

    mais_alto=MaiorAltura(alunos);
    printf("\nO aluno mais alto e: %s ",alunos[mais_alto].nome);

    maiorIMC=IMCMaior(alunos);
    printf("\nO maior IMC pertence a: %s ",alunos[maiorIMC].nome);
    menorIMC=IMCMenor(alunos);
    printf("\nO menor IMC pertence a: %s ",alunos[menorIMC].nome);

    imc_medio = IMCMedio(alunos);
    printf("\n->O IMC Medio e: %f",imc_medio);

    novo=newer(alunos);
    velho=older(alunos);
    printf("\n->O aluno mais velho e: %s ,com %d anos",alunos[velho].nome,alunos[velho].idade);
    printf("\n->O aluno mais novo e: %s ,com %d anos",alunos[novo].nome,alunos[novo].idade);

    return 0;
}
