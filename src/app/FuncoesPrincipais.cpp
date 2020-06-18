#include "FuncoesAuxiliares.h"

void cadastrarAluno(listaAlunos* l)
{
    Aluno *novo, *p, *q;
    novo = new Aluno; 
    p = l->cabeca;
	q = l->cabeca->prox;

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

    while(q != NULL && (strcmp(novo->nome, q->nome) > 0))
    {
        p = q;
        q = q->prox;
    }
    novo->ant = p;
    novo->prox = q;
    p->prox = novo;

    if (q != NULL)
        q->ant = novo;
}

void buscarAluno(listaAlunos* l, char palavra[])
{
    int teste[strlen(palavra)];
    int aux, cont = 0;
    bool ok;

    Aluno* aluno;
    aluno = l->cabeca->prox;

    while(aluno != NULL)
    {
        for(int i = 0; i < strlen(aluno->nome); i++)
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
    printf("\n\n| Quantidade alunos encontrados: %d                 |", cont);
    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n");
}


void lerArquivo(listaAlunos* l, char nomeArquivo[]) 
{
    int cont = 0;
    int c;
    
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo != NULL)
    {
        while(!feof(arquivo))
        {
            Aluno *novo, *p, *q;
            novo = new Aluno; 
            p = l->cabeca;
            q = l->cabeca->prox;

            fscanf(arquivo, "%[^0-9] %d %f %f %f %f%*[^A-Za-zEOF]", novo->nome, &novo->ra, &novo->p1, &novo->p2, &novo->t, &novo->po);  
            cont++;

            while(q != NULL && (strcmp(novo->nome, q->nome) > 0))
            {
                p = q;
                q = q->prox;
            }
            novo->ant = p;
            novo->prox = q;
            p->prox = novo;

            if (q != NULL)
                q->ant = novo;
        }
        printf("\n\n| Total de alunos cadastrados: %d\n\n", cont);
    }else
    {
        printf("Arquivo inválido");
    }
}

void gerarArquivoAlunosAprovados(listaAlunos* l)
{
    FILE *arquivo;
    arquivo = fopen("aprovados.txt", "w");
    float media = 0;
    int cont = 0;
    Aluno* aluno;
    aluno = l->cabeca;

    for (Aluno* aluno = l->cabeca->prox; aluno != NULL; aluno = aluno->prox)
    {
        if (resultadoFinal(aluno)) {
            cont++;
            media = mediaFinal(aluno);
            fprintf(arquivo, "%s %.1f\n", aluno->nome, media);
        }
    }
    fprintf(arquivo, "Total: %d\n", cont);
    fclose(arquivo);
}

void gerarArquivoAlunosReprovados(listaAlunos* l)
{
    FILE *arquivo;
    arquivo = fopen("reprovados.txt", "w");
    float media = 0;
    int cont = 0;
    Aluno* aluno;
    aluno = l->cabeca;

    for (Aluno* aluno = l->cabeca->prox; aluno != NULL; aluno = aluno->prox)
    {
        if (!resultadoFinal(aluno)) {
            cont++;
            media = mediaFinal(aluno);
            fprintf(arquivo, "%s %.1f\n", aluno->nome, media);
        }
    }
    fprintf(arquivo, "Total: %d\n", cont);
    fclose(arquivo);
}