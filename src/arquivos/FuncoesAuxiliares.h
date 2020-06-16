#include "Aluno.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

struct listaAlunos
{
    Aluno* cabeca;
};

//Funções Principais
void cadastrarAluno(listaAlunos*);
void buscarAluno(listaAlunos*, char[]);
void lerArquivo(listaAlunos*, char[]);

//Funções Auxiliares
listaAlunos* cria_nova_lista();
Aluno* pedirInformacoes(listaAlunos*);
void conferirPo(Aluno*);
float mediaFinal(Aluno*);
bool resultadoFinal(Aluno*);
void imprimeAluno(Aluno*);

//Funções para Teste
void imprime_Lista(listaAlunos*);