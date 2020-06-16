#include "FuncoesAuxiliares.h"

listaAlunos* cria_nova_lista()
{
    listaAlunos* l = new listaAlunos;
    l->cabeca = new Aluno;
    l->cabeca->ant = l->cabeca->prox = NULL;

    return l;
}

void conferirPo(Aluno* a)
{
    if (a->p1 < a->po) {
        a->p1 = a->po;
    }    
    else if (a->p2 < a->po) {
        a->p2 = a->po;
    }   
}

float mediaFinal(Aluno* a) {
    
    conferirPo(a);
    
    float mediaFinal = (0.35 * (a->p1)) + (0.35 * (a->p2)) + (0.3 * (a->t));
    
    return mediaFinal;
}

bool resultadoFinal(Aluno* a)
{
    if (mediaFinal(a) >= 6)
        return true;
    return false;
}

void imprimeAluno(Aluno* aluno)
{
    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
    printf("\n| Nome: %s ", aluno->nome);
    printf("\n| Media final do aluno: %.1f", mediaFinal(aluno));
    if (resultadoFinal(aluno))
        printf("\n| Situacao do aluno: Aprovado");
    else
        printf("\n| Situacao do aluno: Reprovado\n");
}

Aluno* pedirInformacoes(listaAlunos* l)
{
    Aluno *novo;
    novo = new Aluno; 
      
    printf("\n|-------------------------------------|");
    printf("\n| Por gentileza informe:");
    printf("\n|");
    printf("\n| Nome do aluno:");
    gets(novo->nome);
    printf("| RA:");
    scanf("%d", &novo->ra);
    printf("| Nota da P1:");
    scanf("%f", &novo->p1);
    printf("| Nota da P2:");
    scanf("%f", &novo->p2);
    printf("| Nota do T:");
    scanf("%f", &novo->t);
    printf("| Nota da PO:");
    scanf("%f", &novo->po);

    return novo;
}

void imprime_Lista(listaAlunos* l)
{
    if (l->cabeca->prox == NULL)
        printf("Lista vazia!\n");
    else
        for (Aluno* ptr = l->cabeca->prox; ptr != NULL; ptr = ptr->prox)
        {
            printf("\nNome: %s ", ptr->nome);
            printf("\nRA: %d ", ptr->ra);
            printf("\nNota da P1: %.1f ", ptr->p1);
            printf("\nNota da P2: %.1f ", ptr->p2);
            printf("\nNota do T: %.1f ", ptr->t);
            printf("\nNota da PO: %.1f ", ptr->po);
            printf("\nMedia do aluno: %.1f", mediaFinal(ptr));
            if (resultadoFinal)
                printf("\nSituação do aluno: Aprovado");
            else
                printf("\nSituação do aluno: Reprovado");
        }
    printf("\n");
}