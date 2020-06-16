#include "FuncoesAuxiliares.h"
//#define MAX 100

int main()
{
    listaAlunos* lista = cria_nova_lista();

    int operacao;
    char nome[MAX+1], nomeArquivo[MAX+1];
    do {
        printf("\n|------------------------MENU-----------------------|\n");
        printf("| Escolha a operacao que deseja realizar:           |\n");
        printf("| 1 - Cadastrar novo aluno                          |\n");
        printf("| 2 - Buscar aluno                                  |\n");
        printf("| 3 - Ler arquivo com listagem de alunos            |\n");
        printf("| 4 - Gerar arquivo com dados dos alunos aprovados  |\n");
        printf("| 5 - Gerar arquivo com dados dos alunos reprovados |\n");
        printf("| 6 - Fechar programa                               |\n");
        printf("|---------------------------------------------------|\n");
        scanf("%d", &operacao);
        setbuf(stdin, NULL);

        switch (operacao)
        {
            case 1:
                cadastrarAluno(lista);
                break;
            case 2:
                printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
                printf("\n| Informe o nome do aluno que deseja buscar: ");
                scanf("%s", &nome);
                buscarAluno(lista, nome);
                setbuf(stdin, NULL);
                break;
            case 3:
                printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
                printf("\n| Informe o nome do arquivo: ");
                scanf("%s", nomeArquivo);
                lerArquivo(lista, nomeArquivo);
                setbuf(stdin, NULL);
                break;
            case 4:
                imprime_Lista(lista);
                break;
            default:
                break;
        }
        
    } while (operacao != 6);

    return 0;
}