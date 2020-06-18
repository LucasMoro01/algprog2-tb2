#include "FuncoesAuxiliares.h"

listaAlunos* cria_nova_lista()
{
    listaAlunos* l = new listaAlunos;
    l->cabeca = new Aluno;
    l->cabeca->ant = l->cabeca->prox = NULL;

    return l;
}

void conferirPo(Aluno* aluno)
{
    if (aluno->p1 < aluno->po) {
        aluno->p1 = aluno->po;
    }    
    else if (aluno->p2 < aluno->po) {
        aluno->p2 = aluno->po;
    }
}

float mediaFinal(Aluno* aluno) {
    
    conferirPo(aluno);
    
    float mediaFinal = (0.35 * (aluno->p1)) + (0.35 * (aluno->p2)) + (0.3 * (aluno->t));
    
    return mediaFinal;
}

bool resultadoFinal(Aluno* aluno)
{
    if (mediaFinal(aluno) >= 6) {
        return true;
    }     
    return false;
}

void imprimeAluno(Aluno* aluno)
{
    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
    printf("\n| Nome: %s ", aluno->nome);
    printf("\n| Media final do aluno: %.1f", mediaFinal(aluno));
    if (resultadoFinal(aluno)) {
        printf("\n| Situacao do aluno: Aprovado\n");
    }else {
        printf("\n| Situacao do aluno: Reprovado\n");
    }
}