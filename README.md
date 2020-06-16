# algprog2-tb2
O trabalho prático consiste na implementação de um sistema para gerenciamento de alunos da disciplina de Algoritmos e Programação II

**Observações:**
  * Arquitetura do projeto:
    * `src/arquivos`: Classes auxiliares
      * `Aluno.h`: Estrutura de classe Aluno
      * `FuncoesAuxiliares.h`: Importações e prototipações
      * `FuncoesAuxiliares.cpp`: Funções auxiliares
      * `FuncoesPrincipais.cpp`: Funções principais
    * `src/app`: Classe principal do programa
      * `Maincpp`: Executa toda a aplicação

**Critérios de avaliação:** Seu trabalho será avaliado de acordo com a correção na implementação das estruturas e funções criadas, funcionamento correto dos algoritmos implementados, formatos de entrada e saída conforme descritos.
Os arquivos de entrada e de saída devem seguir exatamente os formatos especificados, caso isso não ocorra, as funcionalidades envolvidas terão sua pontuação zerada

## Tarefas Executadas
* [X] Criação dos arquivos
* [X] Implementação da função cadastrarAluno
* [X] Implementação da função buscarAluno
* [X] Implementação da função lerArquivo
* [X] Implementação da função gerarArquivoAlunosAprovados
* [X] Implementação da função gerarArquivoAlunosReprovados
* [X] Implementação da função fecharPrograma

<br />

## Descrição do trabalho

Cada aluno da disciplina possui armazenadas as seguintes informações:

* **Nome:** (cujos caracteres não devem incluir acentos e cedilhas);
* **RA:** (inteiro);
* **P1:**Nota da primeira prova obrigatória;
* **P2:**Nota da segunda prova obrigatória;
* **T:**Nota do trabalho prático;
* **PO:**Nota da prova optativa.

Todas as notas devem ser representadas usando números em ponto flutuante. A média final MF é calculada de acordo com a seguinte fórmula: **MF = 0,35 * P1 + 0,35 * P2 + 0,3 * T**

Lembrando que a nota da prova optativa (PO) pode substituir a menor das notas de prova (P1 ou P2), caso seja maior que tal nota. O aluno cuja média final for maior ou igual a 6,0 será considerado aprovado, caso contrário, estará reprovado.

Durante a execução do programa, deve ser utilizada uma lista duplamente encadeada ordenada de alunos (a ordem deve ser a lexicográfica considerando os nomes dos alunos). Sua aplicação deve fornecer um menu com as seguintes opções:

## Descrição das funções

### Cadastrar um novo aluno
Insere um novo aluno na lista contendo os dados fornecidos como entrada pelo usuário. O usuário deve fornecer dados para todos os campos do aluno (se a PO não tiver sido realizada, a nota zero deve ser informada);

### Buscar aluno
Solicita ao usuário uma cadeia de caracteres e lista os nomes completos, a média final (com uma casa decimal) e a situação (aprovado ou reprovado) de todos os alunos cujos nomes casam (total ou parcialmente com a cadeia fornecida). A listagem deve mostrar ao final uma contagem do número de resultados encontrados; 

### Ler arquivo com listagem de alunos:
Solicita ao usuário o nome de um arquivo de texto contendo os dados de alunos. Esse arquivo conterá os dados de, no máximo, um aluno por linha e, em cada linha, todos os dados do aluno deverão ser informados na mesma ordem descrita na descrição da estrutura que define um aluno. Se o aluno não fez PO, o arquivo deve conter a nota zero no local adequado. Ao final do cadastramento, deve-se mostrar na tela uma contagem de quantos alunos foram cadastrados. Veja a Seção 3 para mais informações sobre o formato do arquivo;

### Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética
Escreve um arquivo texto contendo os nomes e as médias finais (com uma casa decimal) dos alunos aprovados na disciplina, um aluno por linha. Os alunos constantes no arquivo resultante devem estar em ordem alfabética de nome. Ao final do arquivo, deve aparecer a contagem de alunos aprovados. O nome do arquivo de saída deve ser aprovados.txt. Veja a Seção 4 para mais informações sobre o formato do arquivo;

### Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética
Escreve um arquivo texto contendo os nomes e as médias finais (com uma casa decimal) dos alunos reprovados na disciplina, um aluno por linha. Os alunos constantes no arquivo resultante devem estar em ordem alfabética de nome. Ao final do arquivo, deve aparecer a contagem de alunos reprovados. O nome do arquivo de saída deve ser reprovados.txt. Veja a Seção 4 para mais informações sobre o formato do arquivo;

### Fechar programa
Encerra a execução do programa.


## Execução
A execução do programa deve se iniciar mostrando o menu de opções. O usuário pode escolher a qualquer momento uma das opções e, baseado na escolha realizada, o sistema deve realizar a atividade pedida.
Os cadastros de novos alunos, tanto individualmente quanto por arquivo, devem fornecer dados para todos os campos do(s) aluno(s) em questão.


## Formato do arquivo de entrada
Os arquivos de entrada para as opções que envolvem leitura de arquivo possuem uma linha para cada aluno a ser cadastrado. Cada linha possui dados para todos os campos do tipo de aluno em questão e é encerrada com um caractere de nova linha. Os campos que devem ser considerados são APENAS os descritos na Seção 1 e na MESMA ordem da descrição.


## Formato do aquivo de saída
Os arquivos de saída para as opções que envolvem escrita em arquivo devem possuir uma linha por aluno. Cada linha possui dados para as informações solicitadas (nome e média final com uma casa decimal). Os campos que devem ser escritos são APENAS os listados na Seção 1 e na MESMA ordem da descrição. Ao final, deve aparecer a linha com a contagem seguindo o formato:
* **Total: cont**
Na qual cont é o número de alunos aprovados ou reprovados, de acordo com a opção escolhida.
Ao final de cada linha, deve ser colocado o caractere de nova linha.
