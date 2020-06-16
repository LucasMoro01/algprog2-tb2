#include "FuncoesAuxiliares.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void cadastrarAluno(listaAlunos* l)
{
    Aluno *novo, *p, *q; 
    novo = pedirInformacoes(l);
    p = l->cabeca;
	q = l->cabeca->prox;

    while(q != NULL && (strcmp(novo->nome, q->nome) == 1))
    {
        p = q;
        q = q->prox;
    }
    if (q == l->cabeca) // Insere no inicio, pois o primeiro elemento ja é maior
    {
        novo->ant = NULL;
        l->cabeca->ant = novo;
        novo->prox = l->cabeca;
        l->cabeca = novo;
    }else //Insere no meio ou no final
    {
        novo->prox = p->prox;
        novo->ant = p;
        p->prox = novo;
        if(q != NULL)
            q->ant = novo;
    }
}

void buscarAluno(listaAlunos* l, char palavra[])
{
    int teste[strlen(palavra)];
    int aux, cont = 0;
    bool ok;
    Aluno* aluno;
    aluno = l->cabeca->prox;

    while(aluno)
    {
        
        for(int i = 0; i < strlen(aluno->nome) - (strlen(palavra)-1); i++) //Percorre até a ultima posição da string - o tamanho da palavra buscada
        {

            if (aluno->nome[i] == palavra[0])
            {
                for(int k = 0; k < strlen(palavra); k++)
                    teste[k] = 0;

                aux = i;//Armazena onde tem a primeira letra que é igual.
                for(int j = 0; j < strlen(palavra); j++)
                {
                    if (palavra[j] == aluno->nome[aux])
                    {
                        teste[j] = 1;
                        aux++;
                    }
                }
                ok = true;
                for(int m=0; m < strlen(palavra);m++)
                {
                    if (teste[m] == 0)
                        ok = false;
                }
                if (ok)
                {
                    imprimeAluno(aluno);
                    cont++;
                }
            }
        }
        aluno = aluno->prox;
    }
    printf("\n\n| Quantidade alunos encontrados: %d |", cont);
    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n");
}

void lerArquivo(listaAlunos* l, char nomeArquivo[]) 
{
    int cont = 0;
    Aluno *novo, *p, *q;
    FILE *arquivo;

    novo = new Aluno; 
    p = l->cabeca;
    q = l->cabeca->prox;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo != NULL)
    {

        while(!feof(arquivo))
        {

            fscanf(arquivo, "%[^0-9] %d %f %f %f %f%*[^A-Aa-zEOF]", &novo->nome, &novo->ra, &novo->p1, &novo->p2, &novo->t, &novo->po);  
            cont++;

            imprimeAluno(novo);

            while(q != NULL && (strcmp(novo->nome, q->nome) == 1))
            {
                p = q;
                q = q->prox;
            }
            if (q == l->cabeca) // Insere no inicio, pois o primeiro elemento ja é maior
            {
                novo->ant = NULL;
                l->cabeca->ant = novo;
                novo->prox = l->cabeca;
                l->cabeca = novo;
            }else //Insere no meio ou no final
            {
                novo->prox = p->prox;
                novo->ant = p;
                p->prox = novo;
                if(q != NULL)
                    q->ant = novo;
            }

        }
        fclose(arquivo);
        printf("\n\n| Alunos cadastrados: %d\n\n", cont);
        }else
        {
            printf("Arquivo inválido");
        }
}