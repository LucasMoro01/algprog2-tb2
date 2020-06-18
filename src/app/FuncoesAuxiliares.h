#include "Aluno.h"
#include <stdio.h>
#include <string.h>

struct listaAlunos
{
    Aluno* cabeca;
};

//Funções Principais
void cadastrarAluno(listaAlunos*);
void buscarAluno(listaAlunos*, char[]);
void lerArquivo(listaAlunos*, char[]);
void gerarArquivoAlunosAprovados(listaAlunos*);
void gerarArquivoAlunosReprovados(listaAlunos*);

//Funções Auxiliares
listaAlunos* cria_nova_lista();
void conferirPo(Aluno*);
float mediaFinal(Aluno*);
bool resultadoFinal(Aluno*);
void imprimeAluno(Aluno*);
