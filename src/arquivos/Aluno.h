#define MAX 100

// Define a estrututa de Aluno
struct Aluno
{
    Aluno* ant;
    char nome[MAX+1];
    int ra;
    float p1;
    float p2;
    float t;
    float po = 0;
    Aluno* prox;
};