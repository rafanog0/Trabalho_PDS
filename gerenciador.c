#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 1024

// Função para obter o path do sistema do arquivo em execução
char *getPathDoArquivoBibliotecas()
{
    char *path = (char *)malloc(sizeof(char) * MAX); // Aloca espaço para o path do arquivo

    // Pega o path do diretório atual
    if (getcwd(path, MAX) != NULL)
    {
        strcat(path, "/bibliotecas");
        return path;
    }

    perror("Erro ao obter o path do arquivo");
    free(path);
    return NULL;
}

void importa_func(FILE *arquivo, char *biblioteca)
{
    char *path_bibliotecas = getPathDoArquivoBibliotecas();
    FILE *funcoes = fopen(strcat(path_bibliotecas, biblioteca), "r");
    fseek(arquivo, 0, SEEK_END);
    if (funcoes == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    // Escreve no inicio do arquivo #include "strcat(path_bibliotecas, biblioteca)"
    fprintf(arquivo, "#include \"%s\"\n", path_bibliotecas);

    fclose(funcoes);
}

void limpa_terminal()
{
// verifica o sistema e limpa o terminal
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void documentacao()
{
    limpa_terminal();
    printf("Documentação:\n");
    printf("1 - Matemática:\n");
    printf("2 - Biblioteca de Strings:\n");
    printf("3 - Biblioteca de Listas:\n");
    printf("4 - Biblioteca de Árvores:\n");
    printf("5 - Biblioteca de Grafos:\n");
    printf("6 - Bibliotecas de Busca e Ordenação:\n");
    printf("7 - Especifidades do Gerenciador de Funções\n");
    printf("0 - Voltar\n");

    int opcao;
    scanf("%d", &opcao);

    if (opcao == 0)
        return;
    else if (opcao == 1)
    {
        limpa_terminal();
        printf("int ehPrimo(int n) -> verifica se um número é primo\n");
        printf("int fatorial(int n) -> calcula o fatorial de um número\n");
        printf("double calcularMedia(int numeros[], int tamanho) -> calcula a média de um array de números\n");
        printf("int encontrarMaior(int numeros[], int tamanho) -> encontra o maior número em um array\n");
    }
    else if (opcao == 2)
    {
        limpa_terminal();
        printf("void inverterString(char *str) -> inverte uma string\n");
        printf("int tamanhoString(char *str) -> retorna o tamanho de uma string\n");
        printf("int compararStrings(char *str1, char *str2) -> compara duas strings\n");
        printf("int contarCaracteres(char *str, char c) -> conta quantas vezes um caracter aparece em uma string\n");
        printf("int contarPalavras(char *str) -> conta quantas palavras tem em uma string\n");
    }
    else if (opcao == 3)
    {
        limpa_terminal();
        printf("No *criarNo(int dado) -> cria um nó\n");
        printf("void inserirNoInicio(Lista *lista, int dado) -> insere um nó no início da lista\n");
        printf("void inserirNoFim(Lista *lista, int dado) -> insere um nó no fim da lista\n");
        printf("void inserirNaPosicao(Lista *lista, int dado, int posicao) -> insere um nó em uma posição específica da lista\n");
        printf("void removerNoInicio(Lista *lista) -> remove um nó do início da lista\n");
        printf("void removerNoFim(Lista *lista) -> remove um nó do fim da lista\n");
        printf("void removerNaPosicao(Lista *lista, int posicao) -> remove um nó de uma posição específica da lista\n");
        printf("void imprimirLista(Lista *lista) -> imprime a lista\n");
        printf("void destruirLista(Lista *lista) -> destrói a lista\n");
    }
    else if (opcao == 4)
    {
        limpa_terminal();
        printf("Arvore *criarArvore(int dado) -> cria uma árvore\n");
        printf("void inserirArvore(Arvore *arvore, int dado) -> insere um nó na árvore\n");
        printf("void removerArvore(Arvore *arvore, int dado) -> remove um nó da árvore\n");
        printf("void imprimirArvore(Arvore *arvore) -> imprime a árvore\n");
        printf("void destruirArvore(Arvore *arvore) -> destrói a árvore\n");
    }
    else if (opcao == 5)
    {
        limpa_terminal();
        printf("Grafo *criarGrafo(int numeroVertices) -> cria um grafo\n");
        printf("void inserirAresta(Grafo *grafo, int vertice1, int vertice2) -> insere uma aresta no grafo\n");
        printf("void removerAresta(Grafo *grafo, int vertice1, int vertice2) -> remove uma aresta do grafo\n");
        printf("void imprimirGrafo(Grafo *grafo) -> imprime o grafo\n");
        printf("void destruirGrafo(Grafo *grafo) -> destrói o grafo\n");
    }
    else if (opcao == 6)
    {
        limpa_terminal();
        printf("int buscaLinear(int array[], int tamanho, int elemento) -> busca um elemento em um array\n");
        printf("int buscaBinaria(int array[], int tamanho, int elemento) -> busca um elemento em um array\n");
        printf("void ordenacaoSelecao(int array[], int tamanho) -> ordena um array\n");
        printf("void ordenacaoInsercao(int array[], int tamanho) -> ordena um array\n");
    }
    else if (opcao == 7)
    {
        limpa_terminal();
        printf("O gerenciador de funções é um programa que permite que o usuário importe funções de bibliotecas para o seu programa.\n");
        printf("Para isso, basta que o usuário digite o nome da biblioteca que deseja importar e o nome da função que deseja utilizar.\n");
        printf("Caso o seu arquivo já exista, o gerenciador irá adicionar as funções ao final do arquivo\n");
        printf("O gerenciador de funções também permite que o usuário visualize a documentação das funções disponíveis.\n");
        printf("*OBS*: Para evitar 'warnings' no seu código, mova as declarações das funções para o inicio do seu arquivo\n");
    }
    else
    {
        limpa_terminal();
        printf("Opção inválida.\n");
    }
    printf("\n******* Pressione ENTER para continuar *******\n");
    getchar();
    getchar();
    documentacao();
}

void menu(FILE *arquivo)
{
    limpa_terminal();
    {
        printf("Escolha uma das bibliotecas que deve ser importada:\n");
    }
    printf("1 - Biblioteca Matemática\n");
    printf("2 - Biblioteca de Strings\n");
    printf("3 - Biblioteca de Listas\n");
    printf("4 - Biblioteca de Árvores\n");
    printf("5 - Biblioteca de Grafos\n");
    printf("6 - Bibliotecas de Busca e Ordenação\n");
    printf("7 - Documentação\n");
    printf("0 - Sair\n");

    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        importa_func(arquivo, "/mat.c");
        printf("Biblioteca matémtica importada com sucesso.\n");
    }

    else if (opcao == 2)
    {
        importa_func(arquivo, "/string.c");
        printf("Biblioteca de strings importada com sucesso.\n");
    }

    else if (opcao == 3)
    {
        importa_func(arquivo, "/lista.c");
        printf("Biblioteca de listas importada com sucesso.\n");
    }

    else if (opcao == 4)
    {
        importa_func(arquivo, "/arvore.c");
        printf("Biblioteca de árvores importada com sucesso.\n");
    }

    else if (opcao == 5)
    {
        importa_func(arquivo, "/grafos.c");
        printf("Biblioteca de grafos importada com sucesso.\n");
    }

    else if (opcao == 6)
    {
        importa_func(arquivo, "/busca.c");
        printf("Biblioteca de busca e ordenação importada com sucesso.\n");
    }

    else if (opcao == 7)
    {
        documentacao();
    }

    else if (opcao == 0)
        return;

    else
        printf("Opção inválida.\n");

    printf("\n******* Pressione ENTER para continuar *******\n");
    getchar();
    getchar();
    
    menu(arquivo);
}

int main(int argc, char const *argv[])
{
    char nomeArquivo[100];
    printf("Escreva o nome do arquivo que terá as funções importadas:\n");
    scanf("%s", nomeArquivo);
    
    FILE *arquivo = fopen(nomeArquivo, "r+");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    menu(arquivo);
    fclose(arquivo);

    return 0;
}
